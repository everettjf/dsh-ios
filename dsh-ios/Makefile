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
#
# Variables: TEAM (Apple developer team id), DEVICE (udid), SIM (simulator name)

ISH_SRC   ?= $(CURDIR)/../ish-arm64
ISH_BUILD ?= $(ISH_SRC)/build-arm64-release
PROJECT   ?= $(CURDIR)/DSH.xcodeproj
SCHEME    ?= DSH
TEAM      ?= YPV49M8592
DEVICE    ?=                       # udid of the connected device (xcrun devicectl list devices)
SIM       ?= iPad Air 11-inch (M4)
BUNDLE_ID ?= com.xnuapp.dsh
XCB        = xcodebuild -project $(PROJECT) -scheme $(SCHEME) -configuration Release DSH_DEVELOPMENT_TEAM=$(TEAM)
DERIVED    = $(shell ls -d ~/Library/Developer/Xcode/DerivedData/DSH-*/Build/Products 2>/dev/null | head -1)

.PHONY: all emulator rootfs project app install run test test-emu test-rootfs test-sim test-device test-device-unit archive clean

all: emulator rootfs project app

emulator:
	cd $(ISH_SRC) && git submodule update --init deps/libapps deps/libarchive
	cd $(ISH_SRC) && { [ -d build-arm64-release ] || meson setup build-arm64-release -Dguest_arch=arm64 --buildtype=release; }
	ninja -C $(ISH_BUILD)

rootfs: emulator
	scripts/build-rootfs.sh

project:
	ruby scripts/gen-xcode-project.rb

app: project
	$(XCB) -destination 'generic/platform=iOS' build

install: app
	xcrun devicectl device install app --device $(DEVICE) "$(DERIVED)/Release-iphoneos/DSH.app"

run: install
	xcrun devicectl device process launch --device $(DEVICE) --terminate-existing $(BUNDLE_ID)

test: test-emu test-rootfs test-sim

test-emu: emulator
	tests/emu-test.sh

test-rootfs: emulator
	tests/rootfs-test.sh

test-sim: project
	rm -rf build/test-sim.xcresult
	-xcrun simctl boot "$(SIM)" 2>/dev/null
	-xcrun simctl uninstall "$(SIM)" $(BUNDLE_ID) 2>/dev/null   # start from a fresh rootfs import
	$(XCB) -destination 'platform=iOS Simulator,name=$(SIM)' -resultBundlePath build/test-sim.xcresult test

test-device: project
	rm -rf build/test-device.xcresult
	$(XCB) -destination 'id=$(DEVICE)' -resultBundlePath build/test-device.xcresult test

# Unit + guest-integration tests only (no UI automation needed on the device).
test-device-unit: project
	rm -rf build/test-device-unit.xcresult
	$(XCB) -destination 'id=$(DEVICE)' -only-testing:DSHTests -resultBundlePath build/test-device-unit.xcresult test

archive: project
	$(XCB) -destination 'generic/platform=iOS' -archivePath build/DSH.xcarchive archive

clean:
	rm -rf build/rootfs-work build/rootfs-test build/emu-test build/*.xcresult
