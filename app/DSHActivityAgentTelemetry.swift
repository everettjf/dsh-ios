import Foundation
import AgentRuntime

/// SHOS adapter from the reusable runtime telemetry protocol to the
/// Objective-C activity log. This deliberately remains outside AgentRuntime.
struct DSHActivityAgentTelemetry: DSHAgentTelemetry, @unchecked Sendable {
    func started(source: String, name: String, detail: String, correlationID: String) async {
        DSHNativeToolAudit.recordStarted(withSource: source, name: name, detail: detail, correlationID: correlationID)
    }

    func finished(
        source: String, name: String, detail: String, result: String, outcome: String,
        duration: TimeInterval, correlationID: String
    ) async {
        DSHNativeToolAudit.recordFinished(
            withSource: source, name: name, detail: detail, result: result,
            outcome: outcome, duration: duration, correlationID: correlationID
        )
    }
}
