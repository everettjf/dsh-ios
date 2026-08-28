import Foundation
import MCP
#if canImport(AgentRuntime)
import AgentRuntime
#endif
#if canImport(AgentProviders)
import AgentProviders
#endif
#if canImport(AgentTools)
import AgentTools
#endif

public enum DSHMCPError: Error, LocalizedError, Equatable, Sendable, DSHAgentErrorCategorizing {
    case invalidResponse
    case httpStatus(Int)
    case protocolError(Int, String)
    case unsupportedProtocol(String)
    case notInitialized
    case sdkFailure

    public var errorDescription: String? {
        switch self {
        case .invalidResponse: return "The MCP server returned an invalid response."
        case .httpStatus(let status): return "The MCP server returned HTTP \(status)."
        case .protocolError(let code, let message): return "MCP error \(code): \(message)"
        case .unsupportedProtocol(let version): return "Unsupported MCP protocol version: \(version)"
        case .notInitialized: return "The MCP connection has not been initialized."
        case .sdkFailure: return "The MCP SDK could not complete the request."
        }
    }

    public var agentErrorCategory: String { "mcp_error" }
}

public protocol DSHMCPTransport: Sendable {
    func send(_ request: URLRequest) async throws -> (Data, HTTPURLResponse)
}

public struct DSHURLSessionMCPTransport: DSHMCPTransport {
    let session: URLSession
    public init(session: URLSession? = nil) {
        if let session {
            self.session = session
        } else {
            let configuration = URLSessionConfiguration.ephemeral
            configuration.timeoutIntervalForRequest = 15
            configuration.timeoutIntervalForResource = 30
            self.session = URLSession(configuration: configuration)
        }
    }

    public func send(_ request: URLRequest) async throws -> (Data, HTTPURLResponse) {
        let (data, response) = try await session.data(for: request)
        guard let response = response as? HTTPURLResponse else { throw DSHMCPError.invalidResponse }
        return (data, response)
    }
}

public struct DSHMCPToolDescription: Equatable, Sendable {
    public let name: String
    public let description: String
    public let inputSchema: DSHJSONValue

    public init(name: String, description: String, inputSchema: DSHJSONValue) {
        self.name = name
        self.description = description
        self.inputSchema = inputSchema
    }
}

