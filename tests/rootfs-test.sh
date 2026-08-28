#!/usr/bin/env bash
# Integration test for build/root.tar.gz: import it exactly like the app does
# (fakefsify), then boot dsh inside the iSH-ARM64 CLI emulator and probe it
# from the macOS host over loopback.
#
# Usage: tests/rootfs-test.sh [path/to/root.tar.gz]
set -uo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/.." && pwd)"
ISH_SRC="${ISH_SRC:-$ROOT/ish-arm64}"
ISH_BUILD="${ISH_BUILD:-$ISH_SRC/build-arm64-release}"
TARBALL="${1:-$ROOT/build/root.tar.gz}"
WORK="${WORK:-$ROOT/build/rootfs-test}"
PORT="${DSH_TEST_PORT:-3181}"
MOCK_PORT="${DSH_MOCK_PORT:-3199}"
BRIDGE_PORT="${DSH_BRIDGE_PORT:-3197}"
BOOT_TIMEOUT="${DSH_BOOT_TIMEOUT:-300}"
GUEST_TIMEOUT="${DSH_GUEST_TIMEOUT:-90}"

pass=0; fail=0
ok()  { pass=$((pass+1)); printf '  \033[32mPASS\033[0m %s\n' "$*"; }
bad() { fail=$((fail+1)); printf '  \033[31mFAIL\033[0m %s\n' "$*"; }
# check <name> <command...>: runs the command (no eval), records the result
check() { local name="$1"; shift; if "$@" >/dev/null 2>&1; then ok "$name"; else bad "$name"; fi; }
filter() { sed '/expose_wasm/d'; }
timed() {
    if command -v gtimeout >/dev/null 2>&1; then
        gtimeout "$@"
    elif command -v timeout >/dev/null 2>&1; then
        timeout "$@"
    else
        perl -e '$seconds = shift; alarm $seconds; exec @ARGV' "$@"
    fi
}
# A guest process that starts while the previous one is still tearing down can
# lose the fakefs lock and print nothing; every command here has output, so
# an empty result means "try again". A broken guest must not hang the release
# gate forever, so each attempt has a hard deadline.
guest() {
    local out
    for _ in 1 2; do
        out="$(timed "$GUEST_TIMEOUT" "$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c "$1" 2>&1 | filter)"
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

cleanup() {
    pkill -f "$ISH_BUILD/ish -f $WORK/fakefs" 2>/dev/null || true
    for pid in "${MOCK_PID:-}" "${STUB_PID:-}"; do [ -n "$pid" ] && kill "$pid" 2>/dev/null; done
    true
}
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
check "sharp keeps musl arm64 runtime" test -d "$WORK/fakefs/data/usr/local/lib/node_modules/@img/sharp-linuxmusl-arm64"
check "sharp drops unusable glibc runtime" test ! -e "$WORK/fakefs/data/usr/local/lib/node_modules/@img/sharp-linux-arm64"
check "sharp drops unusable wasm fallback" test ! -e "$WORK/fakefs/data/usr/local/lib/node_modules/@img/sharp-wasm32"
if find "$WORK/fakefs/data" -name '._*' -print -quit | grep -q .; then
    bad "rootfs contains no macOS AppleDouble files"
else
    ok "rootfs contains no macOS AppleDouble files"
fi

echo "== profile composition"
guest 'export HOME=/root; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile web --dump-config' > "$WORK/config.yml"
grep -A4 '^- id: sandbox-policy' "$WORK/config.yml" > "$WORK/sandbox-row.yml"
check "sandbox-policy patched to danger-full-access" grep -q 'danger-full-access' "$WORK/sandbox-row.yml"
check "hmr row present (needs --expose-internals)"    grep -q 'cordis-plugin-hmr' "$WORK/config.yml"

echo "== headless LLM round trip through mock DeepSeek server (SSE via fetch polyfill)"
node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" > "$WORK/mock.log" 2>&1 &
MOCK_PID=$!
sleep 1
guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT; cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'Say hi.'" > "$WORK/headless.txt"
kill $MOCK_PID 2>/dev/null
sed 's/^/     /' "$WORK/headless.txt" | tail -3
check "headless answer streamed from mock server" grep -q 'MOCK-REPLY-7f3a' "$WORK/headless.txt"

echo "== host bridge: agent calls device_info through a stub bridge"
BRIDGE_TOKEN="stub-token-$$"
node "$HERE/stub-bridge.mjs" "$BRIDGE_PORT" "$BRIDGE_TOKEN" > "$WORK/stub-bridge.log" 2>&1 &
STUB_PID=$!
node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" --tool device_info > "$WORK/mock-tool.log" 2>&1 &
MOCK_PID=$!
sleep 1
guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT \
       DSH_HOST_BRIDGE_URL=http://127.0.0.1:$BRIDGE_PORT DSH_HOST_BRIDGE_TOKEN=$BRIDGE_TOKEN; \
       cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'What device is this?'" > "$WORK/bridge-tool.txt"
