import Foundation
import AgentRuntime
import AgentTools
import AgentStorage
import AgentLinuxGuest

struct DSHSystemGuestHost: DSHGuestHost, @unchecked Sendable {
    let capabilities = DSHGuestCapabilities(streamsOutput: true, supportsCancellation: true)
    let manifest: DSHGuestRuntimeManifest = {
        let checksumURL = Bundle.main.url(forResource: "root.tar.gz", withExtension: "sha256")
        let checksum = checksumURL.flatMap { try? String(contentsOf: $0, encoding: .utf8) }?
            .trimmingCharacters(in: .whitespacesAndNewlines) ?? "unavailable"
        return .init(
            backendName: "iSH64",
            backendVersion: "source-a90363a2723dc9e1c314c825b44303f8fd8a1d53",
            rootFilesystemVersion: "Alpine 3.21.0 / overlay 4 / dsh 0.1.0-rc.7",
            rootFilesystemSHA256: checksum,
            compatibleCoreVersion: ">=0.1.0 <0.2.0",
            license: "GPL-3.0",
            sourceURL: URL(string: "https://github.com/everettjf/dsh-ios")!
        )
    }()
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

    func stream(request: DSHGuestExecutionRequest) -> AsyncThrowingStream<DSHGuestExecutionEvent, Error> {
        AsyncThrowingStream(DSHGuestExecutionEvent.self, bufferingPolicy: .unbounded) { continuation in
            DSHGuestRuntime.streamCommand(request.command, executionID: request.id.uuidString, timeout: request.timeout) { line, isStandardError in
                continuation.yield(isStandardError ? .standardError(line) : .standardOutput(line))
            } completion: { data in
                do {
                    continuation.yield(.completed(try JSONDecoder().decode(DSHJSONValue.self, from: data)))
                    continuation.finish()
                } catch { continuation.finish(throwing: error) }
            }
            continuation.onTermination = { termination in
                if case .cancelled = termination { DSHGuestRuntime.cancelExecutionID(request.id.uuidString) }
            }
        }
    }

    func cancel(executionID: UUID) async { DSHGuestRuntime.cancelExecutionID(executionID.uuidString) }

    func write(data: Data, to path: String, timeout: TimeInterval) async throws -> DSHJSONValue {
        try await withCheckedThrowingContinuation { (continuation: CheckedContinuation<DSHJSONValue, Error>) in
            DSHGuestRuntime.write(data, toPath: path, timeout: timeout) { result in
                do { continuation.resume(returning: try JSONDecoder().decode(DSHJSONValue.self, from: result)) }
                catch { continuation.resume(throwing: error) }
            }
        }
    }
}


struct DSHNativeConfirmationPolicy: DSHToolApprovalPolicy, @unchecked Sendable {
    func approve(title: String, detail: String) async -> Bool {
        await Task.detached {
            DSHCallConfirmation.confirmTitle(title, detail: detail, capability: "guest.bash").rawValue == 0
        }.value
    }
}
