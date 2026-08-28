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

public struct DSHGuestExecutionLimits: Equatable, Sendable {
    public static let `default` = Self()
    public let maximumCommandBytes: Int
    public let maximumOutputBytes: Int
    public let maximumTimeout: TimeInterval

    public init(maximumCommandBytes: Int = 16_384, maximumOutputBytes: Int = 1_048_576, maximumTimeout: TimeInterval = 120) {
        self.maximumCommandBytes = maximumCommandBytes
        self.maximumOutputBytes = maximumOutputBytes
        self.maximumTimeout = maximumTimeout
    }
}

public struct DSHGuestExecutionRequest: Equatable, Sendable {
    public let id: UUID
    public let command: String
    public let timeout: TimeInterval
    public let maximumOutputBytes: Int

    public init(id: UUID = UUID(), command: String, timeout: TimeInterval, maximumOutputBytes: Int) {
        self.id = id
        self.command = command
        self.timeout = timeout
        self.maximumOutputBytes = maximumOutputBytes
    }
}

public enum DSHGuestExecutionEvent: Equatable, Sendable {
    case standardOutput(String)
    case standardError(String)
    case completed(DSHJSONValue)
}

public struct DSHGuestCapabilities: Codable, Equatable, Sendable {
    public let streamsOutput: Bool
    public let supportsCancellation: Bool

    public init(streamsOutput: Bool, supportsCancellation: Bool) {
        self.streamsOutput = streamsOutput
        self.supportsCancellation = supportsCancellation
    }
}

public struct DSHGuestRuntimeManifest: Codable, Equatable, Sendable {
    public let backendName: String
    public let backendVersion: String
    public let rootFilesystemVersion: String
    public let rootFilesystemSHA256: String
    public let compatibleCoreVersion: String
    public let license: String
    public let sourceURL: URL

    public init(backendName: String, backendVersion: String, rootFilesystemVersion: String, rootFilesystemSHA256: String, compatibleCoreVersion: String, license: String, sourceURL: URL) {
        self.backendName = backendName
        self.backendVersion = backendVersion
        self.rootFilesystemVersion = rootFilesystemVersion
        self.rootFilesystemSHA256 = rootFilesystemSHA256
        self.compatibleCoreVersion = compatibleCoreVersion
        self.license = license
        self.sourceURL = sourceURL
    }
}

public enum DSHGuestExecutionError: Error, LocalizedError, Equatable, Sendable {
    case commandTooLarge(Int)
    case outputTooLarge(Int)
    case missingCompletion

    public var errorDescription: String? {
        switch self {
        case .commandTooLarge(let limit): "Linux command exceeds the \(limit)-byte limit."
        case .outputTooLarge(let limit): "Linux output exceeds the \(limit)-byte limit."
        case .missingCompletion: "Linux execution ended without a completion result."
        }
    }
}

/// The portable boundary between Swift Harness Kit and any Linux execution
/// implementation. The framework does not depend on iSH or a particular VM.
public protocol DSHGuestHost: Sendable {
    var capabilities: DSHGuestCapabilities { get }
    var manifest: DSHGuestRuntimeManifest { get }
    func ensureReady() async throws
    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue
    func stream(request: DSHGuestExecutionRequest) -> AsyncThrowingStream<DSHGuestExecutionEvent, Error>
    func cancel(executionID: UUID) async
    func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue
}

public extension DSHGuestHost {
    var capabilities: DSHGuestCapabilities { .init(streamsOutput: false, supportsCancellation: false) }

    func stream(request: DSHGuestExecutionRequest) -> AsyncThrowingStream<DSHGuestExecutionEvent, Error> {
        AsyncThrowingStream(DSHGuestExecutionEvent.self, bufferingPolicy: .unbounded) { continuation in
            let task = Task {
                do {
                    continuation.yield(.completed(try await execute(command: request.command, timeout: request.timeout)))
                    continuation.finish()
                } catch { continuation.finish(throwing: error) }
            }
            continuation.onTermination = { _ in task.cancel() }
        }
    }

    func cancel(executionID: UUID) async {}
}

public actor DSHLazyGuestManager {
    private let host: any DSHGuestHost
    private var bootTask: Task<Void, Error>?
    private let limits: DSHGuestExecutionLimits
    public private(set) var state: DSHGuestState = .dormant

    public init(host: any DSHGuestHost, limits: DSHGuestExecutionLimits = .default) {
        self.host = host
        self.limits = limits
    }

    public nonisolated var capabilities: DSHGuestCapabilities { host.capabilities }
    public nonisolated var manifest: DSHGuestRuntimeManifest { host.manifest }

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
        var standardOutput = ""
        var standardError = ""
        var completion: DSHJSONValue?
        let request = try executionRequest(command: command, timeout: timeout)
        do {
            for try await event in try await stream(request: request) {
                try Task.checkCancellation()
                switch event {
                case .standardOutput(let value): standardOutput += value
                case .standardError(let value): standardError += value
                case .completed(let value): completion = value
                }
                guard standardOutput.utf8.count + standardError.utf8.count <= request.maximumOutputBytes else {
                    await host.cancel(executionID: request.id)
                    throw DSHGuestExecutionError.outputTooLarge(request.maximumOutputBytes)
                }
            }
        } catch {
            if error is CancellationError { await host.cancel(executionID: request.id) }
            throw error
        }
        guard var result = completion else { throw DSHGuestExecutionError.missingCompletion }
        if case .object(var values) = result {
            if values["stdout"] == nil { values["stdout"] = .string(standardOutput) }
            if values["stderr"] == nil { values["stderr"] = .string(standardError) }
            result = .object(values)
        }
        return result
    }

    public func executionRequest(command: String, timeout: TimeInterval, id: UUID = UUID()) throws -> DSHGuestExecutionRequest {
        guard command.utf8.count <= limits.maximumCommandBytes else {
            throw DSHGuestExecutionError.commandTooLarge(limits.maximumCommandBytes)
        }
        return .init(id: id, command: command, timeout: min(limits.maximumTimeout, max(1, timeout)), maximumOutputBytes: limits.maximumOutputBytes)
    }

    public func stream(request: DSHGuestExecutionRequest) async throws -> AsyncThrowingStream<DSHGuestExecutionEvent, Error> {
        try await ensureReady()
        return host.stream(request: request)
    }

    public func cancel(executionID: UUID) async { await host.cancel(executionID: executionID) }

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
