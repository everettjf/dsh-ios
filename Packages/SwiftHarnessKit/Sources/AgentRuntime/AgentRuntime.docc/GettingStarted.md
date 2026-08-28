# Getting started

Create a provider and pass it to a harness agent. The provider can come from
`AgentProviders` or be implemented by the host.

```swift
import AgentRuntime
import AgentProviders

let provider = OpenAICompatibleProvider(
    baseURL: URL(string: "https://api.deepseek.com/v1")!,
    apiKey: apiKey
)
let agent = HarnessAgent(client: provider, model: "deepseek-chat")
let snapshot = try await agent.send("Hello")
print(snapshot.messages.last?.content ?? "")
```

Observe `updates()` to render streaming text and tool progress. Cancel the task
that awaits `send(_:)` to cancel the active turn.
