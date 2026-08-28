# Swift Harness Kit

Swift Harness Kit is the reusable, Swift-native agent framework incubated by
SHOS. The package currently exposes seven products:

- `AgentRuntime`: model-neutral messages, tool contracts, bounded multi-step
  execution, cancellation, retry, continuation and observable snapshots.
- `AgentProviders`: DeepSeek/OpenAI-compatible streaming transport and SSE.
- `AgentTools`: reusable tool registry, invocation and governance contracts.
- `AgentStorage`: native conversation and attachment persistence.
- `AgentAppleTools`: host-independent schemas, validation and route contracts
  for Apple-native tools; the host retains system frameworks and permission UI.
- `AgentMCP`: Model Context Protocol client integration.
- `AgentLinuxGuest`: host-neutral contracts for an optional Linux execution
  backend.

```swift
import AgentRuntime
import AgentProviders

let provider = OpenAICompatibleProvider(
    baseURL: URL(string: "https://api.deepseek.com/v1")!,
    apiKey: key
)
let agent = HarnessAgent(client: provider, model: "deepseek-chat")
let result = try await agent.send("Hello")
```

Version `0.1.0` introduces the supported unprefixed API vocabulary. The original
`DSH*` declarations remain source-compatible throughout the 0.x migration, but
new hosts should use the names shown above. See [API evolution](API_EVOLUTION.md)
for the compatibility and persistence policy.

Run the package suite independently of Xcode and iSH:

```bash
swift test --package-path Packages/SwiftHarnessKit
```

The package does not embed the GPL iSH/Alpine runtime. SHOS explicitly mounts
iSH64 as an optional, separately licensed `AgentLinuxGuest` execution backend;
third-party hosts can omit it or supply another backend.

An independent iOS 16 reference host is available in
[`Examples/HarnessChat`](../../Examples/HarnessChat). It demonstrates streaming,
cancellation, storage, a custom tool, and Apple-tool provider injection without
linking SHOS or iSH64. Build it with `make test-example` from the repository root.
