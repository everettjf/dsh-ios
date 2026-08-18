#!/usr/bin/env bash
# Emulator regression tests for the iSH-ARM64 changes made for DSH:
#   * NEON conversion instructions (FCVTL/FCVTN/FCVTXN, vector fixed-point
#     conversions) — needed by libvips/sharp,
#   * waitpid() must not return EINTR just because the 1 s bounded condvar
#     wait timed out (broke gcc/g++ and node-gyp),
#   * the fetch() polyfill (runs on host node with DSH_FORCE_FETCH_POLYFILL=1).
#
# Uses a throwaway Alpine fakefs with gcc; caches it under build/emu-test.
set -uo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/.." && pwd)"
ISH_SRC="${ISH_SRC:-$ROOT/ish-arm64}"
ISH_BUILD="${ISH_BUILD:-$ISH_SRC/build-arm64-release}"
WORK="${WORK:-$ROOT/build/emu-test}"
ALPINE_TARBALL="$ROOT/build/rootfs-work/alpine-minirootfs-3.21.0-aarch64.tar.gz"
ALPINE_URL="https://dl-cdn.alpinelinux.org/alpine/v3.21/releases/aarch64/alpine-minirootfs-3.21.0-aarch64.tar.gz"

pass=0; fail=0
ok()  { pass=$((pass+1)); printf '  \033[32mPASS\033[0m %s\n' "$*"; }
bad() { fail=$((fail+1)); printf '  \033[31mFAIL\033[0m %s\n' "$*"; }
check() { local name="$1"; shift; if "$@" >/dev/null 2>&1; then ok "$name"; else bad "$name"; fi; }
# Retry: a guest starting while the previous one is still tearing down can
# lose the fakefs lock and print nothing.
guest() {
    local out
    for _ in 1 2 3; do
        out="$("$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c "$1" 2>&1)"
        [ -n "$out" ] && break
        sleep 1
    done
    printf '%s\n' "$out"
}

[ -x "$ISH_BUILD/ish" ] || { echo "iSH CLI not built"; exit 2; }
mkdir -p "$WORK" "$(dirname "$ALPINE_TARBALL")"
[ -f "$ALPINE_TARBALL" ] || curl -fsSL -o "$ALPINE_TARBALL" "$ALPINE_URL"

if [ ! -f "$WORK/fakefs/meta.db" ] || [ ! -f "$WORK/.gcc-ready" ]; then
    echo "== preparing gcc fakefs (one-off)"
    rm -rf "$WORK/fakefs" "$WORK/.gcc-ready"
    "$ISH_BUILD/tools/fakefsify" "$ALPINE_TARBALL" "$WORK/fakefs"
    guest 'echo nameserver 8.8.8.8 > /etc/resolv.conf; apk add --no-progress gcc musl-dev >/dev/null 2>&1 && echo gcc-ok' | grep -q gcc-ok && touch "$WORK/.gcc-ready"
fi
[ -f "$WORK/.gcc-ready" ] || { echo "could not install gcc in the guest"; exit 2; }

echo "== NEON conversion instructions"
"$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c 'cat > /tmp/neon.c' < "$HERE/emu/neon_convert_test.c"
out="$(guest 'cd /tmp && gcc -O1 -o neon neon.c -lm 2>&1 && ./neon')"
echo "$out" | sed 's/^/     /'
check "neon_convert_test compiles and passes" grep -q 'NEON CONVERT OK' <<<"$out"

echo "== waitpid EINTR regression"
"$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c 'cat > /tmp/wait.c' <<'EOF'
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main(void) {
    pid_t p = fork();
    if (p == 0) { sleep(3); _exit(7); }
    int st; pid_t r = waitpid(p, &st, 0);
    if (r != p) { printf("waitpid=%d errno=%s\n", (int) r, strerror(errno)); return 1; }
    if (!WIFEXITED(st) || WEXITSTATUS(st) != 7) { printf("bad status %d\n", st); return 1; }
    printf("WAIT OK\n");
    return 0;
}
EOF
out="$(guest 'cd /tmp && gcc -o wait wait.c && ./wait')"
echo "$out" | sed 's/^/     /'
check "waitpid survives a >1s child" grep -q 'WAIT OK' <<<"$out"

echo "== fetch polyfill (host node)"
if command -v node >/dev/null; then
    node "$HERE/mock-deepseek.mjs" 3198 > "$WORK/mock.log" 2>&1 &
    MOCK=$!
    sleep 1
    out="$(DSH_FORCE_FETCH_POLYFILL=1 node --require "$ISH_SRC/app/RootfsPatch.bundle/files/lib/fetch-polyfill.js" "$HERE/fetch-polyfill-test.mjs" 3198 2>&1)"
    kill $MOCK 2>/dev/null
    echo "$out" | sed 's/^/     /'
    check "fetch polyfill streams SSE, follows redirects, aborts" grep -q 'FETCH POLYFILL OK' <<<"$out"
else
    echo "  skip: node not installed on host"
fi

echo
echo "passed=$pass failed=$fail"
[ "$fail" = 0 ]
