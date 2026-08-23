#!/usr/bin/env bash
#
# Cut a release: bump the version, archive, and upload to App Store Connect.
#
#   scripts/release.sh                 patch bump, test, archive, upload
#   scripts/release.sh --minor         bump the minor component instead
#   scripts/release.sh --build-only    reuse the current version, bump only the build number
#   scripts/release.sh --dry-run       do everything except upload and commit
#   scripts/release.sh --skip-tests    skip the test run (not recommended)
#
# Reads from the environment:
#   APPLE_ID                  Apple account email
#   APPLE_SPECIFIC_PASSWORD   app-specific password (appleid.apple.com ▸ Sign-In and Security)
#   APPLE_TEAM_ID             ten-character team id
#
# The upload lands in App Store Connect and reaches internal TestFlight testers once
# Apple finishes processing it, usually within fifteen minutes. Submitting a build for
# App Store review is deliberately left to the web UI.

set -euo pipefail

cd "$(dirname "$0")/.."

XCCONFIG=app/AppDSH.xcconfig
ARCHIVE=build/DSH.xcarchive
EXPORT_DIR=build/export
SCHEME=DSH

part=patch
dry_run=false
skip_tests=false
build_only=false

while [ $# -gt 0 ]; do
    case "$1" in
        --patch|--minor|--major) part="${1#--}" ;;
        --build-only)            build_only=true ;;
        --dry-run)               dry_run=true ;;
        --skip-tests)            skip_tests=true ;;
        -h|--help)               awk 'NR>1 && /^#/ {sub(/^# ?/, ""); print; next} NR>1 {exit}' "$0"; exit 0 ;;
        *) echo "unknown option: $1 (try --help)" >&2; exit 2 ;;
    esac
    shift
done

die() { echo "error: $*" >&2; exit 1; }
step() { printf '\n\033[1m==> %s\033[0m\n' "$*"; }

# --- preflight ------------------------------------------------------------

step "Checking credentials and working tree"

for var in APPLE_ID APPLE_SPECIFIC_PASSWORD APPLE_TEAM_ID; do
    [ -n "${!var:-}" ] || die "\$$var is not set (it lives in ~/.zshrc; run this from an interactive shell)"
done
[ ${#APPLE_TEAM_ID} -eq 10 ] || die "\$APPLE_TEAM_ID should be ten characters, got '${APPLE_TEAM_ID}'"

if [ -n "$(git status --porcelain)" ]; then
    $dry_run || die "the working tree is dirty; commit or stash first (a release should be reproducible from a commit)"
    echo "  working tree is dirty (allowed under --dry-run)"
fi

free_gb=$(df -g . | awk 'NR==2 {print $4}')
[ "$free_gb" -ge 15 ] || die "only ${free_gb}GB free; an archive needs roughly 10GB and macOS evicts simulator runtimes under pressure"

echo "  Apple ID    ${APPLE_ID}"
echo "  team        ${APPLE_TEAM_ID}"
echo "  disk        ${free_gb}GB free"

# --- version --------------------------------------------------------------

step "Bumping the version"

current=$(sed -n 's/^MARKETING_VERSION = //p' "$XCCONFIG" | tr -d ' ')
build=$(sed -n 's/^CURRENT_PROJECT_VERSION = //p' "$XCCONFIG" | tr -d ' ')
[ -n "$current" ] && [ -n "$build" ] || die "cannot read the version out of $XCCONFIG"

IFS=. read -r major minor patch <<<"$current"
if $build_only; then
    version="$current"
else
    case "$part" in
        patch) patch=$((patch + 1)) ;;
        minor) minor=$((minor + 1)); patch=0 ;;
        major) major=$((major + 1)); minor=0; patch=0 ;;
    esac
    version="${major}.${minor}.${patch}"
fi
next_build=$((build + 1))

# App Store Connect rejects a build number it has already seen for this version,
# so the build number only ever climbs, whether or not the version moved.
sed -i '' "s/^MARKETING_VERSION = .*/MARKETING_VERSION = ${version}/" "$XCCONFIG"
sed -i '' "s/^CURRENT_PROJECT_VERSION = .*/CURRENT_PROJECT_VERSION = ${next_build}/" "$XCCONFIG"

echo "  ${current} (${build})  ->  ${version} (${next_build})"

restore_version() {
    sed -i '' "s/^MARKETING_VERSION = .*/MARKETING_VERSION = ${current}/" "$XCCONFIG"
    sed -i '' "s/^CURRENT_PROJECT_VERSION = .*/CURRENT_PROJECT_VERSION = ${build}/" "$XCCONFIG"
    echo "  version restored to ${current} (${build})"
}
# Anything below this point that fails — including a ^C or a kill, which is how a
# hung device build ends — leaves the tree as it was found.
trap 'restore_version' ERR
trap 'restore_version; exit 130' INT TERM

