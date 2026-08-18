# DSH — DeepSeek Harness on iPad & iPhone

**Run [DeepSeek Harness](https://github.com/deepseek-ai/deepseek-harness) (`dsh`)
entirely on your iPad or iPhone — no jailbreak, no server, no Mac in the loop.**

DSH is a native iOS app that embeds the [iSH-ARM64](ish-arm64) userspace
Linux emulator, boots a bundled Alpine Linux image with Node.js 22 and
`@deepseek-ai/dsh`, supervises `dsh web`, and shows the harness's own web UI in
a `WKWebView`. Everything — the agent loop, sessions, tools, the shell — runs
on the device; only the model API calls leave it.

| Real iPad Air (M3, iOS 27) — first launch | Sessions & workspace |
|---|---|
| ![First launch on iPad Air](docs/screenshots/ipad-air-m3-first-launch.png) | ![Workspace on iPad Air](docs/screenshots/ipad-air-workspace.png) |

<sub>Left: the guest booted and DeepSeek Harness is served on 127.0.0.1:3080
(green dot in the DSH bar). Right: a workspace with sessions — the model
picker, the “Guest Ask” permission preset and the rest is the stock dsh web
UI. Bottom: the same app on the iPad simulator.</sub>

<p align="center"><img src="docs/screenshots/simulator-ipad-air-m4.png" width="420" alt="DSH on the iPad Air simulator"></p>

Project page: **https://xnu.app/dsh-ios/** · License **GPL-3.0** (see [License](#license)) · iOS/iPadOS 16+, Apple Silicon
simulators · Status: works end-to-end on device, all test suites green.

---

## Features

- **Fully on-device** — Alpine 3.21 (aarch64) + Node 22 + dsh 0.1 inside the app.
- **Native shell** — `>_` in the DSH bar opens an Alpine terminal in the same
  guest (`apk add`, `npm i -g`, look at `~/.dsh`); the `⋯` menu has Reload,
  Server Log, Restart Harness, Open in Safari, About.
- **Supervised server** — free-port selection, HTTP readiness probe, crash
  restart with back-off, health check when the app returns to the foreground,
  live log tail on the startup overlay.
- **Safe updates** — a new guest image shipped with an app update is imported
  as a fresh root; `~/.dsh` (sessions, credentials, settings) and the
  workspace are migrated automatically.
- **Real LLM streaming under emulation** — Node runs jitless (no WebAssembly),
  so DSH ships a `fetch()` polyfill with proper streaming `Response` bodies;
  the SSE round trip is covered by tests against a mock DeepSeek server.
- **Downloads & files** — session-log exports land in *Files ▸ DSH ▸ Downloads*.
- Keyboard: ⌘R reload, ⇧⌘T terminal.

## Quick start

Prerequisites: macOS on Apple Silicon, Xcode 26/27, `brew install meson ninja`,
Node.js ≥ 20 + npm, the `xcodeproj` Ruby gem (`gem install xcodeproj`, or
CocoaPods), an Apple developer team.

```bash
git clone git@github.com:everettjf/dsh-ios.git && cd dsh-ios
make emulator        # iSH-ARM64 CLI + fakefsify (used to build and test the guest image)
make rootfs          # build/root.tar.gz — Alpine + Node 22 + dsh (~95 MB, ~6 min, needs network)
open DSH.xcodeproj   # pick the DSH scheme and your device, set the team → Run
```

Or from the command line:

```bash
make run TEAM=XXXXXXXXXX DEVICE=<udid>   # build, sign, install, launch on the iPad
```

First launch imports the guest image (~30 s, progress on the overlay); later
launches take a few seconds. When the harness asks for a DeepSeek API key,
paste it or tap *Configure later*; keys are stored by dsh inside the guest.

## How it works

```
┌─ DSH.app ────────────────────────────────────────────────────────┐
│  DSHRootViewController ──► WKWebView ──► http://127.0.0.1:3080    │
│         │                                        ▲                │
│  DSHHarness  (port pick · readiness probe · restart · health)     │
│         │  ISHShellExecutor                      │ loopback       │
│  ┌──────▼──── iSH-ARM64 emulator (Alpine 3.21 aarch64) ───────┐   │
│  │  /usr/local/bin/dsh-serve                                  │   │
│  │    → node --expose-internals @deepseek-ai/dsh web          │   │
│  │        --host 127.0.0.1 --port N  ─────────────────────────┘   │
│  └────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────┘
```

- The guest's sockets are pass-through host sockets, so the loopback port dsh
  listens on is reachable from the app's web view (and Safari).
- `rootfs/overlay` holds the guest entry point `dsh-serve`, the self test, and
  `cordis.patch.yml` — the dsh profile layer that turns off the per-command
  sandbox (the whole guest already *is* the sandbox) and defines the
  `guest-ask` permission preset.
- `scripts/build-rootfs.sh` builds the image **on the Mac inside the same
  emulator**: Alpine minirootfs → `apk add nodejs npm …` → the pinned npm tree
  from `rootfs/staging` (installed on the host for linux/arm64/musl) →
  `node-pty` rebuilt for musl → overlay → exported with `unfakefsify`.
- `DSHRootUpgrader` compares the bundled image's SHA-256 with the imported
  root on every launch and migrates user data when it changes.

### Changes made to the emulator (`ish-arm64`, vendored fork of OpenMinis/ish-arm64)

| Change | Why |
|---|---|
| `FCVTL/FCVTL2`, `FCVTN/FCVTN2`, `FCVTXN/FCVTXN2` and vector fixed-point `SCVTF/UCVTF/FCVTZS/FCVTZU #fbits` gadgets | libvips (used by `sharp`, dsh's image-attachment plugin) traps on them |
| `FMOV (scalar, immediate)` decoder fix | imm8 bit 6 was not inverted for constants such as `2.25` or `31.0` — every guest program computed wrong values |
| `waitpid()` no longer returns `EINTR` when its 1 s bounded wait merely times out | broke gcc/g++ (`failed to get exit status`), node-gyp, anything waiting on a child > 1 s |
| Streaming `fetch()` polyfill (`app/RootfsPatch.bundle`) returning real `Response` objects | LLM streaming (SSE) via undici needs WebAssembly, which jitless V8 lacks |
| `ISHShellExecutor` returns shell exit codes and drains pipes after exit; `ContainerURL()` falls back without an app group; deployment target 15.0 | app integration |

## Tests

```bash
make test               # unattended on this Mac: emulator + rootfs + XCTest/XCUITest on the simulator
make test-device-unit   # unit + guest-integration tests on the connected iPad
make test-device        # + UI tests on the iPad (enable Settings ▸ Developer ▸ UI Automation first)
```

| Suite | Covers | Runs on |
|---|---|---|
| `tests/emu-test.sh` | the new NEON gadgets and the FMOV fix (C test compiled with gcc *inside* the guest), the `waitpid` regression, the fetch polyfill (host node, 11 checks) | macOS |
| `tests/rootfs-test.sh` | imports `root.tar.gz` like the app does, guest self test (node-pty/koffi/ripgrep/sharp), profile patch, **headless LLM round trip through a mock DeepSeek SSE server**, `dsh-serve` reachable over loopback | macOS |
| `DSHTests` (XCTest, hosted in the app) | port allocator, log ring, readiness probe, harness state machine (fake launcher + local HTTP server); guest integration: real server answers, `dsh-selftest`, node/dsh versions, root-image bookkeeping | simulator / device |
| `DSHUITests` (XCUITest) | app boots to the DeepSeek Harness UI, port in the bar, server-log sheet, terminal sheet | simulator / device |

Status: all suites green (`make test`: 3 + 12 + 15 + 3 checks; on the iPad Air
15/15 unit + guest-integration tests). CI: [`.github/workflows/dsh-ios.yml`](.github/workflows/dsh-ios.yml).

## Project layout

```
DSH.xcodeproj   generated Xcode project (targets DSH, DSHTests, DSHUITests; scheme DSH)
app/            Objective-C sources, AppDSH.xcconfig, Info.plist, assets, launch screen, privacy manifest
rootfs/         overlay baked into the guest image + pinned npm manifest (staging/package.json)
scripts/        build-rootfs.sh · gen-xcode-project.rb
tests/          emu-test.sh · rootfs-test.sh · mock-deepseek.mjs · fetch-polyfill-test.mjs
                emu/ (guest C tests) · DSHTests/ · DSHUITests/
docs/           screenshots
build/          generated: root.tar.gz, work dirs, xcresult bundles (git-ignored)
ish-arm64/      the emulator (vendored, see its UPSTREAM.md)
site/           project page (GitHub Pages)
```

`DSH.xcodeproj` is generated by `scripts/gen-xcode-project.rb`
(`make project`); re-run it after adding or removing source files. All build
settings live in `app/AppDSH.xcconfig`.

## Known limitations

- Node runs `--jitless` under emulation: agent turns are noticeably slower than
  on a Mac; heavy tool use (large `npm install`, builds) is slow.
- iOS suspends the app in the background; the harness and its sessions resume
  with the app (the web client reconnects on its own).
- Real-device XCUITest needs *UI Automation* enabled in the iPad's Developer
  settings; everything else runs unattended.
- iPhone works, but the iPad is the primary target.

## Contributing

Issues and pull requests are welcome. Please run `make test` before opening a
PR (needs an Apple Silicon Mac with Xcode); emulator changes should come with
a case in `tests/emu/neon_convert_test.c` or `tests/emu-test.sh`.

## License

**GPL-3.0.** DSH compiles and statically links the GPLv3 iSH / iSH-ARM64
emulator, so the whole app is GPLv3; iSH's additional App Store terms in
[`ish-arm64/LICENSE.IOS`](ish-arm64/LICENSE.IOS) apply as well. Full
text in [LICENSE](LICENSE); third-party notices (libarchive, hterm, DeepSeek
Harness, Alpine packages) in [LICENSE.md](LICENSE.md).

Not affiliated with DeepSeek or the iSH project.
