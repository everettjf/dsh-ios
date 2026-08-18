#!/usr/bin/env bash
# Integration test for build/root.tar.gz: import it exactly like the app does
# (fakefsify), then boot dsh inside the iSH-ARM64 CLI emulator and probe it
# from the macOS host over loopback.
#
# Usage: tests/rootfs-test.sh [path/to/root.tar.gz]
set -uo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/.." && pwd)"
ISH_SRC="${ISH_SRC:-$ROOT/../ish-arm64}"
ISH_BUILD="${ISH_BUILD:-$ISH_SRC/build-arm64-release}"
TARBALL="${1:-$ROOT/build/root.tar.gz}"
WORK="${WORK:-$ROOT/build/rootfs-test}"
PORT="${DSH_TEST_PORT:-3181}"
BOOT_TIMEOUT="${DSH_BOOT_TIMEOUT:-300}"

pass=0; fail=0
ok()  { pass=$((pass+1)); printf '  \033[32mPASS\033[0m %s\n' "$*"; }
bad() { fail=$((fail+1)); printf '  \033[31mFAIL\033[0m %s\n' "$*"; }
# check <name> <command...>: runs the command (no eval), records the result
check() { local name="$1"; shift; if "$@" >/dev/null 2>&1; then ok "$name"; else bad "$name"; fi; }
filter() { grep -v --line-buffered 'expose_wasm' || true; }
# A guest process that starts while the previous one is still tearing down can
# lose the fakefs lock and print nothing; every command here has output, so
# an empty result means "try again".
guest() {
    local out
    for _ in 1 2 3; do
        out="$("$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c "$1" 2>&1 | filter)"
        [ -n "$out" ] && break
        sleep 1
    done
    printf '%s\n' "$out"
}

[ -f "$TARBALL" ] || { echo "missing $TARBALL (run scripts/build-rootfs.sh)"; exit 2; }
[ -x "$ISH_BUILD/ish" ] || { echo "iSH CLI not built"; exit 2; }
if curl -fs -o /dev/null "http://127.0.0.1:$PORT/" 2>/dev/null; then
    echo "port $PORT is already in use on the host; set DSH_TEST_PORT"; exit 2
fi

cleanup() { pkill -f "$ISH_BUILD/ish -f $WORK/fakefs" 2>/dev/null || true; [ -n "${MOCK_PID:-}" ] && kill "$MOCK_PID" 2>/dev/null; true; }
trap cleanup EXIT

echo "== import $TARBALL"
rm -rf "$WORK" && mkdir -p "$WORK"
"$ISH_BUILD/tools/fakefsify" "$TARBALL" "$WORK/fakefs"
check "root.tar.gz imports via fakefsify" test -f "$WORK/fakefs/meta.db"

echo "== guest sanity"
guest 'node -v; dsh --version; dsh-selftest' > "$WORK/sanity.txt"
sed 's/^/     /' "$WORK/sanity.txt"
check "node >= 22.19 in guest" grep -Eq '^v(22\.(19|[2-9][0-9])|2[3-9]|[3-9][0-9])' "$WORK/sanity.txt"
check "dsh 0.1.x in guest"      grep -Eq '^0\.1\.' "$WORK/sanity.txt"
check "dsh-selftest passes"     grep -q 'SELFTEST OK' "$WORK/sanity.txt"

echo "== profile composition"
guest 'export HOME=/root; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile web --dump-config' > "$WORK/config.yml"
grep -A4 '^- id: sandbox-policy' "$WORK/config.yml" > "$WORK/sandbox-row.yml"
check "sandbox-policy patched to danger-full-access" grep -q 'danger-full-access' "$WORK/sandbox-row.yml"
check "hmr row present (needs --expose-internals)"    grep -q 'cordis-plugin-hmr' "$WORK/config.yml"

echo "== headless LLM round trip through mock DeepSeek server (SSE via fetch polyfill)"
MOCK_PORT="${DSH_MOCK_PORT:-3199}"
node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" > "$WORK/mock.log" 2>&1 &
MOCK_PID=$!
sleep 1
guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT; cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'Say hi.'" > "$WORK/headless.txt"
kill $MOCK_PID 2>/dev/null
sed 's/^/     /' "$WORK/headless.txt" | tail -3
check "headless answer streamed from mock server" grep -q 'MOCK-REPLY-7f3a' "$WORK/headless.txt"

echo "== boot dsh-serve on 127.0.0.1:$PORT (timeout ${BOOT_TIMEOUT}s)"
start=$(date +%s)
( "$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c "DSH_PORT=$PORT dsh-serve" 2>&1 | filter > "$WORK/dsh-serve.log" ) &
up=0
for _ in $(seq 1 "$BOOT_TIMEOUT"); do
    sleep 1
    if curl -fs -o "$WORK/index.html" "http://127.0.0.1:$PORT/"; then up=1; break; fi
done
elapsed=$(( $(date +%s) - start ))
check "web UI reachable from host loopback (${elapsed}s)" test "$up" = 1
check "index carries __DSH_BOOT__ manifest" grep -q '__DSH_BOOT__' "$WORK/index.html"
plugin_url=$(grep -o '/plugins/[^"]*client.js?rev=[0-9a-f]*' "$WORK/index.html" | head -1)
code=$(curl -s -o /dev/null -w '%{http_code}' "http://127.0.0.1:$PORT$plugin_url")
check "client plugin bundle served ($plugin_url -> $code)" test "$code" = 200
sleep 5
check "server still alive after 5s" curl -fs -o /dev/null "http://127.0.0.1:$PORT/"
grep -Eq 'fatal|Error:' "$WORK/dsh-serve.log"; noerr=$?
check "no fatal error in dsh-serve log" test "$noerr" != 0

echo
echo "passed=$pass failed=$fail"
[ "$fail" = 0 ]
