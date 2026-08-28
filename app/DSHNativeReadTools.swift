import Foundation
import AgentRuntime
import AgentTools
import AgentAppleTools

struct DSHInProcessRouteExecutor: DSHAppleRouteExecuting {
    func invoke(method: String, path: String, query: [String: String], json: DSHJSONValue?) async throws -> DSHJSONValue {
        let dictionary: NSDictionary?
        if let json {
            let data = try JSONEncoder().encode(json)
            dictionary = try JSONSerialization.jsonObject(with: data) as? NSDictionary
        } else {
            dictionary = nil
        }
        let data = DSHNativeCapabilityBridge.invokeMethod(method, path: path, query: query, json: dictionary as? [AnyHashable: Any])
        let envelope = try JSONDecoder().decode(DSHNativeRouteEnvelope.self, from: data)
        guard envelope.status < 400 else {
            let message = envelope.body.objectValue?["error"]?.objectValue?["message"]?.routeStringValue
                ?? "The native capability failed with status \(envelope.status)."
            if envelope.status == 403 { throw DSHToolError.permissionDenied(message) }
            throw DSHToolError.disabled(message)
        }
        return envelope.body
    }
}

private struct DSHNativeRouteEnvelope: Decodable {
    let status: Int
    let body: DSHJSONValue
}

private extension DSHJSONValue {
    var objectValue: [String: DSHJSONValue]? {
        guard case .object(let value) = self else { return nil }
        return value
    }

    var routeStringValue: String? {
        guard case .string(let value) = self else { return nil }
        return value
    }
}
