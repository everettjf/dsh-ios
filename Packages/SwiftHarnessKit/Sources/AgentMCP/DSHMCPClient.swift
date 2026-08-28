import Foundation
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

    public var errorDescription: String? {
        switch self {
        case .invalidResponse: return "The MCP server returned an invalid response."
        case .httpStatus(let status): return "The MCP server returned HTTP \(status)."
        case .protocolError(let code, let message): return "MCP error \(code): \(message)"
        case .unsupportedProtocol(let version): return "Unsupported MCP protocol version: \(version)"
        case .notInitialized: return "The MCP connection has not been initialized."
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
    private let transport: any DSHMCPTransport
    private let headers: [String: String]
    private var sessionID: String?
    private var negotiatedVersion: String?
    private var nextID = 1

    public init(endpoint: URL, headers: [String: String] = [:], transport: any DSHMCPTransport = DSHURLSessionMCPTransport()) {
        self.endpoint = endpoint
        self.headers = headers
        self.transport = transport
    }

    public func connect() async throws {
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
        return try await request(
            method: "tools/call",
            params: .object(["name": .string(name), "arguments": arguments])
        )
    }

    public func disconnect() async {
        guard negotiatedVersion != nil else { return }
        if sessionID != nil {
            var request = URLRequest(url: endpoint)
            request.httpMethod = "DELETE"
            for (name, value) in headers { request.setValue(value, forHTTPHeaderField: name) }
            if let sessionID { request.setValue(sessionID, forHTTPHeaderField: "MCP-Session-Id") }
            _ = try? await transport.send(request)
        }
        sessionID = nil
        negotiatedVersion = nil
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
