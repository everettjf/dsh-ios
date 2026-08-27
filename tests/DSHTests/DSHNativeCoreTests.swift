import XCTest
@testable import DSH

final class DSHNativeCoreTests: XCTestCase {
    func testSSEDecoderHandlesFragmentedCRLFAndMultipleEvents() throws {
        var decoder = DSHSSEDecoder()
        XCTAssertEqual(try decoder.append(Data("data: {\"a\":1}\r".utf8)), [])
        XCTAssertEqual(
            try decoder.append(Data("\n\r\ndata: one\ndata: two\n\n".utf8)),
            ["{\"a\":1}", "one\ntwo"]
        )
    }

    func testSSEDecoderIgnoresCommentsAndNonDataFields() throws {
        var decoder = DSHSSEDecoder()
        let events = try decoder.append(Data(": keepalive\nevent: message\ndata: hello\n\n".utf8))
        XCTAssertEqual(events, ["hello"])
    }

    func testCompletionRequestUsesOpenAIWireShape() throws {
        let client = DSHOpenAICompatibleClient(
            baseURL: try XCTUnwrap(URL(string: "https://api.deepseek.com/v1")),
            apiKey: "secret"
        )
        let tool = DSHToolDefinition(
            name: "device_info",
            description: "Read device information",
            parameters: .object(["type": .string("object")])
        )
        let request = try client.makeURLRequest(.init(
            model: "deepseek-chat",
            messages: [.init(role: .user, content: "Hello")],
            tools: [tool]
        ))

        XCTAssertEqual(request.url?.absoluteString, "https://api.deepseek.com/v1/chat/completions")
        XCTAssertEqual(request.value(forHTTPHeaderField: "Authorization"), "Bearer secret")
        let body = try XCTUnwrap(request.httpBody)
        let json = try XCTUnwrap(JSONSerialization.jsonObject(with: body) as? [String: Any])
        XCTAssertEqual(json["model"] as? String, "deepseek-chat")
        XCTAssertEqual(json["stream"] as? Bool, true)
        XCTAssertEqual((json["messages"] as? [[String: Any]])?.first?["role"] as? String, "user")
        XCTAssertEqual((json["tools"] as? [[String: Any]])?.first?["type"] as? String, "function")
    }

    func testJSONValueRoundTripsWithoutLosingStructure() throws {
        let value: DSHJSONValue = .object([
            "enabled": .bool(true),
            "count": .number(3),
            "items": .array([.string("a"), .null])
        ])
        let data = try JSONEncoder().encode(value)
        XCTAssertEqual(try JSONDecoder().decode(DSHJSONValue.self, from: data), value)
    }

    func testAgentRuntimeAccumulatesReasoningContentAndUsage() async throws {
        let usage = DSHTokenUsage(promptTokens: 4, completionTokens: 6, totalTokens: 10)
        let client = ScriptedModelClient(events: [
            .reasoningDelta("think "),
            .reasoningDelta("carefully"),
            .contentDelta("Hello"),
            .contentDelta(" world"),
            .usage(usage),
            .completed(.stop)
        ])
        let runtime = DSHAgentRuntime(client: client, model: "deepseek-chat", systemPrompt: "Be concise")

        let snapshot = try await runtime.send("  Hi  ")

        XCTAssertEqual(snapshot.phase, .completed)
        XCTAssertEqual(snapshot.usage, usage)
        XCTAssertEqual(snapshot.messages.map(\.role), [.user, .assistant])
        XCTAssertEqual(snapshot.messages[0].content, "Hi")
        XCTAssertEqual(snapshot.messages[1].reasoningContent, "think carefully")
        XCTAssertEqual(snapshot.messages[1].content, "Hello world")
        let recordedRequest = await client.lastRequest()
        let request = try XCTUnwrap(recordedRequest)
        XCTAssertEqual(request.messages.map(\.role), [.system, .user])
        XCTAssertEqual(request.messages[0].content, "Be concise")
    }

    func testAgentRuntimeAssemblesFragmentedToolCallsInIndexOrder() async throws {
        let client = ScriptedModelClient(events: [
            .toolCallDelta(.init(index: 1, id: "call_b", name: "share", arguments: "{\"")),
            .toolCallDelta(.init(index: 0, id: "call_a", name: "device", arguments: "{")),
            .toolCallDelta(.init(index: 1, id: nil, name: nil, arguments: "text\":\"x\"}")),
            .toolCallDelta(.init(index: 0, id: nil, name: "_info", arguments: "}")),
            .completed(.toolCalls)
        ])
        let runtime = DSHAgentRuntime(client: client, model: "deepseek-chat")

        let snapshot = try await runtime.send("Inspect")

        XCTAssertEqual(snapshot.messages.last?.toolCalls, [
            .init(id: "call_a", name: "device_info", arguments: "{}"),
            .init(id: "call_b", name: "share", arguments: "{\"text\":\"x\"}")
        ])
    }

