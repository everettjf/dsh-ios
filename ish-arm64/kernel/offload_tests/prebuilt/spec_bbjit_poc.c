/* Basic-block-JIT PoC spec_fn — runs the hot asm loop entirely in host
 * registers (C locals), instead of threaded-code executing it one gadget per
 * guest instruction. Measures the ceiling of a basic-block JIT vs iSH's
 * threaded-code interpreter.
 *
 * The target loop (from /tmp/al2, main+0x50 .. main+0x7c):
 *   7b0: add  x10,x10,x11
 *   7b4: eor  x11,x11,x12
 *   7b8: add  x12,x12,x13
 *   7bc: eor  x13,x13,x14
 *   7c0: add  x14,x14,x10
 *   7c4: mul  x10,x10,x11
 *   7c8: sub  x9,x9,#1
 *   7cc: cbnz x9,7b0        ; else fall through to 7d0
 *
 * spec_fn reads x9..x14 from cpu once, runs the loop in host registers, writes
 * back, and redirects the block's "ret" (prebuilt_entry sets PC=LR) to the
 * fall-through guest PC by overwriting LR. Compiled only with
 * -Doffload_test_prebuilt=true.
 */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"

/* Fall-through guest PC (block after the cbnz). Set at registration time via a
 * global so this file needn't hardcode the load base. */
uint64_t g_bbjit_fallthrough_pc;

void spec_bbjit_poc(struct cpu_state *cpu, struct tlb *tlb) {
    (void)tlb;
    uint64_t x9  = cpu->regs[9];
    uint64_t x10 = cpu->regs[10];
    uint64_t x11 = cpu->regs[11];
    uint64_t x12 = cpu->regs[12];
    uint64_t x13 = cpu->regs[13];
    uint64_t x14 = cpu->regs[14];

    /* The whole loop, in host registers — no per-instruction gret, no
     * cpu->regs[] traffic, no decode. This is what a basic-block JIT with
     * register allocation would emit (here the host C compiler does the
     * allocation + keeps everything in host regs). */
    do {
        x10 = x10 + x11;
        x11 = x11 ^ x12;
        x12 = x12 + x13;
        x13 = x13 ^ x14;
        x14 = x14 + x10;
        x10 = x10 * x11;
        x9  = x9 - 1;
    } while (x9 != 0);

    cpu->regs[9]  = x9;
    cpu->regs[10] = x10;
    cpu->regs[11] = x11;
    cpu->regs[12] = x12;
    cpu->regs[13] = x13;
    cpu->regs[14] = x14;

    /* Redirect prebuilt_entry's "PC = LR" resume to the loop's fall-through. */
    cpu->regs[30] = g_bbjit_fallthrough_pc;
}
