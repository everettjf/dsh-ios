#!/usr/bin/env bash
set -euo pipefail

app=${1:?usage: verify-lite-bundle.sh /path/to/DashrosLite.app}
binary="$app/DashrosLite"

[ -x "$binary" ] || { echo "not ok: missing DashrosLite executable" >&2; exit 1; }
[ "$(/usr/libexec/PlistBuddy -c 'Print :MinimumOSVersion' "$app/Info.plist")" = "16.0" ] || {
  echo 'not ok: DashrosLite is not built for iOS 16' >&2
  exit 1
}

if find "$app" -iname '*rootfs*' -o -iname '*ish*' -o -iname '*guest*' | rg -q .; then
  echo 'not ok: DashrosLite bundle contains a guest artifact' >&2
  exit 1
fi

if otool -L "$binary" | rg -qi 'libish|libfakefs|libarchive'; then
  echo 'not ok: DashrosLite links an emulator or guest library' >&2
  exit 1
fi

if nm "$binary" | rg -q 'DSHGuestRuntime|DSHGuestLauncher|DSHBashTool|DSHStageAttachmentTool|DSHLazyGuestManager'; then
  echo 'not ok: DashrosLite binary contains a guest implementation symbol' >&2
  exit 1
fi

printf 'ok  DashrosLite bundle: iOS 16, no iSH, no rootfs, no guest tools\n'
