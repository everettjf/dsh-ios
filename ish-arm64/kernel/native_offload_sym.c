/*
 * native_offload_sym.c — symbol-level native offload (see native_offload.h)
 *
 * Companion to the binary-level offload in native_offload.c. Where that
 * intercepts whole guest commands at execve(), this intercepts individual
 * guest functions at their entry PC in the ARM64 JIT dispatch loop, running
 * a native handler instead of translating the function's gadgets.
 *
 * ARM64 guest only.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kernel/native_offload.h"
#include "emu/tlb.h"
#include "emu/arch/arm64/cpu.h"

#define NSYM_MAX 64

struct nsym_target {
    const char *binary;         /* e.g. "libc.musl-aarch64.so.1" */
    const char *symbol;         /* e.g. "Py_CompileStringExFlags" */
    addr_t addr_hint;           /* fixed addr if known (no-ASLR), else 0 */
    nsym_handler_func handler;
    void *user;
    addr_t addr;                /* resolved entry address, 0 if unresolved */
};

static struct nsym_target nsym_table[NSYM_MAX];
static int nsym_count = 0;
static uint64_t nsym_hits[NSYM_MAX];

/* ---- accessors ---- */

uint64_t nsym_arg(struct nsym_ctx *ctx, int n) {
    if (n < 0 || n > 7) return 0;   /* AAPCS64 integer args: x0..x7 */
    return ctx->cpu->regs[n];
}

void nsym_set_ret(struct nsym_ctx *ctx, uint64_t v) {
    ctx->cpu->regs[0] = v;
}

bool nsym_read(struct nsym_ctx *ctx, addr_t gaddr, void *buf, size_t len) {
    char *out = buf;
    size_t done = 0;
    while (done < len) {
        size_t chunk = len - done;
        if (chunk > 4096) chunk = 4096;
        if (!tlb_read(ctx->tlb, gaddr + done, out + done, (unsigned)chunk))
            return false;
        done += chunk;
    }
    return true;
}

bool nsym_write(struct nsym_ctx *ctx, addr_t gaddr, const void *buf, size_t len) {
    const char *in = buf;
    size_t done = 0;
    while (done < len) {
        size_t chunk = len - done;
        if (chunk > 4096) chunk = 4096;
        if (!tlb_write(ctx->tlb, gaddr + done, in + done, (unsigned)chunk))
            return false;
        done += chunk;
    }
    return true;
}

/* ---- registry ---- */

int native_offload_add_symbol(const char *binary, const char *symbol,
                              nsym_handler_func handler, void *user) {
    if (nsym_count >= NSYM_MAX) return -1;
    int id = nsym_count++;
    nsym_table[id] = (struct nsym_target){
        .binary = binary, .symbol = symbol,
        .addr_hint = 0, .handler = handler, .user = user, .addr = 0,
    };
    return id;
}

int native_offload_add_symbol_hinted(const char *binary, const char *symbol,
                                     addr_t addr_hint, nsym_handler_func handler,
                                     void *user) {
    int id = native_offload_add_symbol(binary, symbol, handler, user);
    if (id >= 0) {
        nsym_table[id].addr_hint = addr_hint;
        nsym_table[id].addr = addr_hint;   /* pre-bind */
    }
    return id;
}

void native_offload_bind_symbol(const char *binary, const char *symbol, addr_t addr) {
    for (int i = 0; i < nsym_count; i++) {
        struct nsym_target *t = &nsym_table[i];
        if (t->addr) continue;  /* already bound */
        if (binary && t->binary && strcmp(binary, t->binary) != 0) continue;
        if (strcmp(symbol, t->symbol) != 0) continue;
        t->addr = addr;
    }
}

/* ---- dispatch ---- */

/* Whether any symbol offload is active. When nothing is registered the
 * dispatch loop skips the scan entirely (zero cost, like the binary-level
 * offload: no registration → no effect). No env gate — offload is lossless,
 * so "registered == active" is the only condition that matters.
 *
 * Built-ins are registered here on first call (not via a constructor, which
 * a static-library linker dead-strips when the TU is otherwise unreferenced).
 * init_builtins itself is a no-op unless its env/build flags are set, so the
 * default remains zero registrations → inactive. */
bool native_offload_sym_active(void) {
    static bool inited = false;
    if (!inited) {
        inited = true;
        native_offload_sym_init_builtins();
    }
    return nsym_count > 0;
}

bool native_offload_sym_dispatch(addr_t pc, struct cpu_state *cpu, struct tlb *tlb) {
    /* Linear scan against resolved addresses. Tiny table; near-always misses,
     * which branch-predicts well. */
    for (int i = 0; i < nsym_count; i++) {
        struct nsym_target *t = &nsym_table[i];
        if (t->addr != pc) continue;

        struct nsym_ctx ctx = {
            .cpu = cpu, .tlb = tlb,
            .resume = NSYM_RESUME_RET, .resume_pc = 0,
        };
        enum nsym_result r = t->handler(&ctx, t->user);
        if (r == NSYM_DECLINED)
            return false;  /* lossless: fall through to guest code */

        if (nsym_hits[i]++ == 0 && getenv("ISH_OFFLOAD_STATS"))
            fprintf(stderr, "[offload:sym] first hit: %s:%s @ %llx\n",
                    t->binary ? t->binary : "?", t->symbol,
                    (unsigned long long)pc);

        cpu->pc = (ctx.resume == NSYM_RESUME_PC) ? ctx.resume_pc
                                                 : cpu->regs[30];
        return true;
    }
    return false;
}
