import Foundation

enum DSHGuestState: Equatable, Sendable {
    case dormant
    case starting
    case ready
    case failed(String)
}

protocol DSHGuestHost: Sendable {
    func ensureReady() async throws
    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue
}

struct DSHSystemGuestHost: DSHGuestHost, @unchecked Sendable {
    func ensureReady() async throws {
        try await withCheckedThrowingContinuation { (continuation: CheckedContinuation<Void, Error>) in
            DSHGuestRuntime.ensureReady { error in
                if let error { continuation.resume(throwing: error) }
                else { continuation.resume() }
            }
        }
    }

    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        try await withCheckedThrowingContinuation { (continuation: CheckedContinuation<DSHJSONValue, Error>) in
            DSHGuestRuntime.executeCommand(command, timeout: timeout) { data in
                do {
                    continuation.resume(returning: try JSONDecoder().decode(DSHJSONValue.self, from: data))
                } catch {
                    continuation.resume(throwing: error)
                }
            }
        }
    }
}

actor DSHLazyGuestManager {
    private let host: any DSHGuestHost
    private var bootTask: Task<Void, Error>?
    private(set) var state: DSHGuestState = .dormant

    init(host: any DSHGuestHost = DSHSystemGuestHost()) { self.host = host }

    func ensureReady() async throws {
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

    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        try await ensureReady()
        return try await host.execute(command: command, timeout: timeout)
    }
}

protocol DSHToolApprovalPolicy: Sendable {
    func approve(title: String, detail: String) async -> Bool
}

struct DSHNativeConfirmationPolicy: DSHToolApprovalPolicy, @unchecked Sendable {
    func approve(title: String, detail: String) async -> Bool {
        await Task.detached {
            DSHCallConfirmation.confirmTitle(title, detail: detail, capability: "guest.bash").rawValue == 0
        }.value
    }
}

struct DSHBashTool: DSHNativeTool {
    let definition = DSHToolDefinition(
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

    init(manager: DSHLazyGuestManager, approval: any DSHToolApprovalPolicy = DSHNativeConfirmationPolicy()) {
        self.manager = manager
        self.approval = approval
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
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
