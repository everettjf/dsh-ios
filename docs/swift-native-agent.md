# Swift-native agent architecture

## Ownership boundary

The iOS process owns model transport, SSE decoding, step orchestration,
conversation persistence, context selection, attachments, permissions, native
tools, MCP, telemetry, and UI. This is the normal execution path.

The Linux guest owns only Linux-specific work. `DSHLazyGuestManager` coalesces
startup and is first touched by a confirmed shell command or attachment-staging
tool. `DSHNativeRootFactory` creates the primary scene without waiting for the
guest or loading a WebView.

## Runtime flow

1. Persist the user message and attachment references in a native session.
2. Select complete recent turns within the bounded context budget.
3. Stream OpenAI-compatible chat-completion SSE events.
4. Publish reasoning/content deltas at no more than 30 Hz.
5. Assemble, validate, govern, audit, and execute tool calls.
6. Keep native and MCP tools in-process; cross the lazy boundary for Linux tools.
7. Persist terminal, cancellation, usage, and error state immediately.

## Storage and privacy

- API and MCP tokens: Keychain.
- Native conversations and attachment metadata: Application Support.
- Imported bytes: per-session workspace directories.
- Legacy files: retained inside the guest root across image upgrades.
- Activity: bounded lifecycle metadata without prompt, response, result, URL,
  token, or attachment content.

Native schemas migrate forward. Legacy `dsh web` sessions remain guest data and
are not synthesized into native records.

## Supported compatibility surface

- DeepSeek's OpenAI-compatible chat-completions streaming protocol.
- Built-in governed native tools.
- MCP `2025-11-25` over HTTPS, plus loopback HTTP.
- Confirmed shell commands and attachment staging in the bundled Linux guest.

The old web UI and arbitrary dsh plugins are not compatibility contracts.
