import Foundation
import XCTest
import AgentRuntime
@testable import AgentTools

final class AgentToolsTests: XCTestCase {
    func testRegistrySortsDefinitionsAndExecutesTool() async throws {
        let registry = DSHToolRegistry([ValueTool(name: "z"), ValueTool(name: "a")])
        XCTAssertEqual(registry.definitions.map(\.name), ["a", "z"])
        let encoded = await registry.execute(.init(id: "1", name: "a", arguments: "{}"))
        guard case .object(let envelope) = try JSONDecoder().decode(DSHJSONValue.self, from: Data(encoded.utf8)) else {
            return XCTFail("Expected envelope")
        }
        XCTAssertEqual(envelope["ok"], .bool(true))
    }

    func testGovernedToolRefusesBeforeExecutingAndAudits() async throws {
        let tool = CountingTool()
        let audit = RecordingAudit()
        let governed = DSHGovernedTool(
            tool,
            permission: .init(identifier: "private.read", title: "Private read", gate: .enabledOnly, enabledByDefault: false),
            authorization: FixedAuthorization(.refused("disabled")),
            audit: audit
        )
        do {
            _ = try await governed.execute(arguments: .object([:]))
            XCTFail("Expected refusal")
        } catch {
            XCTAssertEqual(error as? DSHToolError, .disabled("disabled"))
        }
        let executionCount = await tool.count
        let outcomes = await audit.outcomes
        XCTAssertEqual(executionCount, 0)
        XCTAssertEqual(outcomes, ["started", "refused"])
    }

    func testGovernedToolAuditsShapeWithoutSensitiveValues() async throws {
        let audit = RecordingAudit()
        let governed = DSHGovernedTool(
            ValueTool(name: "safe", result: .object(["secret": .string("private-value")])),
            permission: .init(identifier: "safe.read", title: "Safe read", gate: .enabledOnly, enabledByDefault: true),
            authorization: FixedAuthorization(.allowed),
            audit: audit
        )
        _ = try await governed.execute(arguments: .object(["query": .string("private-query")]))
        let records = await audit.records
        XCTAssertEqual(records.last?.result, "object with 1 field(s)")
        XCTAssertFalse(records.contains { ($0.detail ?? "").contains("private-query") })
        XCTAssertFalse(records.contains { ($0.result ?? "").contains("private-value") })
    }

    func testToolErrorsExposeStableRuntimeCategory() {
        XCTAssertEqual(DSHToolError.executionFailed("private").agentErrorCategory, "tool_error")
        XCTAssertEqual(DSHAgentRuntime.errorCategory(DSHToolError.executionFailed("private")), "tool_error")
    }
}

private struct ValueTool: DSHNativeTool {
    let definition: DSHToolDefinition
    let result: DSHJSONValue

    init(name: String, result: DSHJSONValue = .string("ok")) {
        definition = .init(name: name, description: name, parameters: .object(["type": .string("object")]))
        self.result = result
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue { result }
}

private actor CountingTool: DSHNativeTool {
    nonisolated let definition = DSHToolDefinition(
        name: "count", description: "count", parameters: .object(["type": .string("object")])
    )
    private(set) var count = 0
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        count += 1
        return .null
    }
}

private struct FixedAuthorization: DSHToolAuthorizationPolicy {
    let decision: DSHToolAuthorizationDecision
    init(_ decision: DSHToolAuthorizationDecision) { self.decision = decision }
    func authorize(permission: DSHToolPermission, detail: String?) async -> DSHToolAuthorizationDecision { decision }
}

private actor RecordingAudit: DSHToolAuditSink {
    struct Record: Sendable { let outcome: String; let detail: String?; let result: String? }
    private(set) var records: [Record] = []
    var outcomes: [String] { records.map(\.outcome) }
    func started(name: String, detail: String?, correlationID: String) async {
        records.append(.init(outcome: "started", detail: detail, result: nil))
    }
    func finished(
        name: String, detail: String?, result: String?, outcome: String,
        duration: TimeInterval, correlationID: String
    ) async {
        records.append(.init(outcome: outcome, detail: detail, result: result))
    }
}
