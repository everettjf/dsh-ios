#!/usr/bin/env bash
# Build the guest root filesystem bundled into the DSH iOS app:
#   Alpine 3.21 (aarch64) + Node.js 22 + @deepseek-ai/dsh (+ rebuilt node-pty)
#
# Everything guest-side runs inside the iSH-ARM64 CLI emulator on macOS, so the
# result is byte-for-byte what the app boots. Output: build/root.tar.gz
#
# Usage: scripts/build-rootfs.sh [--keep-work]
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/.." && pwd)"
ISH_SRC="${ISH_SRC:-$ROOT/ish-arm64}"
ISH_BUILD="${ISH_BUILD:-$ISH_SRC/build-arm64-release}"
WORK="${WORK:-$ROOT/build/rootfs-work}"
OUT="${OUT:-$ROOT/build/root.tar.gz}"

ALPINE_VER=3.21
ALPINE_TARBALL="alpine-minirootfs-${ALPINE_VER}.0-aarch64.tar.gz"
ALPINE_URL="https://dl-cdn.alpinelinux.org/alpine/v${ALPINE_VER}/releases/aarch64/${ALPINE_TARBALL}"
# Pinned dsh release; bump together with package-lock.json under rootfs/staging.
DSH_VERSION="${DSH_VERSION:-0.1.0-rc.7}"

log() { printf '\033[1;34m==> %s\033[0m\n' "$*"; }
die() { printf '\033[1;31mERROR: %s\033[0m\n' "$*" >&2; exit 1; }

# The guest node prints this warning on every start; strip it from build logs.
# `sed` deliberately returns success for empty input while `pipefail` still
# propagates a failing emulator command.  The old `grep ... || true` hid guest
# failures and could export a corrupt image as a successful build.
filter() { sed '/expose_wasm/d'; }

ish() {
    # ish <script-on-stdin>; runs /bin/sh inside the fakefs
    "$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh 2>&1 | filter
}

[ -x "$ISH_BUILD/ish" ] || die "iSH CLI not built. Run: (cd $ISH_SRC && meson setup build-arm64-release -Dguest_arch=arm64 --buildtype=release && ninja -C build-arm64-release)"
[ -x "$ISH_BUILD/tools/fakefsify" ] || die "fakefsify not built in $ISH_BUILD/tools"
command -v npm >/dev/null || die "npm is required on the host"

mkdir -p "$WORK" "$(dirname "$OUT")"
cd "$WORK"

log "Alpine minirootfs"
[ -f "$ALPINE_TARBALL" ] || curl -fsSL -o "$ALPINE_TARBALL" "$ALPINE_URL"

log "Create fakefs"
rm -rf fakefs
"$ISH_BUILD/tools/fakefsify" "$ALPINE_TARBALL" fakefs

log "Stage dsh node_modules on the host (linux/arm64/musl)"
rm -rf stage && mkdir stage
cp "$ROOT/rootfs/staging/package.json" stage/
[ -f "$ROOT/rootfs/staging/package-lock.json" ] && cp "$ROOT/rootfs/staging/package-lock.json" stage/
( cd stage && npm ci --os=linux --cpu=arm64 --libc=musl --ignore-scripts --no-audit --no-fund 2>&1 | tail -3 \
  || npm install "@deepseek-ai/dsh@${DSH_VERSION}" --os=linux --cpu=arm64 --libc=musl --ignore-scripts --no-audit --no-fund )
cp stage/package-lock.json "$ROOT/rootfs/staging/package-lock.json"

log "Guest phase 1: packages"
ish <<'EOF'
set -e
echo "nameserver 8.8.8.8" > /etc/resolv.conf
echo "nameserver 1.1.1.1" >> /etc/resolv.conf
apk update >/dev/null
apk add --no-progress nodejs npm nodejs-dev python3 make g++ bash git curl openssh-client ca-certificates 2>&1 | tail -1
node -v; npm -v
EOF

