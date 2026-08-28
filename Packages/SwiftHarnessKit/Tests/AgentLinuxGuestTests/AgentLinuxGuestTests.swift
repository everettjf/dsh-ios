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

    init(bootDelay: UInt64 = 0) { self.bootDelay = bootDelay }

    func ensureReady() async throws {
        bootCount += 1
        if bootDelay > 0 { try await Task.sleep(nanoseconds: bootDelay) }
    }

    func execute(command: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        lastCommand = (command, timeout)
        return .object(["exit_code": .number(0)])
    }

    func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        .object(["exit_code": .number(0)])
    }
}
