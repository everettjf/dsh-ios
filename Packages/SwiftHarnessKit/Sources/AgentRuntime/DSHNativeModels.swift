import Foundation

public enum DSHJSONValue: Codable, Equatable, Sendable {
    case null
    case bool(Bool)
    case number(Double)
    case string(String)
    case array([DSHJSONValue])
    case object([String: DSHJSONValue])

    public init(from decoder: Decoder) throws {
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

    public func encode(to encoder: Encoder) throws {
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

public enum DSHMessageRole: String, Codable, Sendable {
    case system
    case user
    case assistant
    case tool
}

public struct DSHAttachment: Codable, Equatable, Identifiable, Sendable {
    public let id: UUID
    public let name: String
    public let mediaType: String
    public let byteCount: Int
    public let createdAt: Date
    public let extractedText: String?

    public init(
        id: UUID = UUID(),
        name: String,
        mediaType: String,
        byteCount: Int,
        createdAt: Date = Date(),
        extractedText: String? = nil
    ) {
        self.id = id
        self.name = name
        self.mediaType = mediaType
        self.byteCount = byteCount
        self.createdAt = createdAt
        self.extractedText = extractedText
    }
}

public struct DSHToolCall: Codable, Equatable, Identifiable, Sendable {
    public let id: String
    public let name: String
    public let arguments: String

    public init(id: String, name: String, arguments: String) {
        self.id = id
        self.name = name
        self.arguments = arguments
    }
}

public struct DSHChatMessage: Codable, Equatable, Identifiable, Sendable {
    public let id: UUID
    public let role: DSHMessageRole
    public var content: String?
    public var reasoningContent: String?
    public var toolCalls: [DSHToolCall]
    public var toolCallID: String?
    public var attachments: [DSHAttachment]

    public init(
        id: UUID = UUID(),
        role: DSHMessageRole,
        content: String? = nil,
        reasoningContent: String? = nil,
        toolCalls: [DSHToolCall] = [],
        toolCallID: String? = nil,
        attachments: [DSHAttachment] = []
    ) {
        self.id = id
        self.role = role
        self.content = content
        self.reasoningContent = reasoningContent
        self.toolCalls = toolCalls
        self.toolCallID = toolCallID
        self.attachments = attachments
    }

    private enum CodingKeys: String, CodingKey {
        case id, role, content, reasoningContent, toolCalls, toolCallID, attachments
    }

    public init(from decoder: Decoder) throws {
        let values = try decoder.container(keyedBy: CodingKeys.self)
        id = try values.decode(UUID.self, forKey: .id)
        role = try values.decode(DSHMessageRole.self, forKey: .role)
        content = try values.decodeIfPresent(String.self, forKey: .content)
        reasoningContent = try values.decodeIfPresent(String.self, forKey: .reasoningContent)
        toolCalls = try values.decodeIfPresent([DSHToolCall].self, forKey: .toolCalls) ?? []
        toolCallID = try values.decodeIfPresent(String.self, forKey: .toolCallID)
        attachments = try values.decodeIfPresent([DSHAttachment].self, forKey: .attachments) ?? []
    }
}

public struct DSHToolDefinition: Codable, Equatable, Sendable {
    public let name: String
    public let description: String
    public let parameters: DSHJSONValue

    public init(name: String, description: String, parameters: DSHJSONValue) {
        self.name = name
        self.description = description
        self.parameters = parameters
    }
}

public struct DSHCompletionRequest: Equatable, Sendable {
    public let model: String
    public let messages: [DSHChatMessage]
    public let tools: [DSHToolDefinition]
    public let temperature: Double?

    public init(
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

public enum DSHFinishReason: String, Codable, Equatable, Sendable {
    case stop
    case toolCalls = "tool_calls"
    case length
    case contentFilter = "content_filter"
    case unknown
}

public struct DSHTokenUsage: Codable, Equatable, Sendable {
    public let promptTokens: Int
    public let completionTokens: Int
    public let totalTokens: Int

    public init(promptTokens: Int, completionTokens: Int, totalTokens: Int) {
        self.promptTokens = promptTokens
        self.completionTokens = completionTokens
        self.totalTokens = totalTokens
    }
}

public struct DSHToolCallDelta: Equatable, Sendable {
    public let index: Int
    public let id: String?
    public let name: String?
    public let arguments: String?

    public init(index: Int, id: String?, name: String?, arguments: String?) {
        self.index = index
        self.id = id
        self.name = name
        self.arguments = arguments
    }
}

public enum DSHModelEvent: Equatable, Sendable {
    case reasoningDelta(String)
    case contentDelta(String)
    case toolCallDelta(DSHToolCallDelta)
    case usage(DSHTokenUsage)
    case completed(DSHFinishReason)
}

public protocol DSHModelClient: Sendable {
    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error>
}

/// Lets providers expose a stable, privacy-safe error category without making
/// AgentRuntime depend on a concrete transport implementation.
public protocol DSHAgentErrorCategorizing: Error {
    var agentErrorCategory: String { get }
}
