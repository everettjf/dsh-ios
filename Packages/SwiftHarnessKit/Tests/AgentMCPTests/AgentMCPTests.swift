import Foundation
#if canImport(FoundationNetworking)
import FoundationNetworking
#endif
import Testing
@testable import AgentMCP
import AgentRuntime
import MCP

@Suite("AgentMCP", .serialized)
struct AgentMCPTests {
    @Test("production HTTP client interoperates with an independent Node MCP server")
    func nodeHTTPInterop() async throws {
        try await withFixtureServer(
            executable: "node",
            script: "node-server.mjs",
            port: 18_765,
            token: "node-secret"
        ) { endpoint in
            let client = DSHMCPClient(endpoint: endpoint, headers: [
                "Authorization": "Bearer node-secret",
                "X-Test-Server": "node"
            ])
            try await client.connect()
            #expect(try await client.listTools().map(\.name) == ["node_add", "node_wait"])
            let result = try await client.callTool(
                name: "node_add",
                arguments: .object(["a": .number(19), "b": .number(23)])
            )
            #expect(toolText(result) == "42")

            let slowCall = Task {
                try await client.callTool(name: "node_wait", arguments: .object([:]))
            }
            try await Task.sleep(for: .milliseconds(100))
            slowCall.cancel()
            await #expect(throws: CancellationError.self) { try await slowCall.value }
            await client.disconnect()

            // Disconnect invalidates the SDK transport's URLSession. A second
            // connect must create a fresh SDK client/transport pair.
            try await client.connect()
            #expect(try await client.listTools().map(\.name) == ["node_add", "node_wait"])
            await client.disconnect()
        }
    }

    @Test("production HTTP client interoperates with an independent Python MCP server")
    func pythonHTTPInterop() async throws {
        try await withFixtureServer(
            executable: "python3",
            script: "python_server.py",
            port: 18_766,
            token: "python-secret"
        ) { endpoint in
            let client = DSHMCPClient(endpoint: endpoint, headers: [
                "Authorization": "Bearer python-secret",
                "X-Test-Server": "python"
            ])
            try await client.connect()
            #expect(try await client.listTools().map(\.name) == ["python_echo"])
            let result = try await client.callTool(
                name: "python_echo",
                arguments: .object(["text": .string("shos")])
            )
            #expect(toolText(result) == "python:shos")
            await client.disconnect()
        }
    }

    @Test("official MCP SDK interoperates through the AgentMCP adapter")
    func officialSDKRoundTrip() async throws {
        let transports = await MCP.InMemoryTransport.createConnectedPair()
        let server = MCP.Server(
            name: "AgentMCPTests",
            version: "1",
            capabilities: .init(tools: .init())
        )
        await server.withMethodHandler(MCP.ListTools.self) { _ in
            .init(tools: [
                .init(
                    name: "add",
                    description: "Add two integers",
                    inputSchema: .object([
                        "type": .string("object"),
                        "properties": .object([
                            "a": .object(["type": .string("integer")]),
                            "b": .object(["type": .string("integer")])
                        ])
                    ])
                )
            ])
        }
        await server.withMethodHandler(MCP.CallTool.self) { request in
            let a = request.arguments?["a"]?.intValue ?? 0
            let b = request.arguments?["b"]?.intValue ?? 0
            return .init(content: [.text(text: "\(a + b)", annotations: nil, _meta: nil)])
        }
        try await server.start(transport: transports.server)
        let client = DSHMCPClient(testingOfficialTransport: transports.client)

        try await client.connect()
        let tools = try await client.listTools()
        let result = try await client.callTool(
            name: "add",
            arguments: .object(["a": .number(2), "b": .number(3)])
        )

        #expect(tools.map(\.name) == ["add"])
        guard case .object(let resultObject) = result,
              case .array(let content) = resultObject["content"],
              case .object(let first) = content.first else {
            Issue.record("Expected the official SDK tool response envelope")
            return
        }
        #expect(first["text"] == .string("5"))
        await client.disconnect()
        await server.stop()
    }

