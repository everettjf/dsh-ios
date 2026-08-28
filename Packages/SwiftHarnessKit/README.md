# Swift Harness Kit

Swift Harness Kit is the internal working name for the reusable, Swift-native
agent runtime incubated by Dashros. The package currently exposes two products:

- `AgentRuntime`: model-neutral messages, tool contracts, bounded multi-step
  execution, cancellation, retry, continuation and observable snapshots.
- `AgentProviders`: DeepSeek/OpenAI-compatible streaming transport and SSE.

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

The `DSH` type prefix is retained during the first extraction phase so Dashros
can migrate without a second implementation. A later API stabilization pass
will introduce final unprefixed names with source-compatible deprecations where
appropriate.

Run the package suite independently of Xcode and iSH:

```bash
swift test --package-path Packages/SwiftHarnessKit
```

The package does not include the GPL iSH/Alpine guest. That remains an optional,
separately licensed execution backend.