# --- build ----------------------------------------------------------------

step "Regenerating the project"
ruby scripts/gen-xcode-project.rb >/dev/null

if $skip_tests; then
    echo "  tests skipped"
else
    step "Running tests"
    # The XCTest suites need somewhere to run. Prefer the simulator; fall back to a
    # connected device, because macOS evicts simulator runtimes when the disk fills
    # and a release should not quietly skip its tests over that.
    if xcrun simctl list runtimes 2>/dev/null | grep -q '^iOS '; then
        make test
    elif device=$(xcrun devicectl list devices 2>/dev/null | grep 'connected' \
                    | grep -oE '[0-9A-F]{8}(-[0-9A-F]{4}){3}-[0-9A-F]{12}' | head -1) && [ -n "$device" ]; then
        echo "  no iOS simulator runtime installed; using the connected device $device"
        # A locked device does not fail the build, it stalls it: xcodebuild sits in
        # "Waiting for the destination to become ready" until someone picks the phone up.
        if xcrun devicectl device info lockState --device "$device" 2>/dev/null \
             | grep -q 'passcodeRequired: true'; then
            die "device $device is locked — unlock it and run again (xcodebuild would wait indefinitely)"
        fi
        make test-emu test-rootfs
        make test-device DEVICE="$device"
    else
        die "no simulator runtime and no connected device to test on (xcodebuild -downloadPlatform iOS), or pass --skip-tests"
    fi
fi

step "Archiving"
rm -rf "$ARCHIVE" "$EXPORT_DIR"
xcodebuild -project DSH.xcodeproj -scheme "$SCHEME" -configuration Release \
    DSH_DEVELOPMENT_TEAM="$APPLE_TEAM_ID" \
    -destination 'generic/platform=iOS' \
    -archivePath "$ARCHIVE" archive

plist="$ARCHIVE/Products/Applications/DSH.app/Info.plist"
# Apple's own validator catches these, but only after a ten-minute upload.
for key in NSHealthShareUsageDescription NSHealthUpdateUsageDescription \
           NSCalendarsFullAccessUsageDescription NSRemindersFullAccessUsageDescription \
           NSContactsUsageDescription NSLocationWhenInUseUsageDescription \
           NSLocationAlwaysAndWhenInUseUsageDescription; do
    plutil -extract "$key" raw "$plist" >/dev/null 2>&1 \
        || die "$key is missing from the archived app; App Store validation would reject it"
done
echo "  purpose strings present"

step "Exporting the IPA"
cat > build/ExportOptions.plist <<PLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>method</key><string>app-store-connect</string>
	<key>teamID</key><string>${APPLE_TEAM_ID}</string>
	<key>uploadSymbols</key><true/>
	<key>manageAppVersionAndBuildNumber</key><false/>
</dict>
</plist>
PLIST

xcodebuild -exportArchive -archivePath "$ARCHIVE" \
    -exportOptionsPlist build/ExportOptions.plist \
    -exportPath "$EXPORT_DIR"

ipa=$(ls "$EXPORT_DIR"/*.ipa 2>/dev/null | head -1)
[ -n "$ipa" ] || die "no .ipa in $EXPORT_DIR"
echo "  $(basename "$ipa") ($(du -h "$ipa" | cut -f1))"

# --- upload ---------------------------------------------------------------

step "Validating with App Store Connect"
xcrun altool --validate-app -f "$ipa" -t ios \
    -u "$APPLE_ID" -p "$APPLE_SPECIFIC_PASSWORD"

if $dry_run; then
    trap - ERR INT TERM
    step "Dry run: stopping before upload"
    restore_version
    echo "  the validated build is at $ipa"
    exit 0
fi

step "Uploading to App Store Connect"
xcrun altool --upload-app -f "$ipa" -t ios \
    -u "$APPLE_ID" -p "$APPLE_SPECIFIC_PASSWORD"

trap - ERR INT TERM

# --- record ---------------------------------------------------------------

step "Recording the release"
# The whole generated project, not just the pbxproj: gen-xcode-project.rb rewrites
# the scheme's blueprint identifiers on every run, and a leftover dirty file would
# block the next release at the clean-tree check.
git add "$XCCONFIG" DSH.xcodeproj
git commit -m "Release ${version} (${next_build})"
git tag "v${version}"
echo "  committed and tagged v${version} — 'git push && git push --tags' when ready"

cat <<NOTE

Uploaded ${version} (${next_build}).

Apple processes the build before it shows up anywhere, usually within fifteen
minutes, and emails you either way. Once it lands, internal TestFlight testers
get it automatically; external testers need Beta App Review first.
NOTE
