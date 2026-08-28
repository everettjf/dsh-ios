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

let provider = DSHOpenAICompatibleClient(
    baseURL: URL(string: "https://api.deepseek.com/v1")!,
    apiKey: key
)
let agent = DSHAgentRuntime(client: provider, model: "deepseek-chat")
let result = try await agent.send("Hello")
```

The `DSH` type prefix is retained during the first extraction phase so SHOS
can migrate without a second implementation. A later API stabilization pass
will introduce final unprefixed names with source-compatible deprecations where
appropriate.

Run the package suite independently of Xcode and iSH:

```bash
swift test --package-path Packages/SwiftHarnessKit
```

The package does not embed the GPL iSH/Alpine runtime. SHOS explicitly mounts
iSH64 as an optional, separately licensed `AgentLinuxGuest` execution backend;
third-party hosts can omit it or supply another backend.