    @Test("initialization, pagination, and negotiated headers")
    func initializationAndPagination() async throws {
        let endpoint = try #require(URL(string: "https://example.test/mcp"))
        let transport = FakeTransport(responses: [
            .json(200, rpcResult(id: 1, result: .object([
                "protocolVersion": .string(DSHMCPClient.protocolVersion),
                "capabilities": .object(["tools": .object([:])]),
                "serverInfo": .object(["name": .string("test"), "version": .string("1")])
            ])), headers: ["MCP-Session-Id": "session-1"]),
            .empty(202),
            .json(200, rpcResult(id: 2, result: .object([
                "tools": .array([.object([
                    "name": .string("weather"),
                    "description": .string("Get weather"),
                    "inputSchema": .object(["type": .string("object")])
                ])]),
                "nextCursor": .string("page-2")
            ]))),
            .json(200, rpcResult(id: 3, result: .object(["tools": .array([])])))
        ])
        let client = DSHMCPClient(endpoint: endpoint, headers: ["Authorization": "Bearer secret"], transport: transport)

        try await client.connect()
        let tools = try await client.listTools()

        #expect(tools.map(\.name) == ["weather"])
        let requests = await transport.recordedRequests()
        #expect(requests.count == 4)
        #expect(requests[0].value(forHTTPHeaderField: "MCP-Protocol-Version") == nil)
        #expect(requests[0].value(forHTTPHeaderField: "Authorization") == "Bearer secret")
        #expect(requests[1].value(forHTTPHeaderField: "MCP-Session-Id") == "session-1")
        #expect(requests[2].value(forHTTPHeaderField: "MCP-Protocol-Version") == DSHMCPClient.protocolVersion)
        #expect(String(decoding: try #require(requests[3].httpBody), as: UTF8.self).contains("page-2"))
    }

    @Test("SSE tool results are decoded")
    func sseToolResult() async throws {
        let endpoint = try #require(URL(string: "https://example.test/mcp"))
        let transport = FakeTransport(responses: [
            .json(200, rpcResult(id: 1, result: initializationResult())),
            .empty(202),
            .sse(200, rpcResult(id: 2, result: .object([
                "content": .array([.object(["type": .string("text"), "text": .string("sunny")])])
            ])))
        ])
        let client = DSHMCPClient(endpoint: endpoint, transport: transport)
        try await client.connect()

        let result = try await client.callTool(name: "weather", arguments: .object(["city": .string("LA")]))

        guard case .object(let object) = result else {
            Issue.record("Expected an object result")
            return
        }
        #expect(object["content"] != nil)
    }

    @Test("requests before initialization fail deterministically")
    func requiresInitialization() async throws {
        let endpoint = try #require(URL(string: "https://example.test/mcp"))
        let client = DSHMCPClient(endpoint: endpoint, transport: FakeTransport(responses: []))

        await #expect(throws: DSHMCPError.notInitialized) { try await client.listTools() }
        await #expect(throws: DSHMCPError.notInitialized) {
            try await client.callTool(name: "weather", arguments: .object([:]))
        }
    }

    @Test("unsupported protocol versions are rejected")
    func rejectsUnsupportedProtocol() async throws {
        let endpoint = try #require(URL(string: "https://example.test/mcp"))
        let transport = FakeTransport(responses: [
            .json(200, rpcResult(id: 1, result: .object([
                "protocolVersion": .string("1900-01-01"),
                "capabilities": .object([:]),
                "serverInfo": .object(["name": .string("old"), "version": .string("1")])
            ])))
        ])
        let client = DSHMCPClient(endpoint: endpoint, transport: transport)

        await #expect(throws: DSHMCPError.unsupportedProtocol("1900-01-01")) { try await client.connect() }
    }

    @Test("tool adapters use namespaced names")
    func namespacedToolName() async throws {
        let endpoint = try #require(URL(string: "https://example.test/mcp"))
        let client = DSHMCPClient(endpoint: endpoint, transport: FakeTransport(responses: []))
        let tool = DSHMCPTool(
            serverName: "weather-service",
            description: .init(name: "forecast", description: "Forecast", inputSchema: .object(["type": .string("object")])),
            client: client
        )

        #expect(tool.definition.name == "mcp__weather-service__forecast")
    }
}

