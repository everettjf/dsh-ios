#!/bin/bash
# Check that the provided compiler can BUILD an aarch64 ELF shared object the
# way vdso/arm64/meson.build does. Compiling is not enough: Apple's clang can
# target aarch64 but ships no lld, and the vdso link needs one.

CLANG="$1"

if [ -z "$CLANG" ]; then
    echo "Usage: $0 <clang-path>"
    exit 1
fi

WORK=$(mktemp -d /tmp/check-cc-arm64.XXXXXX)
trap 'rm -rf "$WORK"' EXIT
cat > "$WORK/probe.c" << 'PROBE'
void _start(void) {
    __asm__ volatile("svc #0");
}
PROBE

if ! "$CLANG" -target aarch64-linux-gnu -c "$WORK/probe.c" -o "$WORK/probe.o" 2>"$WORK/err"; then
    echo "Error: $CLANG cannot compile for aarch64 target"
    cat "$WORK/err"
    exit 1
fi

if ! "$CLANG" -target aarch64-linux-gnu -fuse-ld=lld -nostdlib -shared -fPIC \
        -o "$WORK/probe.so" "$WORK/probe.c" 2>"$WORK/err"; then
    echo "Error: $CLANG cannot link an aarch64 ELF (no lld?); the VDSO will be stubbed"
    cat "$WORK/err"
    exit 1
fi

echo "ARM64 cross-compiler check passed"
exit 0
