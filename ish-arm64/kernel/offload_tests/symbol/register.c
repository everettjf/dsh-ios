/*
 * Symbol-level offload test registration (dev only).
 *
 * Compiled only with -Doffload_test_symbol=true. Registers hand-written native
 * handlers for known guest functions (musl memcpy, and the pyc_bench hotspots)
 * so the symbol-level dispatch path can be A/B-tested against threaded-code.
 * Called from native_offload_sym_init_builtins via a gated hook; a no-op in
 * production builds (the whole file isn't compiled).
 *
 * Guest addresses are fixed no-ASLR values for the test binaries under
 * tests/offload/symbol/. See that dir's run.sh.
 */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "kernel/native_offload.h"

/* ── musl memcpy(dst, src, len) → value-copy via TLB (fork/CoW safe) ── */
static enum nsym_result h_memcpy(struct nsym_ctx *ctx, void *user) {
    (void)user;
    addr_t dst = nsym_arg(ctx, 0), src = nsym_arg(ctx, 1);
    uint64_t len = nsym_arg(ctx, 2);
    if (len == 0 || len >= 0x10000000) return NSYM_DECLINED;
    char buf[4096];
    uint64_t done = 0;
    while (done < len) {
        uint64_t chunk = len - done;
        if (chunk > sizeof(buf)) chunk = sizeof(buf);
        if (!nsym_read(ctx, src + done, buf, chunk)) return NSYM_DECLINED;
        if (!nsym_write(ctx, dst + done, buf, chunk)) return NSYM_DECLINED;
        done += chunk;
    }
    nsym_set_ret(ctx, dst);
    return NSYM_HANDLED;
}

/* ── pyc_bench hash_bytes(data, len) — siphash-like byte mix ── */
static uint64_t rol64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static enum nsym_result h_hash_bytes(struct nsym_ctx *ctx, void *user) {
    (void)user;
    addr_t ptr = nsym_arg(ctx, 0);
    int len = (int)(uint32_t)nsym_arg(ctx, 1);
    uint64_t h = 0x736f6d6570736575ULL;
    if (len > 0 && len <= 4096) {
        unsigned char buf[4096];
        if (nsym_read(ctx, ptr, buf, (unsigned)len))
            for (int i = 0; i < len; i++)
                h = rol64(((uint64_t)buf[i]) ^ h, 51) * 0xff51afd7ed558ccdULL;
    }
    nsym_set_ret(ctx, h);
    return NSYM_HANDLED;
}

/* Self-registers at startup via a constructor — the product core has no test
 * hook. Targets are still env-gated (address is rootfs-specific), so the test
 * build stays inert until a target address is supplied. */
__attribute__((constructor))
static void offload_test_symbol_register(void) {
    /* Enable specific targets via env:
     *   ISH_OFFLOAD_MEMCPY=0x<addr>    ISH_OFFLOAD_HASH=0x<addr>  */
    const char *mc = getenv("ISH_OFFLOAD_MEMCPY");
    if (mc)
        native_offload_add_symbol_hinted("libc.musl-aarch64.so.1", "memcpy",
                                         (addr_t)strtoull(mc, NULL, 0), h_memcpy, NULL);
    const char *hb = getenv("ISH_OFFLOAD_HASH");
    if (hb)
        native_offload_add_symbol_hinted("pyc_bench_arm64", "hash_bytes",
                                         (addr_t)strtoull(hb, NULL, 0), h_hash_bytes, NULL);
}
