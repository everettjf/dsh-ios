#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/* padding to push inner/outer off the mixbench mix address (0x400314) */
__attribute__((noinline,used)) uint64_t _pad(uint64_t x){ return x+1; }
__attribute__((noinline))
uint64_t inner(uint64_t x) { return x * 0x9e3779b97f4a7c15ULL + 0x1234; }
__attribute__((noinline))
uint64_t outer(uint64_t seed, uint64_t count) {
    uint64_t h = seed;
    for (uint64_t i = 0; i < count; i++) {
        h = inner(h ^ i);
        h = h ^ (h >> 31);
    }
    return h;
}
int main(int argc, char **argv) {
    uint64_t iters = argc>1 ? strtoull(argv[1],0,0) : 1000000;
    uint64_t acc = 0;
    if (argc>2) acc += _pad(iters);  /* keep _pad referenced */
    for (uint64_t i = 0; i < iters; i++) acc ^= outer(i, 16);
    printf("callbench acc=%llx iters=%lluM\n",
           (unsigned long long)acc, (unsigned long long)(iters/1000000));
    return 0;
}
