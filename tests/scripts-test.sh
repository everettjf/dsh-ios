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

# Project generation must be byte-for-byte idempotent. Random PBX object IDs
# create thousand-line diffs during ordinary tests and releases.
ruby scripts/gen-xcode-project.rb >/dev/null
first_project=$(shasum -a 256 DSH.xcodeproj/project.pbxproj DSH.xcodeproj/xcshareddata/xcschemes/DSH.xcscheme)
ruby scripts/gen-xcode-project.rb >/dev/null
second_project=$(shasum -a 256 DSH.xcodeproj/project.pbxproj DSH.xcodeproj/xcshareddata/xcschemes/DSH.xcscheme)
[ "$first_project" = "$second_project" ] || {
  echo 'not ok: generated Xcode project is not deterministic' >&2
  exit 1
}

printf 'ok  scripts: deterministic Xcode project generation\n'

for module in AgentRuntime AgentProviders; do
  [ -d "Packages/SwiftHarnessKit/Sources/$module" ] || {
    echo "not ok: missing Swift package module $module" >&2
    exit 1
  }
done

if rg -n '^import (UIKit|SwiftUI|HealthKit|EventKit|Photos)$' Packages/SwiftHarnessKit/Sources/AgentRuntime; then
  echo 'not ok: AgentRuntime imports an Apple UI or capability framework' >&2
  exit 1
fi

printf 'ok  scripts: AgentRuntime dependency boundary\n'
