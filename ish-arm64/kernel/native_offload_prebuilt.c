/*
 * native_offload_prebuilt.c — prebuilt-gadget offload (see native_offload.h).
 *
 * Third offload granularity. A registered guest function's whole block is
 * replaced, at block-compile time, by a single "prebuilt gadget" that calls a
 * native spec_fn reproducing the function's logic in guest semantics. Unlike
 * symbol-level offload it never crosses the host/guest object boundary — spec_fn
 * only reads/writes cpu_state regs and guest memory (via the TLB), so it works
 * for any function (including ones returning guest PyObjects).
 *
 * spec_fn is generated offline (clang auto-translation of the guest function's
 * disassembly) and compiled statically into iSH; native_offload_prebuilt_init
 * registers the shipped targets. No spec_fn is hardcoded in this core file.
 *
 * ARM64 guest only.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kernel/native_offload.h"
#include "emu/tlb.h"
#include "emu/arch/arm64/cpu.h"

#define PREBUILT_MAX 4096

struct prebuilt_target {
    const char *binary;
    const char *symbol;
    addr_t guest_addr;      /* function entry; block starting here is replaced */
    prebuilt_fn spec_fn;
};

static struct prebuilt_target prebuilt_table[PREBUILT_MAX];
static int prebuilt_count = 0;
static uint64_t prebuilt_hits[PREBUILT_MAX];

int native_offload_add_prebuilt(const char *binary, const char *symbol,
                              addr_t guest_addr, prebuilt_fn spec_fn) {
    if (prebuilt_count >= PREBUILT_MAX) return -1;
    int id = prebuilt_count++;
    prebuilt_table[id] = (struct prebuilt_target){
        .binary = binary, .symbol = symbol,
        .guest_addr = guest_addr, .spec_fn = spec_fn,
    };
    return id;
}

prebuilt_fn native_offload_prebuilt_lookup(addr_t pc) {
    for (int i = 0; i < prebuilt_count; i++) {
        if (prebuilt_table[i].guest_addr == pc) {
            if (prebuilt_hits[i]++ == 0 && getenv("ISH_OFFLOAD_STATS"))
                fprintf(stderr, "[offload:prebuilt] first hit: %s:%s @ %llx\n",
                        prebuilt_table[i].binary ? prebuilt_table[i].binary : "?",
                        prebuilt_table[i].symbol, (unsigned long long)pc);
            return prebuilt_table[i].spec_fn;
        }
    }
    return NULL;
}

bool native_offload_prebuilt_active(void) {
    static bool inited = false;
    if (!inited) { inited = true; native_offload_prebuilt_init(); }
    return prebuilt_count > 0;
}

void native_offload_prebuilt_init(void) {
    /* Register shipped prebuilt-gadget targets here (generated spec_fns declared
     * extern from the offline tool's output). None yet. Test handlers self-
     * register via a constructor in kernel/offload_tests/ (no hook needed). */
}