public actor DSHMCPClient {
    public static let protocolVersion = "2025-11-25"

    private let endpoint: URL
    private let transport: (any DSHMCPTransport)?
    private let headers: [String: String]
    private var officialClient: MCP.Client?
    private var officialTransport: (any MCP.Transport)?
    private let productionHTTP: Bool
    private var sessionID: String?
    private var negotiatedVersion: String?
    private var nextID = 1

    /// Creates the production client backed by the official MCP Swift SDK.
    public init(endpoint: URL, headers: [String: String] = [:]) {
        self.endpoint = endpoint
        self.headers = headers
        transport = nil
        productionHTTP = true
        officialClient = MCP.Client(name: "SHOS", version: "1")
        officialTransport = Self.makeHTTPTransport(endpoint: endpoint, headers: headers)
    }

    /// Test seam for deterministic wire-protocol fixtures. Production callers
    /// use the official-SDK initializer above.
    public init(endpoint: URL, headers: [String: String] = [:], transport: any DSHMCPTransport) {
        self.endpoint = endpoint
        self.headers = headers
        self.transport = transport
        productionHTTP = false
        officialClient = nil
        officialTransport = nil
    }

    init(testingOfficialTransport transport: any MCP.Transport) {
        endpoint = URL(string: "https://in-memory.invalid/mcp")!
        headers = [:]
        self.transport = nil
        productionHTTP = false
        officialClient = MCP.Client(name: "SHOSTests", version: "1")
        officialTransport = transport
    }

    public func connect() async throws {
        if productionHTTP, officialClient == nil {
            officialClient = MCP.Client(name: "SHOS", version: "1")
            officialTransport = Self.makeHTTPTransport(endpoint: endpoint, headers: headers)
        }
        if let officialClient, let officialTransport {
            do {
                let result = try await officialClient.connect(transport: officialTransport)
                negotiatedVersion = result.protocolVersion
                return
            } catch is CancellationError {
                throw CancellationError()
            } catch {
                throw DSHMCPError.sdkFailure
            }
        }
        let result = try await request(
            method: "initialize",
            params: .object([
                "protocolVersion": .string(Self.protocolVersion),
                "capabilities": .object([:]),
                "clientInfo": .object(["name": .string("DSH iOS"), "version": .string("1")])
            ]),
            requiresInitialization: false
        )
        guard case .object(let object) = result,
              case .string(let version) = object["protocolVersion"] else {
            throw DSHMCPError.invalidResponse
        }
        guard version == Self.protocolVersion else { throw DSHMCPError.unsupportedProtocol(version) }
        negotiatedVersion = version
        try await notification(method: "notifications/initialized")
    }

    public func listTools() async throws -> [DSHMCPToolDescription] {
        guard negotiatedVersion != nil else { throw DSHMCPError.notInitialized }
        if let officialClient {
            do {
                var cursor: String?
                var output: [DSHMCPToolDescription] = []
                repeat {
                    let page = try await officialClient.listTools(cursor: cursor)
                    output.append(contentsOf: page.tools.map {
                        .init(
                            name: $0.name,
                            description: $0.description ?? "",
                            inputSchema: Self.runtimeValue(from: $0.inputSchema)
                        )
                    })
                    cursor = page.nextCursor
                } while cursor != nil
                return output
            } catch is CancellationError {
                throw CancellationError()
            } catch {
                throw DSHMCPError.sdkFailure
            }
        }
        var cursor: String?
        var output: [DSHMCPToolDescription] = []
        repeat {
            let params: DSHJSONValue = cursor.map { .object(["cursor": .string($0)]) } ?? .object([:])
            let result = try await request(method: "tools/list", params: params)
            guard case .object(let object) = result,
                  case .array(let tools) = object["tools"] else { throw DSHMCPError.invalidResponse }
            for value in tools {
                guard case .object(let tool) = value,
                      case .string(let name) = tool["name"],
                      let schema = tool["inputSchema"] else { throw DSHMCPError.invalidResponse }
                let description: String
                if case .string(let value) = tool["description"] { description = value } else { description = "" }
                output.append(.init(name: name, description: description, inputSchema: schema))
            }
            if case .string(let value) = object["nextCursor"] { cursor = value } else { cursor = nil }
        } while cursor != nil
        return output
    }

    public func callTool(name: String, arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard negotiatedVersion != nil else { throw DSHMCPError.notInitialized }
        if let officialClient {
            guard case .object(let arguments) = arguments else { throw DSHMCPError.invalidResponse }
            do {
                let race = DSHCancellationRace<(content: [MCP.Tool.Content], isError: Bool?)>()
                let result = try await race.run {
                    try await officialClient.callTool(
                        name: name,
                        arguments: arguments.mapValues(Self.sdkValue(from:))
                    )
                }
                let content = try result.content.map { content in
                    try JSONDecoder().decode(
                        DSHJSONValue.self,
                        from: JSONEncoder().encode(content)
                    )
                }
                return .object([
                    "content": .array(content),
                    "isError": result.isError.map(DSHJSONValue.bool) ?? .null
                ])
            } catch let error as DSHMCPError {
                throw error
            } catch is CancellationError {
                throw CancellationError()
            } catch {
                throw DSHMCPError.sdkFailure
            }
        }
        return try await request(
            method: "tools/call",
            params: .object(["name": .string(name), "arguments": arguments])
        )
    }

    public func disconnect() async {
        guard negotiatedVersion != nil else { return }
        if let officialClient {
            await officialClient.disconnect()
            negotiatedVersion = nil
            if productionHTTP {
                self.officialClient = nil
                officialTransport = nil
            }
            return
        }
        if sessionID != nil {
            var request = URLRequest(url: endpoint)
            request.httpMethod = "DELETE"
            for (name, value) in headers { request.setValue(value, forHTTPHeaderField: name) }
            if let sessionID { request.setValue(sessionID, forHTTPHeaderField: "MCP-Session-Id") }
            _ = try? await transport?.send(request)
        }
        sessionID = nil
        negotiatedVersion = nil
    }

    private static func makeHTTPTransport(endpoint: URL, headers: [String: String]) -> MCP.HTTPClientTransport {
        MCP.HTTPClientTransport(
            endpoint: endpoint,
            streaming: true,
            protocolVersion: Self.protocolVersion,
            requestModifier: { request in
                var request = request
                for (name, value) in headers {
                    request.setValue(value, forHTTPHeaderField: name)
                }
                return request
            }
        )
    }

    private func request(
        method: String,
        params: DSHJSONValue,
        requiresInitialization: Bool = true
    ) async throws -> DSHJSONValue {
        if requiresInitialization, negotiatedVersion == nil { throw DSHMCPError.notInitialized }
        let id = nextID
        nextID += 1
        let body: DSHJSONValue = .object([
            "jsonrpc": .string("2.0"),
            "id": .number(Double(id)),
            "method": .string(method),
            "params": params
        ])
        guard let transport else { throw DSHMCPError.invalidResponse }
        let (data, response) = try await transport.send(makeRequest(body: body, notification: false))
        if method == "initialize", let value = response.value(forHTTPHeaderField: "MCP-Session-Id") {
            sessionID = value
        }
        guard (200..<300).contains(response.statusCode) else { throw DSHMCPError.httpStatus(response.statusCode) }
        let payload = try decodePayload(data: data, response: response)
        guard case .object(let object) = payload else { throw DSHMCPError.invalidResponse }
        if case .object(let error) = object["error"],
           case .number(let code) = error["code"],
           case .string(let message) = error["message"] {
            throw DSHMCPError.protocolError(Int(code), message)
        }
        guard let result = object["result"] else { throw DSHMCPError.invalidResponse }
        return result
    }

    private func notification(method: String) async throws {
        let body: DSHJSONValue = .object(["jsonrpc": .string("2.0"), "method": .string(method)])
        guard let transport else { throw DSHMCPError.invalidResponse }
        let (_, response) = try await transport.send(makeRequest(body: body, notification: true))
        guard (200..<300).contains(response.statusCode) else { throw DSHMCPError.httpStatus(response.statusCode) }
    }

    private func makeRequest(body: DSHJSONValue, notification: Bool) -> URLRequest {
        var request = URLRequest(url: endpoint)
        request.httpMethod = "POST"
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.setValue("application/json, text/event-stream", forHTTPHeaderField: "Accept")
        for (name, value) in headers { request.setValue(value, forHTTPHeaderField: name) }
        if let version = negotiatedVersion {
            request.setValue(version, forHTTPHeaderField: "MCP-Protocol-Version")
        }
        if let sessionID { request.setValue(sessionID, forHTTPHeaderField: "MCP-Session-Id") }
        request.httpBody = try? JSONEncoder().encode(body)
        return request
    }

    private func decodePayload(data: Data, response: HTTPURLResponse) throws -> DSHJSONValue {
        if response.value(forHTTPHeaderField: "Content-Type")?.lowercased().contains("text/event-stream") == true {
            var decoder = DSHSSEDecoder()
            guard let payload = try decoder.append(data).last, let payloadData = payload.data(using: .utf8) else {
                throw DSHMCPError.invalidResponse
            }
            return try JSONDecoder().decode(DSHJSONValue.self, from: payloadData)
        }
        return try JSONDecoder().decode(DSHJSONValue.self, from: data)
    }

    private static func runtimeValue(from value: MCP.Value) -> DSHJSONValue {
        switch value {
        case .null: return .null
        case .bool(let value): return .bool(value)
        case .int(let value): return .number(Double(value))
        case .double(let value): return .number(value)
        case .string(let value): return .string(value)
        case .data(let mimeType, let value):
            return .object([
                "mimeType": mimeType.map(DSHJSONValue.string) ?? .null,
                "base64": .string(value.base64EncodedString())
            ])
        case .array(let values): return .array(values.map(runtimeValue(from:)))
        case .object(let values): return .object(values.mapValues(runtimeValue(from:)))
        }
    }

    private static func sdkValue(from value: DSHJSONValue) -> MCP.Value {
        switch value {
        case .null: return .null
        case .bool(let value): return .bool(value)
        case .number(let value):
            return value.rounded() == value ? .int(Int(value)) : .double(value)
        case .string(let value): return .string(value)
        case .array(let values): return .array(values.map(sdkValue(from:)))
        case .object(let values): return .object(values.mapValues(sdkValue(from:)))
        }
    }
}

