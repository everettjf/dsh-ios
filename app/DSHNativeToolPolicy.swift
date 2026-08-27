import Foundation

enum DSHToolPermissionGate: Sendable {
    case enabledOnly
    case systemPermission
    case perCall
}

struct DSHToolPermission: Sendable {
    let identifier: String
    let title: String
    let gate: DSHToolPermissionGate
    let enabledByDefault: Bool
}

enum DSHToolAuthorizationDecision: Equatable, Sendable {
    case allowed
    case refused(String)
    case declined(String)
}

protocol DSHToolAuthorizationPolicy: Sendable {
    func authorize(permission: DSHToolPermission, detail: String?) async -> DSHToolAuthorizationDecision
}

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

protocol DSHToolAuditSink: Sendable {
    func started(name: String, detail: String?, correlationID: String) async
    func finished(
        name: String,
        detail: String?,
        result: String?,
        outcome: String,
        duration: TimeInterval,
        correlationID: String
    ) async
}

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

struct DSHGovernedTool: DSHNativeTool {
    let definition: DSHToolDefinition
    private let tool: any DSHNativeTool
    private let permission: DSHToolPermission
    private let authorization: any DSHToolAuthorizationPolicy
    private let audit: any DSHToolAuditSink

    init(
        _ tool: any DSHNativeTool,
        permission: DSHToolPermission,
        authorization: any DSHToolAuthorizationPolicy = DSHDefaultsToolAuthorizationPolicy(),
        audit: any DSHToolAuditSink = DSHActivityToolAuditSink()
    ) {
        self.tool = tool
        self.permission = permission
        self.authorization = authorization
        self.audit = audit
        definition = tool.definition
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        let correlationID = UUID().uuidString
        let detail = Self.argumentSummary(arguments)
        let clock = ContinuousClock()
        let startedAt = clock.now
        await audit.started(name: permission.identifier, detail: detail, correlationID: correlationID)

        let decision = await authorization.authorize(permission: permission, detail: detail)
        switch decision {
        case .allowed:
            break
        case .refused(let message):
            await finish(outcome: "refused", result: nil, startedAt: startedAt, detail: detail, correlationID: correlationID)
            throw DSHToolError.disabled(message)
        case .declined(let message):
            await finish(outcome: "declined", result: nil, startedAt: startedAt, detail: detail, correlationID: correlationID)
            throw DSHToolError.permissionDenied(message)
        }

        do {
            let value = try await tool.execute(arguments: arguments)
            await finish(
                outcome: "ok",
                result: Self.resultShape(value),
                startedAt: startedAt,
                detail: detail,
                correlationID: correlationID
            )
            return value
        } catch {
            await finish(outcome: "error", result: nil, startedAt: startedAt, detail: detail, correlationID: correlationID)
            throw error
        }
    }

    private func finish(
        outcome: String,
        result: String?,
        startedAt: ContinuousClock.Instant,
        detail: String?,
        correlationID: String
    ) async {
        let duration = startedAt.duration(to: ContinuousClock().now)
        let seconds = Double(duration.components.seconds) + Double(duration.components.attoseconds) / 1e18
        await audit.finished(
            name: permission.identifier,
            detail: detail,
            result: result,
            outcome: outcome,
            duration: seconds,
            correlationID: correlationID
        )
    }

    private static func argumentSummary(_ value: DSHJSONValue) -> String? {
        guard case .object(let object) = value, !object.isEmpty else { return nil }
        return "\(object.count) argument field(s): \(object.keys.sorted().joined(separator: ", "))"
    }

    private static func resultShape(_ value: DSHJSONValue) -> String {
        switch value {
        case .object(let object): return "object with \(object.count) field(s)"
        case .array(let array): return "array with \(array.count) item(s)"
        case .string(let string): return "text with \(string.count) character(s)"
        case .number: return "number"
        case .bool: return "boolean"
        case .null: return "empty"
        }
    }
}
