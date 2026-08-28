import Foundation
import XCTest
@testable import AgentRuntime
import AgentTools

final class AgentRuntimeTests: XCTestCase {
    func testJSONValueRoundTripsNestedValues() throws {
        let value: DSHJSONValue = .object([
            "enabled": .bool(true),
            "items": .array([.number(2), .string("two"), .null])
        ])
        let data = try JSONEncoder().encode(value)
        XCTAssertEqual(try JSONDecoder().decode(DSHJSONValue.self, from: data), value)
    }

    func testRegistryReturnsStructuredUnknownToolError() async throws {
        let registry = DSHToolRegistry()
        let result = await registry.execute(.init(id: "1", name: "missing", arguments: "{}"))
        let decoded = try JSONDecoder().decode(DSHJSONValue.self, from: Data(result.utf8))
        guard case .object(let object) = decoded else { return XCTFail("Expected object") }
        XCTAssertEqual(object["ok"], .bool(false))
        XCTAssertEqual(object["error"], .string("Unknown tool: missing"))
    }

    func testRuntimeStreamsReasoningContentAndUsage() async throws {
        let client = StubModelClient(events: [
            .reasoningDelta("think"),
            .contentDelta("answer"),
            .usage(.init(promptTokens: 3, completionTokens: 2, totalTokens: 5)),
            .completed(.stop)
        ])
        let runtime = DSHAgentRuntime(client: client, model: "test")
        let snapshot = try await runtime.send("hello")
        XCTAssertEqual(snapshot.messages.last?.reasoningContent, "think")
        XCTAssertEqual(snapshot.messages.last?.content, "answer")
        XCTAssertEqual(snapshot.usage?.totalTokens, 5)
        XCTAssertEqual(snapshot.phase, .completed)
    }

    func testRuntimeAssemblesToolCallAndContinues() async throws {
        let client = SequencedModelClient(streams: [[
            .toolCallDelta(.init(index: 0, id: "call-", name: "ec", arguments: "{\"value\":")),
            .toolCallDelta(.init(index: 0, id: "1", name: "ho", arguments: "\"ok\"}")),
            .completed(.toolCalls)
        ], [
            .contentDelta("done"), .completed(.stop)
        ]])
        let runtime = DSHAgentRuntime(
            client: client,
            model: "test",
            toolRegistry: DSHToolRegistry([EchoTool()])
        )
        let snapshot = try await runtime.send("run")
        XCTAssertEqual(snapshot.messages.filter { $0.role == .tool }.count, 1)
        XCTAssertEqual(snapshot.messages.last?.content, "done")
    }

    func testContextPolicyRetainsCompleteNewestTurnWithinBudget() {
        let messages = [
            DSHChatMessage(role: .user, content: String(repeating: "old", count: 2_000)),
            DSHChatMessage(role: .assistant, content: "old answer"),
            DSHChatMessage(role: .user, content: "new question"),
            DSHChatMessage(role: .assistant, content: "new answer")
        ]
        let selected = DSHContextPolicy(maximumEstimatedTokens: 1_000)
            .messagesForRequest(messages, systemPrompt: nil)
        XCTAssertEqual(selected.map(\.content), ["new question", "new answer"])
    }
}

private struct StubModelClient: DSHModelClient {
    let events: [DSHModelEvent]

    func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        AsyncThrowingStream { continuation in
            events.forEach { continuation.yield($0) }
            continuation.finish()
        }
    }
}

private actor SequencedModelClient: DSHModelClient {
    private var streams: [[DSHModelEvent]]

    init(streams: [[DSHModelEvent]]) { self.streams = streams }

    nonisolated func stream(request: DSHCompletionRequest) -> AsyncThrowingStream<DSHModelEvent, Error> {
        AsyncThrowingStream { continuation in
            Task {
                let events = await self.next()
                events.forEach { continuation.yield($0) }
                continuation.finish()
            }
        }
    }

    private func next() -> [DSHModelEvent] {
        streams.isEmpty ? [] : streams.removeFirst()
    }
}

private struct EchoTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "echo",
        description: "Echo a value.",
        parameters: .object(["type": .string("object")])
    )

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue { arguments }
}
