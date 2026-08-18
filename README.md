# dsh-ios

**DeepSeek Harness on iPad & iPhone** — a native iOS app that runs
[DeepSeek Harness](https://github.com/deepseek-ai/deepseek-harness) fully
on-device inside an embedded iSH-ARM64 Linux emulator. No jailbreak, no server.

- **[`dsh-ios/`](dsh-ios/README.md)** — the app: Xcode project, sources, guest-image
  pipeline, tests, docs. Start there.
- **[`ish-arm64/`](ish-arm64/UPSTREAM.md)** — the vendored emulator (fork of
  OpenMinis/ish-arm64 → ish-app/ish) with the fixes DSH needs.
- **[`site/`](site/)** — the project page, published at
  https://everettjf.github.io/dsh-ios/.

![DSH on iPad Air](dsh-ios/docs/screenshots/ipad-air-workspace.png)

License: GPL-3.0 — see [dsh-ios/LICENSE.md](dsh-ios/LICENSE.md).
