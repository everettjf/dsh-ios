#!/bin/bash
# Pre-built gadget offload test: verify the auto-translated spec_mix (compiled with
# -Doffload_test_prebuilt=true) produces bit-identical results to normal threaded
# execution, and is faster. Self-contained: rebuilds the guest binary via Docker.
#
# Usage:  tests/offload/prebuilt/run.sh [iters]
# Requires: Docker (aarch64), a built base ish, and a build dir.
set -u
cd "$(dirname "$0")/../../.."          # repo root
ITERS="${1:-5000000}"
ROOTFS="alpine-arm64"
BUILD="build-arm64-release"
HERE="tests/offload/prebuilt"
PASS=0; FAIL=0
say() { printf '%s\n' "$*"; }
ok()  { PASS=$((PASS+1)); say "  PASS: $*"; }
bad() { FAIL=$((FAIL+1)); say "  FAIL: $*"; }

# 1. Rebuild guest mixbench (non-PIE, fixed mix @ 0x400314) via Docker.
say "== building guest mixbench (Docker aarch64) =="
docker run --rm --platform linux/arm64 -v "$PWD/$HERE:/t" alpine:latest sh -c \
  'apk add -q gcc musl-dev >/dev/null 2>&1 && gcc -O1 -static -no-pie -fno-pie -o /t/mixbench /t/mixbench.c' \
  || { say "docker build failed"; exit 2; }
ADDR=$(nm "$HERE/mixbench" 2>/dev/null | awk '/ T mix$/{print "0x"$1}')
say "  mix @ $ADDR (register.c expects 0x400314)"
[ "$ADDR" = "0x0000000000400314" ] || bad "mix address drifted ($ADDR); update register.c + spec_mix"
cp "$HERE/mixbench" "$ROOTFS/root/mixbench"

# 2. Build the prebuilt-test ish and a base ish.
say "== building base + prebuilt-test ish =="
meson configure "$BUILD" -Doffload_test_prebuilt=false >/dev/null 2>&1
ninja -C "$BUILD" ish >/dev/null 2>&1 || { say "base build failed"; exit 2; }
cp "$BUILD/ish" /tmp/ish_base_prebuilt
meson configure "$BUILD" -Doffload_test_prebuilt=true >/dev/null 2>&1
ninja -C "$BUILD" ish >/dev/null 2>&1 || { say "prebuilt build failed"; exit 2; }
cp "$BUILD/ish" /tmp/ish_test_prebuilt
meson configure "$BUILD" -Doffload_test_prebuilt=false >/dev/null 2>&1   # restore default

# 3. Correctness: prebuilt gadget hit + bit-identical acc.
say "== correctness =="
HIT=$(ISH_OFFLOAD_STATS=1 /tmp/ish_test_prebuilt -r "$ROOTFS" /root/mixbench 100000 2>&1 | grep -c 'offload:prebuilt.*mix')
[ "$HIT" -ge 1 ] && ok "prebuilt gadget hit (mix)" || bad "prebuilt gadget did not hit"
ACC_BASE=$(/tmp/ish_base_prebuilt -r "$ROOTFS" /root/mixbench "$ITERS" 2>&1 | grep -oE 'acc=[0-9a-f]+')
ACC_TEST=$(/tmp/ish_test_prebuilt -r "$ROOTFS" /root/mixbench "$ITERS" 2>&1 | grep -oE 'acc=[0-9a-f]+')
[ -n "$ACC_BASE" ] && [ "$ACC_BASE" = "$ACC_TEST" ] \
    && ok "bit-identical result ($ACC_TEST)" \
    || bad "result mismatch: base=$ACC_BASE prebuilt=$ACC_TEST"

# 4. Performance: prebuilt should be faster.
say "== performance =="
ms() { local t0 t1; t0=$(python3 -c 'import time;print(int(time.time()*1000))')
       "$1" -r "$ROOTFS" /root/mixbench "$ITERS" >/dev/null 2>&1
       t1=$(python3 -c 'import time;print(int(time.time()*1000))'); echo $((t1-t0)); }
B=$(ms /tmp/ish_base_prebuilt); T=$(ms /tmp/ish_test_prebuilt)
say "  threaded=${B}ms  prebuilt=${T}ms"
[ "$T" -lt "$B" ] && ok "prebuilt faster ($(python3 -c "print(f'{$B/$T:.2f}x')"))" \
                  || bad "prebuilt not faster (threaded=$B prebuilt=$T)"

# 5. Mixed execution: outer's spec_fn calls inner via prebuilt_call (nested
#    dispatch). Correctness only — this path exercises the bl/blr boundary.
say "== mixed execution (callbench: spec_outer bl inner) =="
docker run --rm --platform linux/arm64 -v "$PWD/$HERE:/t" alpine:latest sh -c \
  'apk add -q gcc musl-dev >/dev/null 2>&1 && gcc -O1 -static -no-pie -fno-pie -o /t/callbench /t/callbench.c' \
  && cp "$HERE/callbench" "$ROOTFS/root/callbench" || bad "callbench build failed"
CB_HIT=$(ISH_OFFLOAD_STATS=1 /tmp/ish_test_prebuilt -r "$ROOTFS" /root/callbench 50000 2>&1 | grep -c 'offload:prebuilt.*outer')
[ "$CB_HIT" -ge 1 ] && ok "prebuilt hit (outer, mixed execution)" || bad "outer did not hit"
CB_BASE=$(/tmp/ish_base_prebuilt -r "$ROOTFS" /root/callbench 500000 2>&1 | grep -oE 'acc=[0-9a-f]+')
CB_TEST=$(/tmp/ish_test_prebuilt -r "$ROOTFS" /root/callbench 500000 2>&1 | grep -oE 'acc=[0-9a-f]+')
[ -n "$CB_BASE" ] && [ "$CB_BASE" = "$CB_TEST" ] \
    && ok "mixed-execution bit-identical ($CB_TEST)" \
    || bad "mixed-execution mismatch: base=$CB_BASE prebuilt=$CB_TEST"

say ""
say "== $PASS passed, $FAIL failed =="
[ "$FAIL" -eq 0 ]
