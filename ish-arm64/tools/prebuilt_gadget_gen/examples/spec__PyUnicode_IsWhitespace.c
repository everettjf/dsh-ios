/* AUTO-GENERATED prebuilt-gadget spec_fn for guest `_PyUnicode_IsWhitespace` — DO NOT EDIT.
 * Source: alpine-arm64-fakefs/data/usr/lib/libpython3.12.so.1.0  addr 0x00000000002546c0
 * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"

static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static uint64_t g_fa, g_fb;
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

void spec__PyUnicode_IsWhitespace(struct cpu_state *cpu, struct tlb *tlb) {
    (void)tlb;
    cpu->regs[1] = 8202ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_2546f8;
    cpu->regs[1] = 8191ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_254760;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(133ULL)));
    if (FLAG_EQ) goto L_254760;
    if (FLAG_HI) goto L_25472c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(13ULL)));
    if (FLAG_HI) goto L_254744;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    cpu->regs[0] = (FLAG_HI) ? 1 : 0;
    return;
L_2546f8:
    cpu->regs[1] = 8287ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_254754;
    cpu->regs[1] = -8232ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = 131ULL;
    cpu->regs[3] = 8231ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 48)) | ((0x80ULL & 0xffff) << 48);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[0] = cpu->regs[1] >> (cpu->regs[2] & 63);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 1ULL));
    cpu->regs[0] = (FLAG_HI) ? cpu->regs[0] : 0ULL;
    return;
L_25472c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(160ULL)));
    if (FLAG_EQ) goto L_254760;
    cpu->regs[1] = 5760ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    return;
L_254744:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 28ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    cpu->regs[0] = (FLAG_LS) ? 1 : 0;
    return;
L_254754:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(12288ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    return;
L_254760:
    cpu->regs[0] = 1ULL;
    return;
}
