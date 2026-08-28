import Foundation
import AgentRuntime
import AgentTools
import AgentStorage
import AgentLinuxGuest

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
