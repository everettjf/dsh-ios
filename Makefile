# DSH — DeepSeek Harness for iPad/iPhone
#
#   make emulator      build the iSH-ARM64 CLI (needed by rootfs + tests)
#   make rootfs        build build/root.tar.gz (Alpine + Node 22 + dsh)
#   make project       (re)generate DSH.xcodeproj (run after adding/removing source files)
#   make app           signed device build (DSH.app)
#   make install       build + install on the connected iPad (DEVICE=<udid>)
#   make run           install + launch
#   make test          everything that runs unattended on this Mac:
#                        emulator tests, rootfs tests, XCTest unit+UI on the simulator
#   make test-device   unit + UI tests on the connected device
#   make archive       .xcarchive for distribution
#   make release       bump the patch version, test, archive, upload to TestFlight
#
# Variables: TEAM (Apple developer team id), DEVICE (udid), SIM (simulator name)

ISH_SRC   ?= $(CURDIR)/ish-arm64
ISH_BUILD ?= $(ISH_SRC)/build-arm64-release
PROJECT   ?= $(CURDIR)/DSH.xcodeproj
SCHEME    ?= DSH
TEAM      ?= YPV49M8592
DEVICE    ?=                       # udid of the connected device (xcrun devicectl list devices)
SIM       ?= iPad Air 11-inch (M4)
BUNDLE_ID ?= com.xnuapp.dsh
XCB        = xcodebuild -project $(PROJECT) -scheme $(SCHEME) -configuration Release DSH_DEVELOPMENT_TEAM=$(TEAM)
DERIVED    = $(shell ls -dt ~/Library/Developer/Xcode/DerivedData/DSH-*/Build/Products 2>/dev/null | head -1)

.PHONY: all emulator rootfs project app app-lite test-lite install run test test-package test-emu test-rootfs test-sim test-device test-device-unit archive release clean

all: emulator rootfs project app

# libapps and libarchive are vendored (they were submodules upstream), so there
# is nothing to fetch — a fresh clone can build straight away.
emulator:
	@command -v ld.lld >/dev/null || { \
	    echo "error: ld.lld not found — the guest VDSO needs LLVM's linker."; \
	    echo "       brew install lld   (and make sure its bin directory is on PATH)"; \
	    exit 1; }
	cd $(ISH_SRC) && { [ -d build-arm64-release ] || meson setup build-arm64-release -Dguest_arch=arm64 --buildtype=release; }
	ninja -C $(ISH_BUILD)

rootfs: emulator
	scripts/build-rootfs.sh

project:
	ruby scripts/gen-xcode-project.rb

app: project
	$(XCB) -destination 'generic/platform=iOS' build

# Pure Swift product variant: no iSH sources, rootfs, bash, or Linux staging.
app-lite: project
	xcodebuild -project $(PROJECT) -scheme DashrosLite -configuration Release -destination 'generic/platform=iOS' DSH_DEVELOPMENT_TEAM=$(TEAM) build

test-lite: project
	xcodebuild -project $(PROJECT) -scheme DashrosLite -configuration Release -destination 'generic/platform=iOS Simulator' -derivedDataPath build/lite-derived CODE_SIGNING_ALLOWED=NO build
	tests/verify-lite-bundle.sh build/lite-derived/Build/Products/Release-iphonesimulator/DashrosLite.app

install: app
	xcrun devicectl device install app --device $(DEVICE) "$(DERIVED)/Release-iphoneos/DSH.app"

run: install
	xcrun devicectl device process launch --device $(DEVICE) --terminate-existing $(BUNDLE_ID)

test: test-package test-emu test-rootfs test-sim

test-package:
	swift test --package-path Packages/SwiftHarnessKit

test-emu: emulator
	tests/emu-test.sh
	tests/scripts-test.sh

test-rootfs: emulator
	tests/rootfs-test.sh

# SIM may name any installed simulator; `make test-sim SIM="$$(scripts/pick-simulator.sh)"`
# picks one that exists on this machine (used by CI).
test-sim: project
	rm -rf build/test-sim.xcresult
	-xcrun simctl boot "$(SIM)" 2>/dev/null
	-xcrun simctl uninstall "$(SIM)" $(BUNDLE_ID) 2>/dev/null   # start from a fresh rootfs import
	$(XCB) -destination 'platform=iOS Simulator,name=$(SIM)' -collect-test-diagnostics never -resultBundlePath build/test-sim.xcresult test

test-device: project
	rm -rf build/test-device.xcresult
	$(XCB) -destination 'id=$(DEVICE)' -collect-test-diagnostics never -resultBundlePath build/test-device.xcresult test

# Unit + guest-integration tests only (no UI automation needed on the device).
test-device-unit: project
	rm -rf build/test-device-unit.xcresult
	$(XCB) -destination 'id=$(DEVICE)' -collect-test-diagnostics never -only-testing:DSHTests -resultBundlePath build/test-device-unit.xcresult test

archive: project
	$(XCB) -destination 'generic/platform=iOS' -archivePath build/DSH.xcarchive archive

# Needs APPLE_ID, APPLE_SPECIFIC_PASSWORD and APPLE_TEAM_ID in the environment.
# Pass arguments through: make release ARGS=--dry-run
release:
	./scripts/release.sh $(ARGS)

clean:
	rm -rf build/rootfs-work build/rootfs-test build/emu-test build/*.xcresult
