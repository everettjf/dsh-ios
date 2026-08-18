/* Guest test program for the prebuilt-gadget offload test.
 * `mix` is a pure-compute leaf function; the offline translator produces
 * kernel/offload_tests/prebuilt/spec_mix.c from its disassembly. Built non-PIE
 * so `mix` sits at a fixed address (0x400314) the test registers.
 * Rebuild:  see run.sh (uses Docker aarch64 gcc -no-pie). */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
__attribute__((noinline))
uint64_t mix(uint64_t seed, uint64_t count) {
    uint64_t h = seed ^ 0x736f6d6570736575ULL;
    for (uint64_t i = 0; i < count; i++) {
        h = h ^ (i + 1);
        h = (h << 13) | (h >> 51);
        h = h * 0xff51afd7ed558ccdULL;
        h = h + 0x9e3779b97f4a7c15ULL;
    }
    return h;
}
int main(int argc, char **argv) {
    uint64_t iters = argc > 1 ? strtoull(argv[1], 0, 0) : 2000000;
    uint64_t acc = 0;
    for (uint64_t i = 0; i < iters; i++) acc ^= mix(i, 64);
    printf("mixbench acc=%llx iters=%lluM\n",
           (unsigned long long)acc, (unsigned long long)(iters / 1000000));
    return 0;
}
