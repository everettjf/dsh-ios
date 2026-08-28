import Foundation

enum DSHToolError: Error, LocalizedError, Equatable, Sendable {
    case unknownTool(String)
    case invalidArguments(String)
    case disabled(String)
    case permissionDenied(String)
    case executionFailed(String)
    case stepLimitExceeded

    var errorDescription: String? {
        switch self {
        case .unknownTool(let name): return "Unknown tool: \(name)"
        case .invalidArguments(let message): return "Invalid tool arguments: \(message)"
        case .disabled(let message): return message
        case .permissionDenied(let message): return message
        case .executionFailed(let message): return message
        case .stepLimitExceeded: return "The agent exceeded the tool step limit."
        }
    }
}

protocol DSHNativeTool: Sendable {
    var definition: DSHToolDefinition { get }
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue
}

final class DSHToolRegistry: @unchecked Sendable {
    private let lock = NSLock()
    private var tools: [String: any DSHNativeTool]

    init(_ tools: [any DSHNativeTool] = []) {
        self.tools = Dictionary(uniqueKeysWithValues: tools.map { ($0.definition.name, $0) })
    }

    var definitions: [DSHToolDefinition] {
        lock.withLock { tools.values.map(\.definition).sorted { $0.name < $1.name } }
    }

    func replaceTools(withPrefix prefix: String, with replacements: [any DSHNativeTool]) {
        lock.withLock {
            tools = tools.filter { !$0.key.hasPrefix(prefix) }
            for tool in replacements { tools[tool.definition.name] = tool }
        }
    }

    func execute(_ call: DSHToolCall) async -> String {
        let tool = lock.withLock { tools[call.name] }
        guard let tool else {
            return encodeError(DSHToolError.unknownTool(call.name))
        }
        do {
            let arguments: DSHJSONValue
            if call.arguments.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
                arguments = .object([:])
            } else {
                guard let data = call.arguments.data(using: .utf8) else {
                    throw DSHToolError.invalidArguments("Arguments are not UTF-8.")
                }
                do {
                    arguments = try JSONDecoder().decode(DSHJSONValue.self, from: data)
                } catch {
                    throw DSHToolError.invalidArguments("Expected a JSON value.")
                }
            }
            return encode(["ok": .bool(true), "result": try await tool.execute(arguments: arguments)])
        } catch {
            return encodeError(error)
        }
    }

    private func encodeError(_ error: Error) -> String {
        encode(["ok": .bool(false), "error": .string(error.localizedDescription)])
    }

    private func encode(_ object: [String: DSHJSONValue]) -> String {
        guard let data = try? JSONEncoder().encode(DSHJSONValue.object(object)) else {
            return "{\"ok\":false,\"error\":\"Could not encode tool result.\"}"
        }
        return String(decoding: data, as: UTF8.self)
    }
}
