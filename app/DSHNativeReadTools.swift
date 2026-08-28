import Foundation
import AgentRuntime
import AgentTools

protocol DSHNativeRouteExecuting: Sendable {
    func invoke(method: String, path: String, query: [String: String], json: DSHJSONValue?) async throws -> DSHJSONValue
}

struct DSHInProcessRouteExecutor: DSHNativeRouteExecuting {
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
            let message = envelope.body.objectValue?["error"]?.objectValue?["message"]?.stringValue
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

enum DSHNativeReadToolKind: Sendable {
    case location
    case contacts
    case calendar
    case reminders
    case health
}

struct DSHNativeReadTool: DSHNativeTool {
    let kind: DSHNativeReadToolKind
    let executor: any DSHNativeRouteExecuting

    init(_ kind: DSHNativeReadToolKind, executor: any DSHNativeRouteExecuting = DSHInProcessRouteExecutor()) {
        self.kind = kind
        self.executor = executor
    }

    var definition: DSHToolDefinition {
        switch kind {
        case .location:
            return Self.definition("location_query", "Get one fresh location fix with accuracy; never tracks in the background.", [:], required: [])
        case .contacts:
            return Self.definition("contacts_search", "Search contacts by a required name; listing the whole address book is not supported.", [
                "query": .object(["type": .string("string"), "description": .string("Name to search for.")]),
                "limit": .object(["type": .string("number"), "description": .string("Maximum matches, up to 25.")])
            ], required: ["query"])
        case .calendar:
            return Self.definition("calendar_query", "Read calendar events in a bounded date window.", [
                "days": .object(["type": .string("number"), "description": .string("Days ahead; negative reads the past. Maximum 366.")]),
                "limit": .object(["type": .string("number"), "description": .string("Maximum events, up to 200.")])
            ], required: [])
        case .reminders:
            return Self.definition("reminders_query", "Read reminders, optionally including completed items.", [
                "completed": .object(["type": .string("boolean")]),
                "limit": .object(["type": .string("number"), "description": .string("Maximum reminders, up to 200.")])
            ], required: [])
        case .health:
            return Self.definition("health_query", "Read one bounded Apple Health metric. Empty data may mean no samples or declined read access.", [
                "metric": .object(["type": .string("string"), "enum": .array([.string("activity"), .string("heart_rate"), .string("sleep"), .string("workouts")])]),
                "days": .object(["type": .string("number"), "description": .string("Days back, up to 366.")]),
                "limit": .object(["type": .string("number"), "description": .string("Maximum workouts, up to 200.")])
            ], required: ["metric"])
        }
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments else {
            throw DSHToolError.invalidArguments("Expected a JSON object.")
        }
        switch kind {
        case .location:
            guard values.isEmpty else { throw DSHToolError.invalidArguments("location_query accepts an empty object.") }
            return try await executor.invoke(method: "GET", path: "/v1/location", query: [:], json: nil)
        case .contacts:
            guard let name = values["query"]?.stringValue?.trimmingCharacters(in: .whitespacesAndNewlines), !name.isEmpty else {
                throw DSHToolError.invalidArguments("query is required: name the person to look up.")
            }
            return try await executor.invoke(method: "GET", path: "/v1/contacts", query: compact(["q": name, "limit": integer(values["limit"], min: 1, max: 25)]), json: nil)
        case .calendar:
            return try await executor.invoke(method: "GET", path: "/v1/calendar/events", query: compact(["days": integer(values["days"], min: -366, max: 366), "limit": integer(values["limit"], min: 1, max: 200)]), json: nil)
        case .reminders:
            let completed = values["completed"]?.boolValue == true ? "true" : nil
            return try await executor.invoke(method: "GET", path: "/v1/reminders", query: compact(["completed": completed, "limit": integer(values["limit"], min: 1, max: 200)]), json: nil)
        case .health:
            guard let metric = values["metric"]?.stringValue,
                  ["activity", "heart_rate", "sleep", "workouts"].contains(metric) else {
                throw DSHToolError.invalidArguments("metric must be activity, heart_rate, sleep, or workouts.")
            }
            return try await executor.invoke(method: "GET", path: "/v1/health/\(metric)", query: compact(["days": integer(values["days"], min: 1, max: 366), "limit": integer(values["limit"], min: 1, max: 200)]), json: nil)
        }
    }

    private func integer(_ value: DSHJSONValue?, min: Int, max: Int) -> String? {
        guard case .number(let number) = value, number.rounded() == number, number >= Double(min), number <= Double(max) else { return nil }
        return String(Int(number))
    }

    private func compact(_ values: [String: String?]) -> [String: String] {
        values.compactMapValues { $0 }
    }

    private static func definition(_ name: String, _ description: String, _ properties: [String: DSHJSONValue], required: [String]) -> DSHToolDefinition {
        var schema: [String: DSHJSONValue] = [
            "type": .string("object"),
            "properties": .object(properties),
            "additionalProperties": .bool(false)
        ]
        if !required.isEmpty { schema["required"] = .array(required.map(DSHJSONValue.string)) }
        return DSHToolDefinition(name: name, description: description, parameters: .object(schema))
    }
}

private extension DSHJSONValue {
    var objectValue: [String: DSHJSONValue]? {
        guard case .object(let value) = self else { return nil }
        return value
    }

    var stringValue: String? {
        guard case .string(let value) = self else { return nil }
        return value
    }

    var boolValue: Bool? {
        guard case .bool(let value) = self else { return nil }
        return value
    }
}
