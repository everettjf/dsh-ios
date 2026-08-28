import Foundation
import AgentRuntime
import AgentTools
import AgentStorage

public enum DSHGuestState: Equatable, Sendable {
    case dormant
    case starting
    case ready
    case failed(String)
}

/// The portable boundary between Swift Harness Kit and any Linux execution
/// implementation. The framework does not depend on iSH or a particular VM.
public protocol DSHGuestHost: Sendable {
    func ensureReady() async throws
    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue
    func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue
}

public actor DSHLazyGuestManager {
    private let host: any DSHGuestHost
    private var bootTask: Task<Void, Error>?
    public private(set) var state: DSHGuestState = .dormant

    public init(host: any DSHGuestHost) { self.host = host }

    public func ensureReady() async throws {
        if state == .ready { return }
        if let bootTask { return try await bootTask.value }
        state = .starting
        let host = host
        let task = Task { try await host.ensureReady() }
        bootTask = task
        do {
            try await task.value
            state = .ready
            bootTask = nil
        } catch {
            state = .failed(error.localizedDescription)
            bootTask = nil
            throw error
        }
    }

    public func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        try await ensureReady()
        return try await host.execute(command: command, timeout: timeout)
    }

    public func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        try await ensureReady()
        return try await host.write(data: data, to: path, timeout: timeout)
    }
}

public actor DSHActiveWorkspaceContext {
    private var sessionID: UUID
    public init(sessionID: UUID) { self.sessionID = sessionID }
    public func currentSessionID() -> UUID { sessionID }
    public func select(_ sessionID: UUID) { self.sessionID = sessionID }
}

public struct DSHStageAttachmentTool: DSHNativeTool {
    public let definition = DSHToolDefinition(
        name: "stage_attachment_in_linux",
        description: "Copy a user-attached file into the private Linux workspace when Linux processing is required. Starts Linux on first use.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object(["attachment_id": .object(["type": .string("string")])]),
            "required": .array([.string("attachment_id")]),
            "additionalProperties": .bool(false)
        ])
    )
    private let manager: DSHLazyGuestManager
    private let workspace: DSHWorkspaceStore
    private let context: DSHActiveWorkspaceContext

    public init(manager: DSHLazyGuestManager, workspace: DSHWorkspaceStore, context: DSHActiveWorkspaceContext) {
        self.manager = manager
        self.workspace = workspace
        self.context = context
    }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let object) = arguments,
              case .string(let rawID) = object["attachment_id"],
              let id = UUID(uuidString: rawID) else {
            throw DSHToolError.invalidArguments("attachment_id must be a UUID from the current conversation")
        }
        let sessionID = await context.currentSessionID()
        let data = try await workspace.data(attachmentID: id, sessionID: sessionID)
        guard data.count <= DSHWorkspaceStore.maximumFileBytes else {
            throw DSHWorkspaceError.fileTooLarge(DSHWorkspaceStore.maximumFileBytes)
        }
        let path = "/root/workspace/attachments/\(id.uuidString)"
        let result = try await manager.write(data: data, to: path, timeout: 120)
        guard case .object(let values) = result,
              case .number(let exitCode) = values["exit_code"], exitCode == 0 else {
            throw DSHToolError.executionFailed("Linux could not stage the attachment")
        }
        return .object(["path": .string(path), "bytes": .number(Double(data.count))])
    }
}

public protocol DSHToolApprovalPolicy: Sendable {
    func approve(title: String, detail: String) async -> Bool
}

public struct DSHBashTool: DSHNativeTool {
    public let definition = DSHToolDefinition(
        name: "bash",
        description: "Run a shell command in the app's private Linux workspace. Starts Linux on first use and requires user confirmation for every command.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([
                "command": .object(["type": .string("string")]),
                "timeout_seconds": .object(["type": .string("number"), "minimum": .number(1), "maximum": .number(120)])
            ]),
            "required": .array([.string("command")]),
            "additionalProperties": .bool(false)
        ])
    )
    private let manager: DSHLazyGuestManager
    private let approval: any DSHToolApprovalPolicy

    public init(manager: DSHLazyGuestManager, approval: any DSHToolApprovalPolicy) {
        self.manager = manager
        self.approval = approval
    }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let object) = arguments,
              case .string(let command) = object["command"],
              !command.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty else {
            throw DSHToolError.invalidArguments("command is required")
        }
        let requestedTimeout: Double
        if case .number(let value) = object["timeout_seconds"] { requestedTimeout = value }
        else { requestedTimeout = 30 }
        let timeout = min(120, max(1, requestedTimeout))
        guard await approval.approve(title: "Run Linux command?", detail: command) else {
            throw DSHToolError.disabled("bash command (not approved)")
        }
        return try await manager.execute(command: command, timeout: timeout)
    }
}
