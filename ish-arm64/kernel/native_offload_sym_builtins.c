/*
 * native_offload_sym_builtins.c — product symbol-level offload targets.
 *
 * Registers the offload targets that ship as real features. Currently:
 *   - Python compile: offload CPython's compile path to native libpython
 *     (only when built with -DISH_OFFLOAD_PYCOMPILE; backend in
 *     native_offload_pycompile.c).
 *
 * ARM64 guest only.
 */
#include "kernel/native_offload.h"

#ifdef ISH_OFFLOAD_PYCOMPILE
/* Provided by native_offload_pycompile.c */
enum nsym_result native_offload_pycompile_handler(struct nsym_ctx *ctx, void *user);
#endif

void native_offload_sym_init_builtins(void) {
#ifdef ISH_OFFLOAD_PYCOMPILE
    /* Python compile: address unresolved at register time (depends on where
     * libpython maps); bound later via native_offload_bind_symbol once the
     * loader reports the symbol. */
    native_offload_add_symbol("libpython3.12.so.1.0", "Py_CompileStringExFlags",
                              native_offload_pycompile_handler, NULL);
#endif
    /* Test handlers self-register via a constructor in kernel/offload_tests/. */
}