log "Guest phase 2: install node_modules + polyfills + overlay"
# Assemble one payload tree rooted at / (staged node_modules, the iSH
# node polyfills, our overlay) and stream it into the guest in a single pass.
rm -rf payload && mkdir -p payload/usr/local/lib payload/lib
mv stage/node_modules payload/usr/local/lib/node_modules
# npm retains every optional sharp binary named in the lockfile even when the
# target is pinned to linux/arm64/musl.  The glibc build cannot load on Alpine,
# and the wasm fallback cannot run under DSH's jitless Node.  Keep only the
# musl/arm64 pair that sharp actually selects in the guest.  Also strip macOS
# AppleDouble files before they become tens of thousands of fakefs entries.
rm -rf payload/usr/local/lib/node_modules/@img/sharp-linux-arm64 \
       payload/usr/local/lib/node_modules/@img/sharp-libvips-linux-arm64 \
       payload/usr/local/lib/node_modules/@img/sharp-wasm32
cp "$ISH_SRC"/app/RootfsPatch.bundle/files/lib/*.js payload/lib/
# Record the overlay version so the app does not re-apply (and downgrade) the
# same RootfsPatch files on first launch.
overlay_ver=$(/usr/libexec/PlistBuddy -c 'Print :version' "$ISH_SRC/app/RootfsPatch.bundle/manifest.plist")
mkdir -p payload/ish && printf '%s\n' "$overlay_ver" > payload/ish/overlay-version
cp -R "$ROOT/rootfs/overlay/." payload/
find payload -name '._*' -delete
# BSD tar otherwise serialises extended attributes as AppleDouble `._*` files
# when this payload is unpacked by the Linux guest.
COPYFILE_DISABLE=1 tar czf payload.tgz -C payload .
"$ISH_BUILD/ish" -f "$WORK/fakefs" /bin/sh -c 'cd / && tar xzf -' < payload.tgz 2>&1 | filter

log "Guest phase 3: node-pty rebuild for musl, profile, cleanup"
ish <<EOF
set -e
export HOME=/root
chmod +x /usr/local/bin/* /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js
ln -sf ../lib/node_modules/@deepseek-ai/dsh/lib/bin.js /usr/local/bin/dsh
cd /usr/local/lib/node_modules/node-pty
rm -rf build prebuilds
npx --yes node-gyp rebuild --nodedir=/usr 2>&1 | tail -1
test -f build/Release/pty.node
# Pre-create the web profile so first launch on device does no scaffolding,
# then drop in our patch layer.
node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js --profile web --dump-config >/dev/null
install -m 0644 /usr/local/share/dsh/cordis.patch.yml /root/.dsh/profiles/web/cordis.patch.yml
# Home-level layer: applies to every profile (see rootfs/overlay/.../home.patch.yml).
install -m 0644 /usr/local/share/dsh/home.patch.yml /root/.dsh/cordis.patch.yml
mkdir -p /root/workspace
# Slim down: build tooling is only needed for node-pty.
apk del --no-progress nodejs-dev python3 make g++ >/dev/null 2>&1 || true
apk add --no-progress libstdc++ libgcc >/dev/null
rm -rf /root/.npm /root/.cache /var/cache/apk/* /tmp/* /usr/local/lib/node_modules/node-pty/build/Release/obj.target
echo "guest node: \$(node -v), dsh: \$(dsh --version)"
du -sh /usr/local/lib/node_modules /usr/lib/node_modules 2>/dev/null
EOF

log "Export root.tar.gz"
rm -f "$OUT"
"$ISH_BUILD/tools/unfakefsify" fakefs "$OUT"
ls -lh "$OUT"
shasum -a 256 "$OUT" | tee "$OUT.sha256"

if [ "${1:-}" != "--keep-work" ]; then
    rm -rf stage payload payload.tgz
fi
log "Done: $OUT"
