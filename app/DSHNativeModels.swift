import Foundation

enum DSHJSONValue: Codable, Equatable, Sendable {
    case null
    case bool(Bool)
    case number(Double)
    case string(String)
    case array([DSHJSONValue])
    case object([String: DSHJSONValue])

    init(from decoder: Decoder) throws {
        let container = try decoder.singleValueContainer()
        if container.decodeNil() {
            self = .null
        } else if let value = try? container.decode(Bool.self) {
            self = .bool(value)
        } else if let value = try? container.decode(Double.self) {
            self = .number(value)
        } else if let value = try? container.decode(String.self) {
            self = .string(value)
        } else if let value = try? container.decode([DSHJSONValue].self) {
            self = .array(value)
        } else {
            self = .object(try container.decode([String: DSHJSONValue].self))
        }
    }

    func encode(to encoder: Encoder) throws {
        var container = encoder.singleValueContainer()
        switch self {
        case .null: try container.encodeNil()
        case .bool(let value): try container.encode(value)
        case .number(let value): try container.encode(value)
        case .string(let value): try container.encode(value)
        case .array(let value): try container.encode(value)
        case .object(let value): try container.encode(value)
        }
    }
}

enum DSHMessageRole: String, Codable, Sendable {
    case system
    case user
    case assistant
    case tool
}

struct DSHToolCall: Codable, Equatable, Identifiable, Sendable {
    let id: String
    let name: String
    let arguments: String
}

struct DSHChatMessage: Codable, Equatable, Identifiable, Sendable {
    let id: UUID
    let role: DSHMessageRole
    var content: String?
    var reasoningContent: String?
    var toolCalls: [DSHToolCall]
    var toolCallID: String?

    init(
        id: UUID = UUID(),
        role: DSHMessageRole,
        content: String? = nil,
        reasoningContent: String? = nil,
        toolCalls: [DSHToolCall] = [],
        toolCallID: String? = nil
    ) {
        self.id = id
        self.role = role
        self.content = content
        self.reasoningContent = reasoningContent
        self.toolCalls = toolCalls
        self.toolCallID = toolCallID
    }
}

struct DSHToolDefinition: Codable, Equatable, Sendable {
    let name: String
    let description: String
    let parameters: DSHJSONValue
}

struct DSHCompletionRequest: Equatable, Sendable {
    let model: String
    let messages: [DSHChatMessage]
    let tools: [DSHToolDefinition]
    let temperature: Double?

    init(
        model: String,
        messages: [DSHChatMessage],
        tools: [DSHToolDefinition] = [],
        temperature: Double? = nil
    ) {
        self.model = model
        self.messages = messages
        self.tools = tools
        self.temperature = temperature
    }
}

enum DSHFinishReason: String, Codable, Equatable, Sendable {
    case stop
    case toolCalls = "tool_calls"
    case length
    case contentFilter = "content_filter"
    case unknown
}

struct DSHTokenUsage: Codable, Equatable, Sendable {
    let promptTokens: Int
    let completionTokens: Int
    let totalTokens: Int
}

struct DSHToolCallDelta: Equatable, Sendable {
    let index: Int
    let id: String?
    let name: String?
    let arguments: String?
}

enum DSHModelEvent: Equatable, Sendable {
    case reasoningDelta(String)
    case contentDelta(String)
    case toolCallDelta(DSHToolCallDelta)
    case usage(DSHTokenUsage)
    case completed(DSHFinishReason)
}

protocol DSHModelClient: Sendable {
    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error>
}