    func testAgentRuntimeRetainsPartialResponseAndMarksFailure() async throws {
        let expectedError = DSHModelClientError.httpStatus(503, "busy")
        let client = ScriptedModelClient(events: [.contentDelta("partial")], terminalError: expectedError)
        let runtime = DSHAgentRuntime(client: client, model: "deepseek-chat")

        do {
            _ = try await runtime.send("Hello")
            XCTFail("Expected the stream to fail")
        } catch {
            XCTAssertEqual(error as? DSHModelClientError, expectedError)
        }

        let snapshot = await runtime.snapshot()
        XCTAssertEqual(snapshot.messages.last?.content, "partial")
        guard case .failed(let message) = snapshot.phase else {
            return XCTFail("Expected failed phase")
        }
        XCTAssertTrue(message.contains("503"))
    }

    func testAgentRuntimeRejectsBlankPromptWithoutChangingHistory() async {
        let runtime = DSHAgentRuntime(client: ScriptedModelClient(events: []), model: "deepseek-chat")
        do {
            _ = try await runtime.send(" \n ")
            XCTFail("Expected empty prompt error")
        } catch {
            XCTAssertEqual(error as? DSHAgentRuntimeError, .emptyPrompt)
        }
        let snapshot = await runtime.snapshot()
        XCTAssertEqual(snapshot.phase, .idle)
        XCTAssertTrue(snapshot.messages.isEmpty)
    }

    func testAgentRuntimeExecutesToolAndContinuesNextStep() async throws {
        let client = SequencedModelClient(scripts: [
            [
                .toolCallDelta(.init(index: 0, id: "call_1", name: "echo", arguments: "{\"text\":\"hello\"}")),
                .completed(.toolCalls)
            ],
            [.contentDelta("Tool completed"), .completed(.stop)]
        ])
        let registry = DSHToolRegistry([EchoTool()])
        let runtime = DSHAgentRuntime(
            client: client,
            model: "deepseek-chat",
            toolRegistry: registry
        )

        let snapshot = try await runtime.send("Use echo")

        XCTAssertEqual(snapshot.phase, .completed)
        XCTAssertEqual(snapshot.messages.map(\.role), [.user, .assistant, .tool, .assistant])
        XCTAssertEqual(snapshot.messages[2].toolCallID, "call_1")
        XCTAssertTrue(snapshot.messages[2].content?.contains("hello") == true)
        XCTAssertEqual(snapshot.messages[3].content, "Tool completed")
        let requests = await client.requests()
        XCTAssertEqual(requests.count, 2)
        XCTAssertEqual(requests[0].tools.map(\.name), ["echo"])
        XCTAssertEqual(requests[1].messages.last?.role, .tool)
    }

    func testToolRegistryReturnsStructuredErrors() async throws {
        let registry = DSHToolRegistry([EchoTool()])
        let malformed = await registry.execute(.init(id: "1", name: "echo", arguments: "not-json"))
        let unknown = await registry.execute(.init(id: "2", name: "missing", arguments: "{}"))

        XCTAssertTrue(malformed.contains("\"ok\":false"))
        XCTAssertTrue(malformed.contains("Invalid tool arguments"))
        XCTAssertTrue(unknown.contains("Unknown tool"))
    }

    func testSessionStorePersistsListsAndDeletesSessions() async throws {
        let directory = FileManager.default.temporaryDirectory
            .appendingPathComponent("DSHSessionStoreTests-\(UUID().uuidString)", isDirectory: true)
        defer { try? FileManager.default.removeItem(at: directory) }
        let store = DSHSessionStore(directory: directory)
        let older = DSHSessionRecord(
            id: UUID(),
            title: "Older",
            messages: [.init(role: .user, content: "first")],
            createdAt: Date(timeIntervalSince1970: 1),
            updatedAt: Date(timeIntervalSince1970: 2)
        )
        let newer = DSHSessionRecord(
            id: UUID(),
            title: "Newer",
            messages: [.init(role: .user, content: "second")],
            createdAt: Date(timeIntervalSince1970: 3),
            updatedAt: Date(timeIntervalSince1970: 4)
        )

        try await store.save(older)
        try await store.save(newer)

        let loadedOlder = try await store.load(id: older.id)
        XCTAssertEqual(loadedOlder, older)
        let records = try await store.list()
        XCTAssertEqual(records.map(\.id), [newer.id, older.id])
        try await store.delete(id: newer.id)
        let deleted = try await store.load(id: newer.id)
        XCTAssertNil(deleted)
    }

