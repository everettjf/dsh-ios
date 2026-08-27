# Swift-native release acceptance

## Product behavior

- Native UI appears without a WebView or guest startup overlay.
- Portrait and landscape keep settings, composer, send, stop, and attachments reachable.
- Settings, sessions, and Activity do not start Linux.
- Shell and attachment staging start Linux once, on demand, after governance.
- Existing guest workspace remains present after image upgrade.
- UI states that legacy web conversations are not imported and arbitrary dsh
  plugins are not guaranteed.

## Agent reliability

- Fragmented SSE, reasoning, content, usage, and tool calls assemble correctly.
- Cancellation retains partial output and differs from timeout/failure.
- Retry does not duplicate the user message; continuation resumes partial work.
- Sessions recover after lifecycle interruption and migrate schema forward.
- Context stays bounded across 100 turns; a 10,000-delta stream loses no data.
- Offline, HTTP, decoding, MCP, tool, permission, and guest failures recover.

## Security and privacy

- Credentials use Keychain and never enter diagnostics.
- Attachments are isolated, limited, pruned, and staged without command bytes.
- Native writes and shell commands require concrete confirmation.
- Remote MCP rejects non-HTTPS endpoints; localhost HTTP remains testable.
- Diagnostic export redacts bearer/API-key-like values and excludes content.

## Final test matrix

- Emulator instruction/process regressions.
- Rootfs self-test and mock DeepSeek/bridge integration.
- Complete `DSHTests` and `DSHUITests` on an iPhone simulator.
- Native launch, compatibility settings, Activity, and landscape on iPad.
- Generated-project check, Release build, `git diff --check`, and secret scan.

Device signing, HealthKit permissions, and App Store/TestFlight validation are
release-operator checks because they require distribution credentials and a
physical device.
