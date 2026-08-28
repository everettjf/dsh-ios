# SHOS — a Swift-native agent for iPhone and iPad

SHOS is a fast, native iOS agent with first-class DeepSeek support. Swift owns the
primary UI, model streaming, turn state machine, conversations, attachments,
permissions, native iOS tools, MCP clients, and private diagnostics.

An Alpine Linux guest remains available for shell commands and Linux tooling,
but starts only when a tool actually needs it. Launching the app, reading a
conversation, editing settings, using native tools, and calling MCP do not boot
Linux. This is a forward-only transition from the earlier `dsh web` app; DSH
does not promise compatibility with every dsh plugin.

> **Repository lines:** `main` retains the Node.js DeepSeek Harness app. The last
> official Node.js implementation before this rewrite is also
> preserved at [`nodejs-harness-v1.0.10`](https://github.com/everettjf/dsh-ios/tree/nodejs-harness-v1.0.10).
> Use that tag when you need the original `dsh web` / Node.js architecture;
> Swift-native SHOS and the internal **Swift Harness Kit** are developed on
> `rewrite-deepseek-harness-with-swift`.

## Product architecture

```text
SHOS (SwiftUI app)
  ├─ Swift Harness Kit
  │   ├─ providers + SSE
  │   ├─ turn/step runtime
  │   ├─ tools, storage and MCP
  │   └─ host-neutral Linux guest contracts
  ├─ native Apple tools, permissions and UI
  └─ AgentLinuxGuest (optional) ── iSH64 / Alpine / shell / staging
```

- The native agent is usable immediately; Linux is not part of app startup.
- Model and MCP credentials are stored in Keychain.
- Conversations and attachments live in Application Support.
- Activity reports contain lifecycle metrics and categorized failures, not
  prompts, model output, tool results, URLs, or credentials. Export applies
  secret redaction again.
- Mutating tools require a concrete confirmation. Native reads remain behind
  their capability switch and the corresponding iOS permission.
- Remote MCP endpoints must use HTTPS; loopback HTTP is allowed for development.

See [Swift-native architecture](docs/swift-native-agent.md), the [SHOS
product plan](docs/shos-product-plan.zh.md), the [Swift Harness Kit
extraction plan](docs/swift-harness-kit-plan.md), and [release
acceptance](docs/release-acceptance.md) for the complete contract.

## Upgrade and compatibility

Upgrades are forward-only; there is no rollback migration.

- Existing Linux guest files, `~/.dsh`, and workspace data are preserved and
  remain reachable through Linux tools.
- Old `dsh web` conversations are not converted into native conversations.
- New native conversations migrate automatically between supported schema versions.
- Arbitrary dsh plugins are not an API contract. Prefer built-in native tools
  or MCP servers. Plugins that depend on the old web runtime may remain usable
  only inside the optional guest when invoked by a supported Linux tool.

## Build and run

Requirements: Apple Silicon Mac, Xcode 27, iOS/iPadOS 16 or later, Node.js 20+,
Meson, Ninja, `lld`, and the Ruby `xcodeproj` gem.

```bash
git clone https://github.com/everettjf/dsh-ios.git
cd dsh-ios
make emulator
make rootfs
open DSH.xcodeproj
```

Select the DSH scheme, configure an Apple development team, and run on an
iPhone, iPad, or simulator. Enter the endpoint, API key, and model in Agent
Settings. Linux remains stopped until it is needed.

## Tests

```bash
make test               # emulator + rootfs + app and UI suites
make test-emu           # emulator and release-script regressions
make test-rootfs        # guest image and mock-model integrations
make test-sim           # XCTest and XCUITest on a simulator
make test-device-unit   # app and guest integration tests on a device
make test-device        # app and UI tests on a device
make test-lite          # build/audit the iOS 16 variant without Linux guest
make test-example       # build the independent HarnessChat public-API host
```

The app suite covers SSE fragmentation, multi-step tools, cancellation, retry,
storage migration, attachment isolation, permissions, dynamic MCP, lazy guest
boot, diagnostics privacy, a 10,000-delta stream, a 100-turn bounded-context
run, and real guest integration. UI tests verify native launch, no primary
WebView, settings, conversations, activity, attachments, landscape, and the
forward-only Linux compatibility notice.

## Repository layout

```text
app/            Swift-native agent plus governed iOS/guest integration
tests/          XCTest, XCUITest, emulator and rootfs integration suites
app-lite/       runnable NO_LINUX_GUEST reference application
rootfs/         optional Alpine guest image overlay
ish-arm64/      vendored userspace emulator
scripts/        project, rootfs, test and release automation
docs/           architecture, security, migration and release acceptance
```

Run `make project` after adding or removing Xcode source files.

SHOS is intentionally an iOS-native agent, not a byte-for-byte Swift
port of the original harness. Its supported extension surface is the native
tool registry plus MCP; Linux is an optional workspace capability.

The project is GPL-3.0 because it includes the iSH-derived emulator. See
[LICENSE](LICENSE).