private func toolText(_ value: DSHJSONValue) -> String? {
    guard case .object(let object) = value,
          case .array(let content) = object["content"],
          case .object(let first) = content.first,
          case .string(let text) = first["text"] else { return nil }
    return text
}

private func withFixtureServer(
    executable: String,
    script: String,
    port: Int,
    token: String,
    operation: (URL) async throws -> Void
) async throws {
    let packageRoot = URL(fileURLWithPath: #filePath)
        .deletingLastPathComponent()
        .deletingLastPathComponent()
        .deletingLastPathComponent()
    let scriptURL = packageRoot.appendingPathComponent("Tests/MCPFixtures/\(script)")
    let process = Process()
    process.executableURL = URL(fileURLWithPath: "/usr/bin/env")
    process.arguments = [executable, scriptURL.path, String(port), token]
    process.standardOutput = Pipe()
    process.standardError = Pipe()
    try process.run()
    defer {
        if process.isRunning { process.terminate() }
        process.waitUntilExit()
    }

    let health = URL(string: "http://127.0.0.1:\(port)/health")!
    var ready = false
    for _ in 0..<50 {
        if let (_, response) = try? await URLSession.shared.data(from: health),
           (response as? HTTPURLResponse)?.statusCode == 200 {
            ready = true
            break
        }
        try await Task.sleep(for: .milliseconds(50))
    }
    guard ready else { throw FixtureServerError.didNotStart(executable) }
    try await operation(URL(string: "http://127.0.0.1:\(port)/mcp")!)
}

private enum FixtureServerError: Error {
    case didNotStart(String)
}

private func initializationResult() -> DSHJSONValue {
    .object([
        "protocolVersion": .string(DSHMCPClient.protocolVersion),
        "capabilities": .object([:]),
        "serverInfo": .object(["name": .string("test"), "version": .string("1")])
    ])
}

private func rpcResult(id: Double, result: DSHJSONValue) -> [String: DSHJSONValue] {
    ["jsonrpc": .string("2.0"), "id": .number(id), "result": result]
}

private struct FakeResponse: Sendable {
    let status: Int
    let data: Data
    let headers: [String: String]

    static func json(_ status: Int, _ object: [String: DSHJSONValue], headers: [String: String] = [:]) -> Self {
        .init(
            status: status,
            data: try! JSONEncoder().encode(DSHJSONValue.object(object)),
            headers: headers.merging(["Content-Type": "application/json"]) { first, _ in first }
        )
    }

    static func sse(_ status: Int, _ object: [String: DSHJSONValue]) -> Self {
        let json = String(decoding: try! JSONEncoder().encode(DSHJSONValue.object(object)), as: UTF8.self)
        return .init(status: status, data: Data("data: \(json)\n\n".utf8), headers: ["Content-Type": "text/event-stream"])
    }

    static func empty(_ status: Int) -> Self { .init(status: status, data: Data(), headers: [:]) }
}

private actor FakeTransport: DSHMCPTransport {
    private var responses: [FakeResponse]
    private var requests: [URLRequest] = []

    init(responses: [FakeResponse]) { self.responses = responses }

    func send(_ request: URLRequest) async throws -> (Data, HTTPURLResponse) {
        requests.append(request)
        let response = responses.removeFirst()
        let http = try #require(HTTPURLResponse(
            url: request.url!,
            statusCode: response.status,
            httpVersion: "HTTP/1.1",
            headerFields: response.headers
        ))
        return (response.data, http)
    }

    func recordedRequests() -> [URLRequest] { requests }
}
