import Foundation

enum DSHModelClientError: Error, LocalizedError, Equatable, DSHAgentErrorCategorizing {
    case invalidEndpoint
    case invalidResponse
    case httpStatus(Int, String)
    case malformedEvent

    var errorDescription: String? {
        switch self {
        case .invalidEndpoint: return "The model endpoint is invalid."
        case .invalidResponse: return "The model server returned an invalid response."
        case .httpStatus(let status, let message): return "Model request failed (HTTP \(status)): \(message)"
        case .malformedEvent: return "The model stream contained an invalid event."
        }
    }

    var agentErrorCategory: String {
        switch self {
        case .invalidEndpoint: return "invalid_endpoint"
        case .invalidResponse: return "invalid_response"
        case .httpStatus(let status, _): return "http_\(status)"
        case .malformedEvent: return "malformed_stream"
        }
    }
}

final class DSHOpenAICompatibleClient: DSHModelClient, @unchecked Sendable {
    private let baseURL: URL
    private let apiKey: String
    private let session: URLSession
    private let decoder = JSONDecoder()
    private let encoder = JSONEncoder()

    init(baseURL: URL, apiKey: String, session: URLSession = .shared) {
        self.baseURL = baseURL
        self.apiKey = apiKey
        self.session = session
        decoder.keyDecodingStrategy = .convertFromSnakeCase
        encoder.keyEncodingStrategy = .convertToSnakeCase
    }

    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        AsyncThrowingStream { continuation in
            let task = Task {
                do {
                    let urlRequest = try makeURLRequest(request)
                    let (bytes, response) = try await session.bytes(for: urlRequest)
                    guard let http = response as? HTTPURLResponse else {
                        throw DSHModelClientError.invalidResponse
                    }
                    guard (200..<300).contains(http.statusCode) else {
                        var body = Data()
                        for try await byte in bytes.prefix(64 * 1024) { body.append(byte) }
                        let message = String(data: body, encoding: .utf8) ?? "Unknown error"
                        throw DSHModelClientError.httpStatus(http.statusCode, message)
                    }

                    var sse = DSHSSEDecoder()
                    var chunk = Data()
                    chunk.reserveCapacity(1024)
                    for try await byte in bytes {
                        try Task.checkCancellation()
                        chunk.append(byte)
                        if byte == 0x0A || chunk.count >= 4096 {
                            for payload in try sse.append(chunk) {
                                try emit(payload: payload, to: continuation)
                            }
                            chunk.removeAll(keepingCapacity: true)
                        }
                    }
                    if !chunk.isEmpty {
                        for payload in try sse.append(chunk) {
                            try emit(payload: payload, to: continuation)
                        }
                    }
                    continuation.finish()
                } catch is CancellationError {
                    continuation.finish(throwing: CancellationError())
                } catch {
                    continuation.finish(throwing: error)
                }
            }
            continuation.onTermination = { @Sendable _ in task.cancel() }
        }
    }

    func makeURLRequest(_ request: DSHCompletionRequest) throws -> URLRequest {
        guard let url = URL(string: "chat/completions", relativeTo: normalizedBaseURL()) else {
            throw DSHModelClientError.invalidEndpoint
        }
        var urlRequest = URLRequest(url: url)
        urlRequest.httpMethod = "POST"
        urlRequest.setValue("application/json", forHTTPHeaderField: "Content-Type")
        urlRequest.setValue("text/event-stream", forHTTPHeaderField: "Accept")
        if !apiKey.isEmpty {
            urlRequest.setValue("Bearer \(apiKey)", forHTTPHeaderField: "Authorization")
        }
        urlRequest.httpBody = try encoder.encode(WireRequest(request))
        return urlRequest
    }

    private func normalizedBaseURL() -> URL {
        baseURL.absoluteString.hasSuffix("/") ? baseURL : baseURL.appendingPathComponent("")
    }

    private func emit(
        payload: String,
        to continuation: AsyncThrowingStream<DSHModelEvent, Error>.Continuation
    ) throws {
        if payload == "[DONE]" { return }
        guard let data = payload.data(using: .utf8),
              let chunk = try? decoder.decode(WireChunk.self, from: data) else {
            throw DSHModelClientError.malformedEvent
        }

        if let usage = chunk.usage {
            continuation.yield(.usage(.init(
                promptTokens: usage.promptTokens,
                completionTokens: usage.completionTokens,
                totalTokens: usage.totalTokens
            )))
        }
        for choice in chunk.choices {
            if let reasoning = choice.delta.reasoningContent, !reasoning.isEmpty {
                continuation.yield(.reasoningDelta(reasoning))
            }
            if let content = choice.delta.content, !content.isEmpty {
                continuation.yield(.contentDelta(content))
            }
            for toolCall in choice.delta.toolCalls ?? [] {
                continuation.yield(.toolCallDelta(.init(
                    index: toolCall.index,
                    id: toolCall.id,
                    name: toolCall.function?.name,
                    arguments: toolCall.function?.arguments
                )))
            }
            if let reason = choice.finishReason {
                continuation.yield(.completed(DSHFinishReason(rawValue: reason) ?? .unknown))
            }
        }
    }
}

private struct WireRequest: Encodable {
    let model: String
    let messages: [WireMessage]
    let tools: [WireTool]?
    let temperature: Double?
    let stream = true
    let streamOptions = WireStreamOptions(includeUsage: true)

    init(_ request: DSHCompletionRequest) {
        model = request.model
        messages = request.messages.map(WireMessage.init)
        tools = request.tools.isEmpty ? nil : request.tools.map(WireTool.init)
        temperature = request.temperature
    }
}

private struct WireStreamOptions: Encodable { let includeUsage: Bool }

private struct WireMessage: Encodable {
    let role: DSHMessageRole
    let content: String?
    let reasoningContent: String?
    let toolCalls: [WireOutgoingToolCall]?
    let toolCallID: String?

    init(_ message: DSHChatMessage) {
        role = message.role
        content = message.content
        reasoningContent = message.reasoningContent
        toolCalls = message.toolCalls.isEmpty ? nil : message.toolCalls.map(WireOutgoingToolCall.init)
        toolCallID = message.toolCallID
    }
}

private struct WireOutgoingToolCall: Encodable {
    let id: String
    let type = "function"
    let function: WireOutgoingFunction

    init(_ call: DSHToolCall) {
        id = call.id
        function = .init(name: call.name, arguments: call.arguments)
    }
}

private struct WireOutgoingFunction: Encodable {
    let name: String
    let arguments: String
}

private struct WireTool: Encodable {
    let type = "function"
    let function: WireToolFunction

    init(_ definition: DSHToolDefinition) {
        function = .init(name: definition.name, description: definition.description, parameters: definition.parameters)
    }
}

private struct WireToolFunction: Encodable {
    let name: String
    let description: String
    let parameters: DSHJSONValue
}

private struct WireChunk: Decodable {
    let choices: [WireChoice]
    let usage: WireUsage?
}

private struct WireChoice: Decodable {
    let delta: WireDelta
    let finishReason: String?
}

private struct WireDelta: Decodable {
    let content: String?
    let reasoningContent: String?
    let toolCalls: [WireIncomingToolCall]?
}

private struct WireIncomingToolCall: Decodable {
    let index: Int
    let id: String?
    let function: WireIncomingFunction?
}

private struct WireIncomingFunction: Decodable {
    let name: String?
    let arguments: String?
}

private struct WireUsage: Decodable {
    let promptTokens: Int
    let completionTokens: Int
    let totalTokens: Int
}
