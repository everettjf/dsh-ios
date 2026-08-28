import Foundation
#if canImport(AgentRuntime)
import AgentRuntime
#endif
#if canImport(AgentTools)
import AgentTools
#endif
#if canImport(AgentLinuxGuest)
import AgentLinuxGuest
#endif

/// SHOS policy adapter that combines its capability preferences with the
/// native per-call confirmation UI. Neither concern belongs in AgentTools.
struct DSHDefaultsToolAuthorizationPolicy: DSHToolAuthorizationPolicy {
    private let approval: any DSHToolApprovalPolicy

    init(approval: any DSHToolApprovalPolicy = DSHNativeConfirmationPolicy()) {
        self.approval = approval
    }

    func authorize(permission: DSHToolPermission, detail: String?) async -> DSHToolAuthorizationDecision {
        let key = "DSHCapabilityEnabled.\(permission.identifier)"
        let stored = UserDefaults.standard.object(forKey: key) as? NSNumber
        let enabled = stored?.boolValue ?? permission.enabledByDefault
        guard enabled else { return .refused("The user disabled \(permission.title).") }
        guard permission.gate == .perCall else { return .allowed }
        let approved = await approval.approve(
            title: permission.title,
            detail: detail ?? "The agent requested this action."
        )
        return approved ? .allowed : .declined("The user declined \(permission.title).")
    }
}

/// SHOS adapter from package audit events to the Objective-C activity log.
struct DSHActivityToolAuditSink: DSHToolAuditSink {
    func started(name: String, detail: String?, correlationID: String) async {
        DSHNativeToolAudit.recordStarted(name, detail: detail, correlationID: correlationID)
    }

    func finished(
        name: String,
        detail: String?,
        result: String?,
        outcome: String,
        duration: TimeInterval,
        correlationID: String
    ) async {
        DSHNativeToolAudit.recordFinished(
            name,
            detail: detail,
            result: result,
            outcome: outcome,
            duration: duration,
            correlationID: correlationID
        )
    }
}

/// SHOS-only adapter for tools whose lifecycle is audited without an
/// authorization decision (for example MCP and guest staging wrappers).
struct DSHAuditedTool: DSHNativeTool {
    let definition: DSHToolDefinition
    private let tool: any DSHNativeTool
    private let source: String
    private let auditName: String

    init(_ tool: any DSHNativeTool, source: String, auditName: String) {
        self.tool = tool
        self.source = source
        self.auditName = auditName
        definition = tool.definition
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        let id = UUID().uuidString
        let detail: String
        if case .object(let fields) = arguments { detail = "argument_fields=\(fields.keys.sorted().joined(separator: ","))" }
        else { detail = "argument_shape=non_object" }
        let started = ContinuousClock().now
        DSHNativeToolAudit.recordStarted(withSource: source, name: auditName, detail: detail, correlationID: id)
        do {
            let result = try await tool.execute(arguments: arguments)
            DSHNativeToolAudit.recordFinished(
                withSource: source,
                name: auditName,
                detail: detail,
                result: Self.shape(result),
                outcome: "ok",
                duration: Self.seconds(started.duration(to: ContinuousClock().now)),
                correlationID: id
            )
            return result
        } catch {
            DSHNativeToolAudit.recordFinished(
                withSource: source,
                name: auditName,
                detail: detail,
                result: "error_category=\(DSHAgentRuntime.errorCategory(error))",
                outcome: "error",
                duration: Self.seconds(started.duration(to: ContinuousClock().now)),
                correlationID: id
            )
            throw error
        }
    }

    private static func shape(_ value: DSHJSONValue) -> String {
        switch value {
        case .object(let value): return "result_shape=object fields=\(value.count)"
        case .array(let value): return "result_shape=array items=\(value.count)"
        case .string(let value): return "result_shape=text characters=\(value.count)"
        case .number: return "result_shape=number"
        case .bool: return "result_shape=boolean"
        case .null: return "result_shape=empty"
        }
    }

    private static func seconds(_ duration: Duration) -> TimeInterval {
        Double(duration.components.seconds) + Double(duration.components.attoseconds) / 1e18
    }
}