    func testMCPClientInitializesPagesToolsAndPreservesSessionHeaders() async throws {
        let endpoint = try XCTUnwrap(URL(string: "https://example.test/mcp"))
        let transport = FakeMCPTransport(responses: [
            .json(200, ["jsonrpc": .string("2.0"), "id": .number(1), "result": .object([
                "protocolVersion": .string(DSHMCPClient.protocolVersion),
                "capabilities": .object(["tools": .object([:])]),
                "serverInfo": .object(["name": .string("test"), "version": .string("1")])
            ])], headers: ["MCP-Session-Id": "session-1"]),
            .empty(202),
            .json(200, ["jsonrpc": .string("2.0"), "id": .number(2), "result": .object([
                "tools": .array([.object([
                    "name": .string("weather"),
                    "description": .string("Get weather"),
                    "inputSchema": .object(["type": .string("object")])
                ])]),
                "nextCursor": .string("page-2")
            ])]),
            .json(200, ["jsonrpc": .string("2.0"), "id": .number(3), "result": .object([
                "tools": .array([])
            ])])
        ])
        let client = DSHMCPClient(endpoint: endpoint, transport: transport)

        try await client.connect()
        let tools = try await client.listTools()

        XCTAssertEqual(tools.map(\.name), ["weather"])
        let requests = await transport.requests
        XCTAssertEqual(requests.count, 4)
        XCTAssertNil(requests[0].value(forHTTPHeaderField: "MCP-Protocol-Version"))
        XCTAssertEqual(requests[1].value(forHTTPHeaderField: "MCP-Session-Id"), "session-1")
        XCTAssertEqual(requests[2].value(forHTTPHeaderField: "MCP-Protocol-Version"), DSHMCPClient.protocolVersion)
        let lastBody = try XCTUnwrap(requests[3].httpBody)
        XCTAssertTrue(String(decoding: lastBody, as: UTF8.self).contains("page-2"))
    }

    func testMCPClientDecodesSSEToolResult() async throws {
        let endpoint = try XCTUnwrap(URL(string: "https://example.test/mcp"))
        let transport = FakeMCPTransport(responses: [
            .json(200, ["jsonrpc": .string("2.0"), "id": .number(1), "result": .object([
                "protocolVersion": .string(DSHMCPClient.protocolVersion),
                "capabilities": .object([:]),
                "serverInfo": .object(["name": .string("test"), "version": .string("1")])
            ])]),
            .empty(202),
            .sse(200, ["jsonrpc": .string("2.0"), "id": .number(2), "result": .object([
                "content": .array([.object(["type": .string("text"), "text": .string("sunny")])])
            ])])
        ])
        let client = DSHMCPClient(endpoint: endpoint, transport: transport)
        try await client.connect()

        let result = try await client.callTool(name: "weather", arguments: .object(["city": .string("LA")]))

        guard case .object(let object) = result else { return XCTFail("Expected object result") }
        XCTAssertNotNil(object["content"])
    }

    func testLazyGuestBootsOnlyOnFirstCommand() async throws {
        let host = FakeGuestHost()
        let manager = DSHLazyGuestManager(host: host)
        let initialState = await manager.state
        XCTAssertEqual(initialState, .dormant)

        _ = try await manager.execute(command: "pwd", timeout: 5)
        _ = try await manager.execute(command: "ls", timeout: 5)

        let readyState = await manager.state
        XCTAssertEqual(readyState, .ready)
        let calls = await host.calls()
        XCTAssertEqual(calls.boots, 1)
        XCTAssertEqual(calls.commands, ["pwd", "ls"])
    }

    func testConcurrentGuestReadinessCoalescesBoot() async throws {
        let host = FakeGuestHost(bootDelayNanoseconds: 50_000_000)
        let manager = DSHLazyGuestManager(host: host)
        async let first: Void = manager.ensureReady()
        async let second: Void = manager.ensureReady()
        _ = try await (first, second)
        let calls = await host.calls()
        XCTAssertEqual(calls.boots, 1)
    }

    func testBashToolDoesNotBootWhenUserDeclines() async throws {
        let host = FakeGuestHost()
        let manager = DSHLazyGuestManager(host: host)
        let tool = DSHBashTool(manager: manager, approval: FixedApproval(approved: false))
        do {
            _ = try await tool.execute(arguments: .object(["command": .string("rm file")]))
            XCTFail("Expected refusal")
        } catch {
            XCTAssertEqual(error as? DSHToolError, .disabled("bash command (not approved)"))
        }
        let calls = await host.calls()
        XCTAssertEqual(calls.boots, 0)
    }
}

