#!/usr/bin/env bash
# Prints the name of an available iPad simulator (falls back to any iPhone), so
# CI does not hard-code a device that a given Xcode image may not ship.
set -euo pipefail
list=$(xcrun simctl list devices available)
name=$(printf '%s\n' "$list" | sed -n 's/^ *\(iPad[^(]*\) (.*/\1/p' | sed 's/ *$//' | head -1)
[ -z "$name" ] && name=$(printf '%s\n' "$list" | sed -n 's/^ *\(iPhone[^(]*\) (.*/\1/p' | sed 's/ *$//' | head -1)
[ -z "$name" ] && { echo "no available simulator" >&2; exit 1; }
printf '%s\n' "$name"
