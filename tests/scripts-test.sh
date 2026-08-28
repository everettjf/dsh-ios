#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

fixture=$(mktemp /tmp/dsh-simulators.XXXXXX)
trap 'rm -f "$fixture"' EXIT

printf '%s\n' \
  '== Devices ==' \
  '-- iOS 26.0 --' \
  '    iPad Pro 13-inch (M5) (CB894F29-D83F-492A-8927-18D23BC76403) (Shutdown) ' \
  '    iPhone 17 Pro (3135C53E-C4EA-4D81-B488-6692757B524C) (Shutdown)' > "$fixture"

actual=$(DSH_SIMULATOR_LIST_FILE="$fixture" scripts/pick-simulator.sh)
[ "$actual" = 'iPad Pro 13-inch (M5)' ] || {
  echo "not ok: simulator parser returned '$actual'" >&2
  exit 1
}

printf 'ok  scripts: simulator names with parenthesized models\n'

target=$(sed -n 's/^IPHONEOS_DEPLOYMENT_TARGET = //p' app/AppDSH.xcconfig | tr -d ' ')
[ "$target" = '16.0' ] || {
  echo "not ok: deployment target is '$target', expected 16.0" >&2
  exit 1
}

generated_targets=$(grep -c "new_target(.*:ios, '16.0')" scripts/gen-xcode-project.rb)
[ "$generated_targets" = '3' ] || {
  echo "not ok: project generator does not keep all three targets on iOS 16" >&2
  exit 1
}

printf 'ok  scripts: app and generated test targets support iOS 16\n'
