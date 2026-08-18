/* PoC prebuilt-gadget spec_fn for guest `_PyToken_TwoChars`.
 * Produced by tools/prebuilt_gadget_gen/translate.py (guest asm -> C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"
#include "kernel/native_offload.h"
static uint64_t g_fa, g_fb;
#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)
#define FLAG_EQ (g_fa == g_fb)
#define FLAG_NE (g_fa != g_fb)
#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)
#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)
#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)
#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)
#define FLAG_HI (g_fa >  g_fb)
#define FLAG_LO (g_fa <  g_fb)
#define FLAG_HS (g_fa >= g_fb)
#define FLAG_LS (g_fa <= g_fb)
#define SP (cpu->sp)
/* PB_BASE set at runtime via the global below (PIE load base + ...). Here the
 * only adrp/adr targets are the in-function jump table + base label, both
 * resolved as PB_BASE + file-offset. */
extern uint64_t g_twochars_pb_base;
#define PB_BASE g_twochars_pb_base
#define PB_LDRB(dst, addr) do { uint8_t _b=0; tlb_read(tlb,(addr),&_b,1); (dst)=_b; } while(0)

uint64_t g_twochars_pb_base;
void spec_twochars_poc_fn(struct cpu_state *cpu, struct tlb *tlb) {
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 33ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(91ULL)));
    if (FLAG_HI) goto L_1087a4;
    switch ((uint32_t)(cpu->regs[0])) {
        case 0: goto L_108820;
        case 4: goto L_108848;
        case 5: goto L_1088cc;
        case 9: goto L_108804;
        case 10: goto L_1087f0;
        case 12: goto L_1087d4;
        case 14: goto L_10889c;
        case 25: goto L_1087ac;
        case 27: goto L_10885c;
        case 28: goto L_1087c0;
        case 29: goto L_108880;
        case 31: goto L_108834;
        case 61: goto L_1088e0;
        case 91: goto L_1088b8;
        default: goto L_1087a4;
    }
L_1087a4:
    cpu->regs[0] = 55ULL;
    return;
L_1087ac:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 53ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1087c0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 27ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1087d4:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108914;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 51ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1087f0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 36ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_108804:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(42ULL)));
    if (FLAG_EQ) goto L_1088f4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 38ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_108820:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 28ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_108834:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 50ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_108848:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 40ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_10885c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_1088fc;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    if (FLAG_EQ) goto L_10891c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(60ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 33ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_108880:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    if (FLAG_EQ) goto L_108904;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(62ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 34ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_10889c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_EQ) goto L_10890c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 39ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1088b8:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 42ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1088cc:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 41ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1088e0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(61ULL)));
    cpu->regs[0] = 55ULL;
    cpu->regs[1] = 43ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1088f4:
    cpu->regs[0] = 35ULL;
    return;
L_1088fc:
    cpu->regs[0] = 29ULL;
    return;
L_108904:
    cpu->regs[0] = 30ULL;
    return;
L_10890c:
    cpu->regs[0] = cpu->regs[1];
    return;
L_108914:
    cpu->regs[0] = 37ULL;
    return;
L_10891c:
    cpu->regs[0] = 28ULL;
    return;
}
