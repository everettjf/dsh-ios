import Foundation
import Testing
import AgentRuntime
import AgentTools
import AgentStorage
@testable import AgentLinuxGuest

@Suite("AgentLinuxGuest")
struct AgentLinuxGuestTests {
    @Test("concurrent callers coalesce the lazy boot")
    func coalescesBoot() async throws {
        let host = FakeGuestHost(bootDelay: 20_000_000)
        let manager = DSHLazyGuestManager(host: host)
        async let first: Void = manager.ensureReady()
        async let second: Void = manager.ensureReady()
        _ = try await (first, second)
        #expect(await manager.state == .ready)
        #expect(await host.bootCount == 1)
    }

    @Test("declined bash approval never boots Linux")
    func declineDoesNotBoot() async throws {
        let host = FakeGuestHost()
        let manager = DSHLazyGuestManager(host: host)
        let tool = DSHBashTool(manager: manager, approval: FixedApproval(approved: false))
        await #expect(throws: DSHToolError.disabled("bash command (not approved)")) {
            _ = try await tool.execute(arguments: .object(["command": .string("touch file")]))
        }
        #expect(await host.bootCount == 0)
    }

    @Test("bash clamps timeout and executes after approval")
    func bashExecutes() async throws {
        let host = FakeGuestHost()
        let manager = DSHLazyGuestManager(host: host)
        let tool = DSHBashTool(manager: manager, approval: FixedApproval(approved: true))
        _ = try await tool.execute(arguments: .object([
            "command": .string("pwd"),
            "timeout_seconds": .number(999)
        ]))
        let call = await host.lastCommand
        #expect(call?.command == "pwd")
        #expect(call?.timeout == 120)
        #expect(await host.bootCount == 1)
    }

    @Test("execution applies command, timeout, and output quotas")
    func quotas() async throws {
        let host = FakeGuestHost()
        let manager = DSHLazyGuestManager(
            host: host,
            limits: .init(maximumCommandBytes: 4, maximumOutputBytes: 5, maximumTimeout: 10)
        )
        await #expect(throws: DSHGuestExecutionError.commandTooLarge(4)) {
            _ = try await manager.execute(command: "12345", timeout: 1)
        }
        let request = try await manager.executionRequest(command: "pwd", timeout: 99)
        #expect(request.timeout == 10)

        await host.setEvents([.standardOutput("123456"), .completed(.object(["exit_code": .number(0)]))])
        await #expect(throws: DSHGuestExecutionError.outputTooLarge(5)) {
            _ = try await manager.execute(command: "pwd", timeout: 1)
        }
        #expect(await host.cancelledExecutionIDs.count == 1)
    }

    @Test("streaming preserves stdout, stderr, and manifest metadata")
    func streamingAndManifest() async throws {
        let host = FakeGuestHost()
        await host.setEvents([
            .standardOutput("out\n"), .standardError("err\n"),
            .completed(.object(["exit_code": .number(0)]))
        ])
        let manager = DSHLazyGuestManager(host: host)
        let result = try await manager.execute(command: "pwd", timeout: 3)
        #expect(result == .object(["exit_code": .number(0), "stdout": .string("out\n"), "stderr": .string("err\n")]))
        #expect(manager.manifest.license == "GPL-3.0")
        #expect(manager.capabilities.streamsOutput)
    }

    @Test("attachment staging preserves session isolation")
    func attachmentIsolation() async throws {
        let directory = FileManager.default.temporaryDirectory
            .appendingPathComponent("AgentLinuxGuestTests-\(UUID().uuidString)", isDirectory: true)
        defer { try? FileManager.default.removeItem(at: directory) }
        let source = directory.appendingPathComponent("source.txt")
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        try Data("private".utf8).write(to: source)
        let workspace = DSHWorkspaceStore(directory: directory.appendingPathComponent("workspace"))
        let owner = UUID()
        let attachment = try await workspace.importFile(at: source, sessionID: owner)
        let host = FakeGuestHost()
        let tool = DSHStageAttachmentTool(
            manager: DSHLazyGuestManager(host: host),
            workspace: workspace,
            context: DSHActiveWorkspaceContext(sessionID: UUID())
        )
        await #expect(throws: DSHWorkspaceError.attachmentMissing) {
            _ = try await tool.execute(arguments: .object(["attachment_id": .string(attachment.id.uuidString)]))
        }
        #expect(await host.bootCount == 0)
    }
}

private struct FixedApproval: DSHToolApprovalPolicy {
    let approved: Bool
    func approve(title: String, detail: String) async -> Bool { approved }
}

private actor FakeGuestHost: DSHGuestHost {
    private(set) var bootCount = 0
    private(set) var lastCommand: (command: String, timeout: TimeInterval)?
    private let bootDelay: UInt64
    private var events: [DSHGuestExecutionEvent] = []
    private(set) var cancelledExecutionIDs: [UUID] = []
    nonisolated let capabilities = DSHGuestCapabilities(streamsOutput: true, supportsCancellation: true)
    nonisolated let manifest = DSHGuestRuntimeManifest(
        backendName: "Fake", backendVersion: "1", rootFilesystemVersion: "1",
        rootFilesystemSHA256: "abc", compatibleCoreVersion: ">=0.1.0 <0.2.0",
        license: "GPL-3.0", sourceURL: URL(string: "https://example.com/source")!
    )

    init(bootDelay: UInt64 = 0) { self.bootDelay = bootDelay }

    func ensureReady() async throws {
        bootCount += 1
        if bootDelay > 0 { try await Task.sleep(nanoseconds: bootDelay) }
    }

    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        lastCommand = (command, timeout)
        return .object(["exit_code": .number(0)])
    }

    func setEvents(_ events: [DSHGuestExecutionEvent]) { self.events = events }

    nonisolated func stream(request: DSHGuestExecutionRequest) -> AsyncThrowingStream<DSHGuestExecutionEvent, Error> {
        AsyncThrowingStream(DSHGuestExecutionEvent.self, bufferingPolicy: .unbounded) { continuation in
            Task {
                let events = await self.events
                if events.isEmpty {
                    continuation.yield(.completed(try! await self.execute(command: request.command, timeout: request.timeout)))
                } else {
                    for event in events { continuation.yield(event) }
                }
                continuation.finish()
            }
        }
    }

    func cancel(executionID: UUID) { cancelledExecutionIDs.append(executionID) }

    func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        .object(["exit_code": .number(0)])
    }
}
