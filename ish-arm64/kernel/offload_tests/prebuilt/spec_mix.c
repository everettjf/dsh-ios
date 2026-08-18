/* AUTO-GENERATED prebuilt-gadget spec_fn for guest `mix` — DO NOT EDIT.
 * Source: tests/offload/prebuilt/mixbench  addr 0x0000000000400314
 * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"

static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static uint64_t g_fa, g_fb;
#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)
#define FLAG_NE (g_fa != g_fb)
#define FLAG_EQ (g_fa == g_fb)
#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)
#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)
#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)
#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)

void spec_mix(struct cpu_state *cpu, struct tlb *tlb) {
    (void)tlb;
    cpu->regs[2] = 25973ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x7073ULL & 0xffff) << 16);
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 32)) | ((0x6d65ULL & 0xffff) << 32);
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x736fULL & 0xffff) << 48);
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[2];
    if ((cpu->regs[1])==0) goto L_400368;
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = 36045ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0xed55ULL & 0xffff) << 16);
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0xafd7ULL & 0xffff) << 32);
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 48)) | ((0xff51ULL & 0xffff) << 48);
    cpu->regs[3] = 31765ULL;
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 16)) | ((0x7f4aULL & 0xffff) << 16);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 32)) | ((0x79b9ULL & 0xffff) << 32);
    cpu->regs[3] = (cpu->regs[3] & ~(0xffffULL << 48)) | ((0x9e37ULL & 0xffff) << 48);
L_400350:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    cpu->regs[0] = cpu->regs[2] ^ cpu->regs[0];
    cpu->regs[0] = ror64(cpu->regs[0], 51);
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_400350;
L_400368:
    return;
}
