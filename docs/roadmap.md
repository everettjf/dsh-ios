# Swift-native agent delivery plan

The Swift-native transition is implemented as a forward-only product change.
The primary app no longer depends on booting `dsh web`; Linux is an optional,
lazy workspace capability.

| Phase | Delivered |
|---|---|
| 0–5 | Native shell, DeepSeek SSE, turn runtime, conversations, SwiftUI, lazy guest boundary |
| 6 | Governed native iOS read/write tools and per-call confirmations |
| 7 | Configurable dynamic MCP servers with Keychain credentials |
| 8 | Durable sessions, schema migration, retry, continuation, cancellation and recovery |
| 9 | Native attachments, isolation, quotas and lazy guest staging |
| 10 | Private activity telemetry, categorized errors and redacted export |
| 11 | 30 Hz streaming publication, 10,000-delta stress and 100-turn context test |
| 12 | Forward-only compatibility contract, in-product notice and release acceptance |

## Product decisions

- Swift owns latency-sensitive and user-facing agent behavior.
- Linux starts only for shell, staging, or Linux-only tools.
- Existing guest data is retained, but legacy web conversations are not
  imported into the native conversation store.
- Arbitrary dsh plugin compatibility is not promised. Native tools and MCP are
  the supported extension mechanisms.
- There is no rollback migration. Native storage schemas migrate forward.

Future work is incremental: real-device beta feedback, additional native tools,
MCP interoperability fixtures, Instruments energy traces on shipping hardware,
localization, deterministic Xcode project generation (the current generator
rewrites object IDs), and App Store presentation. None reintroduces the old
WebView runtime as the primary product.
