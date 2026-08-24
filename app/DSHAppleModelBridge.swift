import Foundation
import FoundationModels

/// OpenAI-compatible façade over Apple's Private Cloud Compute model. dsh
/// remains responsible for executing tools; this layer only translates the
/// model's structured choice back into an OpenAI assistant/tool-call message.
@objc(DSHAppleModelBridge)
final class DSHAppleModelBridge: NSObject {
    @objc static func registerRoutes() {
        let handler: DSHHostBridgeHandler = { request in
            guard let rawJSON = request.json else {
                return .error(withStatus: 400, code: "invalid_request", message: "body must be JSON", recoverable: false)
            }
            let json = Dictionary(uniqueKeysWithValues: rawJSON.compactMap { key, value in
                (key as? String).map { ($0, value) }
            })

            let semaphore = DispatchSemaphore(value: 0)
            var result: Result<[String: Any], Error>!
            Task {
                do { result = .success(try await complete(json)) }
                catch { result = .failure(error) }
                semaphore.signal()
            }
            guard semaphore.wait(timeout: .now() + 175) == .success else {
                return .error(withStatus: 504, code: "model_timeout", message: "Private Cloud Compute timed out", recoverable: true)
            }

            switch result! {
            case .failure(let error):
                return .error(withStatus: 503, code: "model_unavailable", message: error.localizedDescription, recoverable: true)
            case .success(let answer):
                if (json["stream"] as? Bool) == true {
                    let event = (try? JSONSerialization.data(withJSONObject: answer)) ?? Data()
                    let payload = Data("data: ".utf8) + event + Data("\n\ndata: [DONE]\n\n".utf8)
                    return .status(200, contentType: "text/event-stream", rawBody: payload)
                }
                return .ok(answer)
            }
        }
        DSHHostBridge.shared().registerRoute("POST", path: "/chat/completions", capability: nil, handler: handler)
        DSHHostBridge.shared().registerRoute("POST", path: "/v1/chat/completions", capability: nil, handler: handler)
        DSHHostBridge.shared().registerRoute("GET", path: "/models", capability: nil) { _ in
            .ok(["object": "list", "data": [["id": "apple-pcc", "object": "model"]]])
        }
        DSHHostBridge.shared().registerRoute("GET", path: "/v1/models", capability: nil) { _ in
            .ok(["object": "list", "data": [["id": "apple-pcc", "object": "model"]]])
        }
    }

    @available(iOS 27.0, *)
    private static func completePCC(_ request: [String: Any]) async throws -> [String: Any] {
        let model = PrivateCloudComputeLanguageModel()
        guard model.isAvailable else { throw PCCError.unavailable }

        let messages = request["messages"] as? [[String: Any]] ?? []
        let tools = request["tools"] as? [[String: Any]] ?? []
        let prompt = render(messages: messages, tools: tools)
        let schema = try responseSchema(toolNames: toolNames(from: tools))
        let session = LanguageModelSession(model: model, instructions: "You are the language model inside DeepSeek Harness. Follow the conversation and return either a final assistant answer or exactly one requested tool call. Never invent a tool name. Tool arguments must be a valid JSON object string.")
        let response = try await session.respond(
            to: prompt,
            schema: schema,
            contextOptions: ContextOptions(reasoningLevel: .moderate)
        )
        let object = try JSONSerialization.jsonObject(with: Data(response.rawContent.jsonString.utf8)) as? [String: Any] ?? [:]
        return openAIResponse(from: object)
    }

    private static func complete(_ request: [String: Any]) async throws -> [String: Any] {
        guard #available(iOS 27.0, *) else { throw PCCError.requiresIOS27 }
        return try await completePCC(request)
    }

    @available(iOS 27.0, *)
    private static func responseSchema(toolNames: [String]) throws -> GenerationSchema {
        let kindAnswer = DynamicGenerationSchema(type: String.self, guides: [.constant("answer")])
        let answer = DynamicGenerationSchema(name: "AssistantAnswer", properties: [
            .init(name: "kind", schema: kindAnswer),
            .init(name: "content", description: "The complete answer to the user", schema: .init(type: String.self))
        ])
        guard !toolNames.isEmpty else { return try GenerationSchema(root: answer, dependencies: []) }

        let tool = DynamicGenerationSchema(name: "AssistantToolCall", properties: [
            .init(name: "kind", schema: .init(type: String.self, guides: [.constant("tool_call")])),
            .init(name: "tool_name", description: "One available tool name", schema: .init(name: "ToolName", anyOf: toolNames)),
            .init(name: "arguments", description: "A valid JSON object string matching that tool's parameter schema", schema: .init(type: String.self))
        ])
        return try GenerationSchema(root: .init(name: "AssistantAction", anyOf: [answer, tool]), dependencies: [])
    }

    private static func toolNames(from tools: [[String: Any]]) -> [String] {
        tools.compactMap { ($0["function"] as? [String: Any])?["name"] as? String }
    }

    private static func render(messages: [[String: Any]], tools: [[String: Any]]) -> String {
        var lines = ["CONVERSATION (oldest to newest):"]
        for message in messages {
            let role = message["role"] as? String ?? "unknown"
            if let calls = message["tool_calls"] {
                lines.append("\(role.uppercased()) TOOL CALLS: \(json(calls))")
            }
            lines.append("\(role.uppercased()): \(contentText(message["content"]))")
            if let id = message["tool_call_id"] as? String { lines.append("TOOL CALL ID: \(id)") }
        }
        if !tools.isEmpty {
            lines.append("AVAILABLE TOOLS (name, description, JSON parameter schema):")
            for tool in tools { lines.append(json(tool["function"] ?? tool)) }
        }
        lines.append("Choose a final answer unless a tool is genuinely needed. Return one action in the required schema.")
        return lines.joined(separator: "\n")
    }

    private static func contentText(_ value: Any?) -> String {
        if let text = value as? String { return text }
        return value.map(json) ?? ""
    }

    private static func json(_ value: Any) -> String {
        guard JSONSerialization.isValidJSONObject(value),
              let data = try? JSONSerialization.data(withJSONObject: value),
              let string = String(data: data, encoding: .utf8) else { return String(describing: value) }
        return string
    }

    private static func openAIResponse(from action: [String: Any]) -> [String: Any] {
        let id = "chatcmpl-\(UUID().uuidString)"
        var delta: [String: Any]
        var finish = "stop"
        if action["kind"] as? String == "tool_call", let name = action["tool_name"] as? String {
            finish = "tool_calls"
            delta = ["role": "assistant", "content": NSNull(), "tool_calls": [[
                "index": 0, "id": "call_\(UUID().uuidString)", "type": "function",
                "function": ["name": name, "arguments": action["arguments"] as? String ?? "{}"]
            ]]]
        } else {
            delta = ["role": "assistant", "content": action["content"] as? String ?? ""]
        }
        return ["id": id, "object": "chat.completion.chunk", "created": Int(Date().timeIntervalSince1970),
                "model": "apple-pcc", "choices": [["index": 0, "delta": delta, "finish_reason": finish]]]
    }

    private enum PCCError: LocalizedError {
        case requiresIOS27, unavailable
        var errorDescription: String? {
            switch self {
            case .requiresIOS27: return "Apple Private Cloud Compute requires iOS 27 or later"
            case .unavailable: return "Apple Private Cloud Compute is unavailable on this device, account, or region"
            }
        }
    }
}
