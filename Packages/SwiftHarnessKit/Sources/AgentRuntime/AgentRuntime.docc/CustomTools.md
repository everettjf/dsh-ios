# Create a custom tool

Import `AgentTools`, conform a value to `AgentTool`, and register it with a
`ToolRegistry`.

```swift
import AgentRuntime
import AgentTools

struct EchoTool: AgentTool {
    let definition = ToolDefinition(
        name: "echo",
        description: "Return text unchanged.",
        parameters: .object(["type": .string("object")])
    )

    func execute(arguments: JSONValue) async throws -> JSONValue {
        arguments
    }
}

let tools = ToolRegistry([EchoTool()])
```

Wrap tools that perform sensitive operations in `GovernedTool` and let the host
own the permission prompt and audit sink.