/// Bridges SDK operations that do not promptly propagate structured
/// cancellation. The first terminal event wins; late SDK results are ignored.
private final class DSHCancellationRace<Value: Sendable>: @unchecked Sendable {
    private let lock = NSLock()
    private var continuation: CheckedContinuation<Value, Error>?
    private var operationTask: Task<Void, Never>?
    private var completed = false
    private var cancelled = false

    func run(
        operation: @escaping @Sendable () async throws -> Value
    ) async throws -> Value {
        try await withTaskCancellationHandler {
            try await withCheckedThrowingContinuation { continuation in
                lock.lock()
                if cancelled {
                    completed = true
                    lock.unlock()
                    continuation.resume(throwing: CancellationError())
                    return
                }
                self.continuation = continuation
                let task = Task { [weak self] in
                    do { self?.finish(.success(try await operation())) }
                    catch { self?.finish(.failure(error)) }
                }
                operationTask = task
                lock.unlock()
            }
        } onCancel: {
            cancel()
        }
    }

    private func cancel() {
        let continuation: CheckedContinuation<Value, Error>?
        let task: Task<Void, Never>?
        lock.lock()
        cancelled = true
        guard !completed else { lock.unlock(); return }
        completed = true
        continuation = self.continuation
        task = operationTask
        self.continuation = nil
        lock.unlock()
        task?.cancel()
        continuation?.resume(throwing: CancellationError())
    }

    private func finish(_ result: Result<Value, Error>) {
        let continuation: CheckedContinuation<Value, Error>?
        lock.lock()
        guard !completed else { lock.unlock(); return }
        completed = true
        continuation = self.continuation
        self.continuation = nil
        lock.unlock()
        continuation?.resume(with: result)
    }
}

public struct DSHMCPTool: DSHNativeTool {
    public let definition: DSHToolDefinition
    private let remoteName: String
    private let client: DSHMCPClient

    public init(serverName: String, description: DSHMCPToolDescription, client: DSHMCPClient) {
        remoteName = description.name
        self.client = client
        definition = .init(
            name: "mcp__\(serverName)__\(description.name)",
            description: description.description,
            parameters: description.inputSchema
        )
    }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        try await client.callTool(name: remoteName, arguments: arguments)
    }
}
