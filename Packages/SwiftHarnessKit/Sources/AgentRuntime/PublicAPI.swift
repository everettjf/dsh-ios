/// A JSON value used by model providers, tools, and persistence adapters.
public typealias JSONValue = DSHJSONValue
public typealias MessageRole = DSHMessageRole
public typealias Attachment = DSHAttachment
public typealias ToolCall = DSHToolCall
public typealias ChatMessage = DSHChatMessage
public typealias ToolDefinition = DSHToolDefinition
public typealias CompletionRequest = DSHCompletionRequest
public typealias FinishReason = DSHFinishReason
public typealias TokenUsage = DSHTokenUsage
public typealias ToolCallDelta = DSHToolCallDelta
public typealias ModelEvent = DSHModelEvent
public typealias ModelProvider = DSHModelClient
public typealias AgentErrorCategorizing = DSHAgentErrorCategorizing
public typealias AgentTelemetry = DSHAgentTelemetry
public typealias NoopAgentTelemetry = DSHNoopAgentTelemetry
public typealias AgentPhase = DSHAgentPhase
public typealias AgentSnapshot = DSHAgentSnapshot
public typealias AgentRuntimeError = DSHAgentRuntimeError
public typealias ContextPolicy = DSHContextPolicy

/// A model-neutral, streaming agent runtime with bounded tool execution.
public typealias HarnessAgent = DSHAgentRuntime
public typealias ToolProviding = DSHToolProviding
