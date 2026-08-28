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

for module in AgentRuntime AgentProviders AgentTools AgentStorage AgentMCP AgentLinuxGuest; do
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

if ! rg -q 'XCLocalSwiftPackageReference "SwiftHarnessKit"' DSH.xcodeproj/project.pbxproj; then
  echo 'not ok: SHOS does not reference the local SwiftHarnessKit package' >&2
  exit 1
fi

for product in AgentRuntime AgentProviders AgentTools AgentStorage AgentMCP AgentLinuxGuest; do
  if ! rg -q "${product} in Frameworks" DSH.xcodeproj/project.pbxproj; then
    echo "not ok: SHOS does not link Swift package product $product" >&2
    exit 1
  fi
done

if rg -q 'Packages/SwiftHarnessKit/Sources|DSHAgentRuntime.swift in Sources|DSHMCPClient.swift in Sources' DSH.xcodeproj/project.pbxproj; then
  echo 'not ok: SwiftHarnessKit sources are compiled directly into the SHOS app target' >&2
  exit 1
fi

printf 'ok  scripts: SHOS consumes SwiftHarnessKit package products\n'

if ! rg -q "project.new_target\(:application, 'SHOSLite', :ios, '16\\.0'\)" scripts/gen-xcode-project.rb ||
   ! rg -q 'NO_LINUX_GUEST' DSH.xcodeproj/project.pbxproj; then
  echo 'not ok: missing iOS 16 NO_LINUX_GUEST application target' >&2
  exit 1
fi

lite_target=$(ruby -rxcodeproj -e '
  project = Xcodeproj::Project.open("DSH.xcodeproj")
  target = project.targets.find { |value| value.name == "SHOSLite" } or abort "missing SHOSLite"
  puts target.source_build_phase.files.map { |file| file.file_ref.real_path }
  puts target.resources_build_phase.files.map { |file| file.file_ref.real_path }
  puts target.package_product_dependencies.map(&:product_name)
')
case "$lite_target" in
  *ish-arm64*|*root.tar.gz*|*AgentLinuxGuest*)
    echo 'not ok: SHOSLite includes a Linux guest source, resource, or package' >&2
    exit 1
    ;;
esac
for product in AgentRuntime AgentProviders AgentTools AgentStorage AgentMCP; do
  printf '%s\n' "$lite_target" | rg -q "^${product}$" || {
    echo "not ok: SHOSLite does not link $product" >&2
    exit 1
  }
done

printf 'ok  scripts: NO_LINUX_GUEST product boundary\n'

if ! rg -q "project.new_target\(:application, 'DSH', :ios, '16\\.0'\)" scripts/gen-xcode-project.rb ||
   ! rg -q '^IPHONEOS_DEPLOYMENT_TARGET = 16\.0$' app/AppDSH.xcconfig; then
  echo 'not ok: the SHOS application target must support iOS 16' >&2
  exit 1
fi

if rg -q '^import Observation$|@Observable|@ObservationIgnored' app; then
  echo 'not ok: SHOS app state uses Observation APIs unavailable on iOS 16' >&2
  exit 1
fi

printf 'ok  scripts: SHOS iOS 16 compatibility boundary\n'
