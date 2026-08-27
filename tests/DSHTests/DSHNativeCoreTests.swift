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

    func testAgentRuntimeCancellationRetainsPartialResponse() async throws {
        let runtime = DSHAgentRuntime(client: SuspendedModelClient(), model: "deepseek-chat")
        let task = Task { try await runtime.send("Hello") }
        try await Task.sleep(for: .milliseconds(50))
        task.cancel()

        do {
            _ = try await task.value
            XCTFail("Expected cancellation")
        } catch is CancellationError { }

        let snapshot = await runtime.snapshot()
        XCTAssertEqual(snapshot.phase, .cancelled)
        XCTAssertEqual(snapshot.messages.last?.content, "partial")
    }

    func testAgentRuntimeRetriesWithoutDuplicatingUserMessageAndCanContinue() async throws {
        let client = SequencedModelClient(scripts: [
            [.contentDelta("first"), .completed(.stop)],
            [.contentDelta("replacement"), .completed(.stop)],
            [.contentDelta("continued"), .completed(.stop)]
        ])
        let runtime = DSHAgentRuntime(client: client, model: "deepseek-chat")

        _ = try await runtime.send("Question")
        let retried = try await runtime.retryLastTurn()
        XCTAssertEqual(retried.messages.map(\.role), [.user, .assistant])
        XCTAssertEqual(retried.messages.last?.content, "replacement")

        let continued = try await runtime.continueResponse()
        XCTAssertEqual(continued.messages.map(\.role), [.user, .assistant, .assistant])
        XCTAssertEqual(continued.messages.last?.content, "continued")
        let requests = await client.requests()
        XCTAssertEqual(requests[1].messages.map(\.role), [.user])
        XCTAssertEqual(requests[2].messages.map(\.role), [.user, .assistant])
    }

    func testContextPolicyKeepsNewestTurnWhole() {
        let old = String(repeating: "o", count: 5_000)
        let newest = String(repeating: "n", count: 5_000)
        let messages: [DSHChatMessage] = [
            .init(role: .user, content: old),
            .init(role: .assistant, content: "old answer"),
            .init(role: .user, content: newest),
            .init(role: .assistant, content: "new answer"),
            .init(role: .tool, content: "tool result", toolCallID: "call-1")
        ]

        let selected = DSHContextPolicy(maximumEstimatedTokens: 1_000)
            .messagesForRequest(messages, systemPrompt: "system")

        XCTAssertEqual(selected.map(\.role), [.system, .user, .assistant, .tool])
        XCTAssertEqual(selected[1].content, newest)
        XCTAssertEqual(selected.last?.toolCallID, "call-1")
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

    func testSessionStoreMigratesLegacyRecordsToCurrentSchema() async throws {
        let directory = FileManager.default.temporaryDirectory
            .appendingPathComponent("DSHSessionMigrationTests-\(UUID().uuidString)", isDirectory: true)
        defer { try? FileManager.default.removeItem(at: directory) }
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        let id = UUID()
        let record = DSHSessionRecord(
            id: id,
            title: "Legacy",
            messages: [.init(role: .user, content: "hello")],
            createdAt: Date(timeIntervalSince1970: 1),
            updatedAt: Date(timeIntervalSince1970: 2)
        )
        let encoder = JSONEncoder()
        encoder.dateEncodingStrategy = .iso8601
        var json = try XCTUnwrap(JSONSerialization.jsonObject(with: encoder.encode(record)) as? [String: Any])
        json.removeValue(forKey: "schemaVersion")
        json.removeValue(forKey: "turnState")
        let url = directory.appendingPathComponent(id.uuidString).appendingPathExtension("json")
        try JSONSerialization.data(withJSONObject: json).write(to: url)
        let store = DSHSessionStore(directory: directory)

        let loaded = try await store.load(id: id)
        let migrated = try XCTUnwrap(loaded)

        XCTAssertEqual(migrated.schemaVersion, DSHSessionRecord.currentSchemaVersion)
        XCTAssertEqual(migrated.turnState, .completed)
        let rewritten = try XCTUnwrap(JSONSerialization.jsonObject(with: Data(contentsOf: url)) as? [String: Any])
        XCTAssertEqual(rewritten["schemaVersion"] as? Int, DSHSessionRecord.currentSchemaVersion)
        XCTAssertEqual(rewritten["turnState"] as? String, DSHSessionTurnState.completed.rawValue)
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
        let client = DSHMCPClient(endpoint: endpoint, headers: ["Authorization": "Bearer secret-token"], transport: transport)

        try await client.connect()
        let tools = try await client.listTools()

        XCTAssertEqual(tools.map(\.name), ["weather"])
        let requests = await transport.requests
        XCTAssertEqual(requests.count, 4)
        XCTAssertNil(requests[0].value(forHTTPHeaderField: "MCP-Protocol-Version"))
        XCTAssertEqual(requests[0].value(forHTTPHeaderField: "Authorization"), "Bearer secret-token")
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

    func testToolRegistryCanAtomicallyRefreshOnlyMCPTools() async {
        let registry = DSHToolRegistry([EchoTool()])
        registry.replaceTools(withPrefix: "mcp__", with: [NamedTool(name: "mcp__one__search")])
        XCTAssertEqual(registry.definitions.map(\.name), ["echo", "mcp__one__search"])
        registry.replaceTools(withPrefix: "mcp__", with: [NamedTool(name: "mcp__two__fetch")])
        XCTAssertEqual(registry.definitions.map(\.name), ["echo", "mcp__two__fetch"])
        let stale = await registry.execute(.init(id: "1", name: "mcp__one__search", arguments: "{}"))
        XCTAssertTrue(stale.contains("Unknown tool"))
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

    func testGovernedToolRefusesBeforeExecutionAndAuditsDecision() async throws {
        let probe = ProbeTool()
        let audit = RecordingAuditSink()
        let tool = DSHGovernedTool(
            probe,
            permission: .init(identifier: "private.read", title: "Private read", gate: .enabledOnly, enabledByDefault: false),
            authorization: FixedAuthorization(.refused("disabled")),
            audit: audit
        )

        do {
            _ = try await tool.execute(arguments: .object([:]))
            XCTFail("Expected refusal")
        } catch {
            XCTAssertEqual(error as? DSHToolError, .disabled("disabled"))
        }

        let executionCount = await probe.executionCount()
        XCTAssertEqual(executionCount, 0)
        let records = await audit.records
        XCTAssertEqual(records.map(\.outcome), ["started", "refused"])
    }

    func testGovernedToolAuditsOnlyResultShapeNotSensitiveContents() async throws {
        let audit = RecordingAuditSink()
        let tool = DSHGovernedTool(
            ProbeTool(result: .object(["secret": .string("private-value")])),
            permission: .init(identifier: "safe.read", title: "Safe read", gate: .enabledOnly, enabledByDefault: true),
            authorization: FixedAuthorization(.allowed),
            audit: audit
        )

        _ = try await tool.execute(arguments: .object(["query": .string("private-query")]))

        let records = await audit.records
        XCTAssertEqual(records.last?.outcome, "ok")
        XCTAssertEqual(records.last?.result, "object with 1 field(s)")
        XCTAssertFalse(records.contains { ($0.detail ?? "").contains("private-query") })
        XCTAssertFalse(records.contains { ($0.result ?? "").contains("private-value") })
    }

    func testDeviceToolsHaveSeparateStableSchemas() async throws {
        let info = DSHDeviceInfoTool()
        let power = DSHDevicePowerTool()
        XCTAssertEqual(info.definition.name, "device_info")
        XCTAssertEqual(power.definition.name, "device_power")
        guard case .object(let infoResult) = try await info.execute(arguments: .object([:])),
              case .object(let powerResult) = try await power.execute(arguments: .object([:])) else {
            return XCTFail("Expected object results")
        }
        XCTAssertNotNil(infoResult["system_version"])
        XCTAssertNil(infoResult["battery_level"])
        XCTAssertNotNil(powerResult["battery_level"])
        XCTAssertNotNil(powerResult["thermal_state"])
    }

    func testNativeReadToolsMapArgumentsToInProcessRoutes() async throws {
        let executor = RecordingRouteExecutor(result: .object(["rows": .array([])]))
        _ = try await DSHNativeReadTool(.contacts, executor: executor).execute(arguments: .object([
            "query": .string("Ada Lovelace"), "limit": .number(3)
        ]))
        _ = try await DSHNativeReadTool(.calendar, executor: executor).execute(arguments: .object([
            "days": .number(-7), "limit": .number(20)
        ]))
        _ = try await DSHNativeReadTool(.health, executor: executor).execute(arguments: .object([
            "metric": .string("sleep"), "days": .number(14)
        ]))

        let calls = await executor.calls
        XCTAssertEqual(calls.map(\.path), ["/v1/contacts", "/v1/calendar/events", "/v1/health/sleep"])
        XCTAssertEqual(calls[0].query, ["q": "Ada Lovelace", "limit": "3"])
        XCTAssertEqual(calls[1].query, ["days": "-7", "limit": "20"])
        XCTAssertEqual(calls[2].query, ["days": "14"])
        XCTAssertTrue(calls.allSatisfy { $0.method == "GET" && $0.json == nil })
    }

    func testNativeReadToolsRejectUnboundedContactsAndUnknownHealthMetric() async {
        let executor = RecordingRouteExecutor(result: .object([:]))
        do {
            _ = try await DSHNativeReadTool(.contacts, executor: executor).execute(arguments: .object([:]))
            XCTFail("Missing contact query should fail")
        } catch { XCTAssertTrue(error.localizedDescription.contains("query is required")) }
        do {
            _ = try await DSHNativeReadTool(.health, executor: executor).execute(arguments: .object(["metric": .string("diagnosis")]))
            XCTFail("Unknown health metric should fail")
        } catch { XCTAssertTrue(error.localizedDescription.contains("metric must be")) }
        let calls = await executor.calls
        XCTAssertTrue(calls.isEmpty)
    }

    func testNativeReadToolDefinitionsExposeFiveDistinctTools() {
        let names = [
            DSHNativeReadTool(.location).definition.name,
            DSHNativeReadTool(.contacts).definition.name,
            DSHNativeReadTool(.calendar).definition.name,
            DSHNativeReadTool(.reminders).definition.name,
            DSHNativeReadTool(.health).definition.name
        ]
        XCTAssertEqual(Set(names), Set(["location_query", "contacts_search", "calendar_query", "reminders_query", "health_query"]))
    }

    func testNativeWriteToolsUsePostRoutesAndPreserveBodies() async throws {
        let executor = RecordingRouteExecutor(result: .object(["accepted": .bool(true)]))
        _ = try await DSHNativeWriteTool(.notify, executor: executor).execute(arguments: .object(["title": .string("Done")]))
        _ = try await DSHNativeWriteTool(.calendarCreate, executor: executor).execute(arguments: .object(["title": .string("Review"), "start": .string("2026-09-01 09:00")]))
        _ = try await DSHNativeWriteTool(.fileImport, executor: executor).execute(arguments: .object([:]))
        _ = try await DSHNativeWriteTool(.shortcutRun, executor: executor).execute(arguments: .object(["name": .string("Focus")]))

        let calls = await executor.calls
        XCTAssertEqual(calls.map(\.path), ["/v1/notify", "/v1/calendar/events", "/v1/files/import", "/v1/shortcut/run"])
        XCTAssertTrue(calls.allSatisfy { $0.method == "POST" && $0.query.isEmpty && $0.json != nil })
        guard case .object(let notification) = calls[0].json else { return XCTFail("Expected body") }
        XCTAssertEqual(notification["title"], .string("Done"))
    }

    func testNativeWriteToolsAreCompleteAndValidateBeforeUI() async {
        let names = DSHNativeWriteToolKind.allCases.map { DSHNativeWriteTool($0).definition.name }
        XCTAssertEqual(Set(names), Set(["notify", "calendar_create_event", "reminders_create", "file_import", "file_export", "photo_import", "share", "shortcut_run"]))
        let executor = RecordingRouteExecutor(result: .object([:]))
        do {
            _ = try await DSHNativeWriteTool(.share, executor: executor).execute(arguments: .object(["text": .string(String(repeating: "x", count: 4_001))]))
            XCTFail("Oversized share should fail")
        } catch { XCTAssertTrue(error.localizedDescription.contains("4000")) }
        do {
            _ = try await DSHNativeWriteTool(.fileExport, executor: executor).execute(arguments: .object(["name": .string("a.txt")]))
            XCTFail("Missing contents should fail")
        } catch { XCTAssertTrue(error.localizedDescription.contains("base64")) }
        let calls = await executor.calls
        XCTAssertTrue(calls.isEmpty)
    }
}

private struct RouteCall: Sendable {
    let method: String
    let path: String
    let query: [String: String]
    let json: DSHJSONValue?
}

private actor RecordingRouteExecutor: DSHNativeRouteExecuting {
    private(set) var calls: [RouteCall] = []
    let result: DSHJSONValue
    init(result: DSHJSONValue) { self.result = result }
    func invoke(method: String, path: String, query: [String: String], json: DSHJSONValue?) async throws -> DSHJSONValue {
        calls.append(.init(method: method, path: path, query: query, json: json))
        return result
    }
}

private struct FixedAuthorization: DSHToolAuthorizationPolicy {
    let decision: DSHToolAuthorizationDecision
    init(_ decision: DSHToolAuthorizationDecision) { self.decision = decision }
    func authorize(permission: DSHToolPermission, detail: String?) async -> DSHToolAuthorizationDecision { decision }
}

private actor ProbeTool: DSHNativeTool {
    nonisolated let definition = DSHToolDefinition(
        name: "probe",
        description: "Test probe",
        parameters: .object(["type": .string("object")])
    )
    private var count = 0
    private let result: DSHJSONValue
    init(result: DSHJSONValue = .object(["value": .string("ok")])) { self.result = result }
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        count += 1
        return result
    }
    func executionCount() -> Int { count }
}

private struct AuditRecord: Sendable {
    let outcome: String
    let detail: String?
    let result: String?
}

private actor RecordingAuditSink: DSHToolAuditSink {
    var records: [AuditRecord] = []
    func started(name: String, detail: String?, correlationID: String) async {
        records.append(.init(outcome: "started", detail: detail, result: nil))
    }
    func finished(
        name: String,
        detail: String?,
        result: String?,
        outcome: String,
        duration: TimeInterval,
        correlationID: String
    ) async {
        records.append(.init(outcome: outcome, detail: detail, result: result))
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

private struct NamedTool: DSHNativeTool {
    let definition: DSHToolDefinition
    init(name: String) { definition = .init(name: name, description: "Test", parameters: .object(["type": .string("object")])) }
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue { .object(["ok": .bool(true)]) }
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

private struct SuspendedModelClient: DSHModelClient {
    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        AsyncThrowingStream { continuation in
            let task = Task {
                continuation.yield(.contentDelta("partial"))
                do {
                    try await Task.sleep(for: .seconds(30))
                    continuation.finish()
                } catch {
                    continuation.finish(throwing: CancellationError())
                }
            }
            continuation.onTermination = { @Sendable _ in task.cancel() }
        }
    }
}