sed 's/^/     /' "$WORK/bridge-tool.txt" | tail -3
check "device_info tool reached the bridge" grep -q '\[stub\] GET /v1/device' "$WORK/stub-bridge.log"
check "tool result reached the model"       grep -q 'model: iPad15,3' "$WORK/bridge-tool.txt"

# The calendar and reminders tools go through the same path.
for tool in calendar_query reminders_query; do
    kill $MOCK_PID 2>/dev/null
    node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" --tool "$tool" > "$WORK/mock-$tool.log" 2>&1 &
    MOCK_PID=$!
    sleep 1
    guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT \
           DSH_HOST_BRIDGE_URL=http://127.0.0.1:$BRIDGE_PORT DSH_HOST_BRIDGE_TOKEN=$BRIDGE_TOKEN; \
           cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'What is on my schedule?'" > "$WORK/tool-$tool.txt"
    check "$tool reaches the bridge and renders a result" grep -qE 'Standup|Buy milk' "$WORK/tool-$tool.txt"
done

# health_query takes a required `metric`, and each one renders differently.
for metric_case in "activity:9312 steps" "heart_rate:avg 71" "sleep:asleep" "workouts:Running"; do
    metric="${metric_case%%:*}"; expected="${metric_case#*:}"
    kill $MOCK_PID 2>/dev/null
    node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" --tool health_query --tool-args "{\"metric\":\"$metric\",\"days\":3}" > "$WORK/mock-health-$metric.log" 2>&1 &
    MOCK_PID=$!
    sleep 1
    guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT \
           DSH_HOST_BRIDGE_URL=http://127.0.0.1:$BRIDGE_PORT DSH_HOST_BRIDGE_TOKEN=$BRIDGE_TOKEN; \
           cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'How active have I been?'" > "$WORK/tool-health-$metric.txt"
    check "health_query $metric reaches the bridge and renders" grep -q "$expected" "$WORK/tool-health-$metric.txt"
done

# Every remaining bridge tool, each driven through a real agent turn. The
# arguments matter: the tools with required parameters must reach the route
# with them, and the renderers must turn each answer into something readable.
BRIDGE_TOOL_CASES=(
    "device_power|{}|thermalState: fair"
    "location_query|{}|±65 m"
    "contacts_search|{\"query\":\"ada\"}|Ada Lovelace"
    "notify|{\"title\":\"Done\"}|Notification sent"
    "calendar_create_event|{\"title\":\"Standup\",\"start\":\"2026-08-20 09:00\"}|Added.*Standup.*to Work"
    "reminders_create|{\"title\":\"Buy milk\"}|Added.*Buy milk.*to Home"
    "file_import|{}|picked.*notes[.]txt"
    "file_export|{\"name\":\"report.md\",\"base64\":\"aGVsbG8=\"}|Saved.*report[.]md"
    "photo_import|{}|picked.*IMG_0042"
    "share|{\"text\":\"hello there\"}|shared the text"
    "shortcut_run|{\"name\":\"Log Water\"}|Started the shortcut"
)
for bridge_case in "${BRIDGE_TOOL_CASES[@]}"; do
    tool="${bridge_case%%|*}"; rest="${bridge_case#*|}"
    args="${rest%%|*}"; expected="${rest#*|}"
    kill $MOCK_PID 2>/dev/null
    node "$HERE/mock-deepseek.mjs" "$MOCK_PORT" --tool "$tool" --tool-args "$args" > "$WORK/mock-$tool.log" 2>&1 &
    MOCK_PID=$!
    sleep 1
    guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT \
           DSH_HOST_BRIDGE_URL=http://127.0.0.1:$BRIDGE_PORT DSH_HOST_BRIDGE_TOKEN=$BRIDGE_TOKEN; \
           cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'Please do it.'" > "$WORK/tool-$tool.txt"
    check "$tool reaches the bridge and renders" grep -qE "$expected" "$WORK/tool-$tool.txt"
done

# A wrong token must fail loudly instead of silently returning nothing.
guest "export HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=http://127.0.0.1:$MOCK_PORT \
       DSH_HOST_BRIDGE_URL=http://127.0.0.1:$BRIDGE_PORT DSH_HOST_BRIDGE_TOKEN=wrong-token; \
       cd /root/workspace; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile headless 'What device is this?'" > "$WORK/bridge-denied.txt"
check "wrong bridge token is refused" grep -q 'unauthorized' "$WORK/bridge-denied.txt"

# The same image must still work with no bridge at all (CLI, tests, macOS).
guest "export HOME=/root; node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile web --dump-config" > "$WORK/config-nobridge.yml"
check "plugin loads without bridge environment" grep -q 'host-bridge' "$WORK/config-nobridge.yml"
kill $STUB_PID $MOCK_PID 2>/dev/null

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