private struct FixedApproval: DSHToolApprovalPolicy {
    let approved: Bool
    func approve(title: String, detail: String) async -> Bool { approved }
}

private actor FakeGuestHost: DSHGuestHost {
    private var bootCount = 0
    private var commands: [String] = []
    private let bootDelayNanoseconds: UInt64

    init(bootDelayNanoseconds: UInt64 = 0) { self.bootDelayNanoseconds = bootDelayNanoseconds }
    func ensureReady() async throws {
        bootCount += 1
        if bootDelayNanoseconds > 0 { try await Task.sleep(nanoseconds: bootDelayNanoseconds) }
    }
    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        commands.append(command)
        return .object(["exit_code": .number(0), "stdout": .string(command)])
    }
    func calls() -> (boots: Int, commands: [String]) { (bootCount, commands) }
}

private struct FakeMCPResponse: Sendable {
    let status: Int
    let data: Data
    let headers: [String: String]

    static func json(_ status: Int, _ object: [String: DSHJSONValue], headers: [String: String] = [:]) -> Self {
        .init(status: status, data: try! JSONEncoder().encode(DSHJSONValue.object(object)), headers: headers.merging(["Content-Type": "application/json"]) { first, _ in first })
    }
    static func sse(_ status: Int, _ object: [String: DSHJSONValue]) -> Self {
        let json = String(decoding: try! JSONEncoder().encode(DSHJSONValue.object(object)), as: UTF8.self)
        return .init(status: status, data: Data("data: \(json)\n\n".utf8), headers: ["Content-Type": "text/event-stream"])
    }
    static func empty(_ status: Int) -> Self { .init(status: status, data: Data(), headers: [:]) }
}

private actor FakeMCPTransport: DSHMCPTransport {
    private var responses: [FakeMCPResponse]
    var requests: [URLRequest] = []
    init(responses: [FakeMCPResponse]) { self.responses = responses }

    func send(_ request: URLRequest) async throws -> (Data, HTTPURLResponse) {
        requests.append(request)
        let response = responses.removeFirst()
        let http = HTTPURLResponse(
            url: request.url!,
            statusCode: response.status,
            httpVersion: "HTTP/1.1",
            headerFields: response.headers
        )!
        return (response.data, http)
    }
}

private struct EchoTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "echo",
        description: "Echo text",
        parameters: .object(["type": .string("object")])
    )

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let object) = arguments, case .string(let text) = object["text"] else {
            throw DSHToolError.invalidArguments("text is required")
        }
        return .object(["text": .string(text)])
    }
}

private actor SequencedModelState {
    var scripts: [[DSHModelEvent]]
    var recordedRequests: [DSHCompletionRequest] = []

    init(scripts: [[DSHModelEvent]]) { self.scripts = scripts }

    func next(for request: DSHCompletionRequest) -> [DSHModelEvent] {
        recordedRequests.append(request)
        return scripts.isEmpty ? [.completed(.stop)] : scripts.removeFirst()
    }
}

private struct SequencedModelClient: DSHModelClient {
    private let state: SequencedModelState
    init(scripts: [[DSHModelEvent]]) { state = SequencedModelState(scripts: scripts) }

    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        let state = state
        return AsyncThrowingStream { continuation in
            let task = Task {
                let events = await state.next(for: request)
                for event in events { continuation.yield(event) }
                continuation.finish()
            }
            continuation.onTermination = { @Sendable _ in task.cancel() }
        }
    }

    func requests() async -> [DSHCompletionRequest] { await state.recordedRequests }
}

private actor ScriptedRequestRecorder {
    var request: DSHCompletionRequest?
    func record(_ request: DSHCompletionRequest) { self.request = request }
}

private struct ScriptedModelClient: DSHModelClient {
    let events: [DSHModelEvent]
    let terminalError: (any Error & Sendable)?
    private let recorder = ScriptedRequestRecorder()

    init(events: [DSHModelEvent], terminalError: (any Error & Sendable)? = nil) {
        self.events = events
        self.terminalError = terminalError
    }

    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        let events = events
        let terminalError = terminalError
        let recorder = recorder
        return AsyncThrowingStream { continuation in
            let task = Task {
                await recorder.record(request)
                for event in events { continuation.yield(event) }
                continuation.finish(throwing: terminalError)
            }
            continuation.onTermination = { @Sendable _ in task.cancel() }
        }
    }

    func lastRequest() async -> DSHCompletionRequest? {
        await recorder.request
    }
}
