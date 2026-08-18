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

void ft_PyErr_BadInternalCall(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x935e0ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] + 3144ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5980ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x93610ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x90930ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_93638;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 3184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93630ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_93644;
L_93638:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[19] + 24), 0ULL); PB_STR((cpu->regs[19] + 24) + 8, 0ULL);
L_93644:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x93668ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x90930ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_93690;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 3184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93688ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_9369c;
L_93690:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STRB((cpu->regs[19] + 32), 0ULL);
L_9369c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 112));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_936d4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x936d0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_936f4;
L_936d4:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 113));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_936fc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x936f4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_936f4:
    cpu->regs[0] = 0ULL;
    goto L_93704;
L_936fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_93704:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_9370c:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 112));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_93738;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93734ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_93758;
L_93738:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 113));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_93760;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93758ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_93758:
    cpu->regs[0] = 0ULL;
    goto L_93768;
L_93760:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_93768:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    goto L_9370c;
    goto L_9370c;
    goto L_9370c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 112));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_937a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x937a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_937c8;
L_937a8:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 113));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_937d0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x937c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_937c8:
    cpu->regs[0] = 0ULL;
    goto L_937f8;
L_937d0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 120));
    if ((cpu->regs[0])==0) goto L_937f0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = 51624ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    { PB_CALL(13, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_937f0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_937f8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 32ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_93848;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93844ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_93868;
L_93848:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_93870;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93868ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_93868:
    cpu->regs[0] = 0ULL;
    goto L_938a4;
L_93870:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    if ((cpu->regs[0])!=0) goto L_93884;
L_93878:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_938a4;
L_93884:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 51624ULL;
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x9389cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x112290ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_93878;
    PB_LDR(cpu->regs[0], (SP + 0));
L_938a4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_938c4;
    cpu->regs[30] = PB_BASE + 0x938c4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_938c4:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_938d0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[3])!=0) goto L_938e8;
    if ((cpu->regs[4])==0) goto L_93904;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 16));
    if ((cpu->regs[0])==0) goto L_93904;
L_938e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 3224ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93900ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9391c;
L_93904:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 888));
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 3256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x9391cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_9391c:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    goto L_938d0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_93948;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 39376ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    { PB_CALL(20, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_93948:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3264ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93968ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_939bc;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 28));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_939ac;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x939a8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_939d4;
L_939ac:
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0x939b8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_939d4;
L_939bc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[2] = 50568ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    { PB_CALL(24, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_939d4:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x939f0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x230c8cULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x93a14ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1cc470ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x93a38ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1cc470ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    return;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 48));
    if ((cpu->regs[2])==0) goto L_93ae4;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[0], (cpu->regs[0] + 32) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 56));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_93a9c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 48), 0ULL);
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 1912ULL;
    cpu->regs[30] = PB_BASE + 0x93a90ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_93a9c:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[1] + 16) + 8);
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[4] = cpu->regs[0] - 1ULL;
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((cpu->regs[1] + 24), cpu->regs[4]);
    PB_STR((cpu->regs[1] + 48), cpu->regs[2]);
    if (!((cpu->regs[4] >> 63) & 1)) goto L_93ad0;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_93ad0;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[3] = 63ULL;
    PB_STR((cpu->regs[1] + 16), cpu->regs[2]); PB_STR((cpu->regs[1] + 16) + 8, cpu->regs[3]);
L_93ad0:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_93ae8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_93ae4:
    cpu->regs[0] = 0ULL;
L_93ae8:
    return;
    if ((cpu->regs[3])!=0) goto L_93afc;
    if ((cpu->regs[4])==0) goto L_93b28;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 16));
    if ((cpu->regs[0])==0) goto L_93b28;
L_93afc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x93b1cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_93b28:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    return;
}
