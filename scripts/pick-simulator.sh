#!/usr/bin/env bash
# Prints the name of an available iPad simulator (falls back to any iPhone), so
# CI does not hard-code a device that a given Xcode image may not ship.
set -euo pipefail
if [ -n "${DSH_SIMULATOR_LIST_FILE:-}" ]; then
    list=$(<"$DSH_SIMULATOR_LIST_FILE")
else
    list=$(xcrun simctl list devices available)
fi
# Capture everything before the UUID rather than stopping at the first "(";
# current runtimes include model names such as "iPad Pro 13-inch (M5)".
name=$(printf '%s\n' "$list" | sed -En 's/^ *(iPad.*) \([0-9A-Fa-f-]{36}\) \((Booted|Shutdown)\)[[:space:]]*$/\1/p' | head -1)
[ -z "$name" ] && name=$(printf '%s\n' "$list" | sed -En 's/^ *(iPhone.*) \([0-9A-Fa-f-]{36}\) \((Booted|Shutdown)\)[[:space:]]*$/\1/p' | head -1)
[ -z "$name" ] && { echo "no available simulator" >&2; exit 1; }
printf '%s\n' "$name"
