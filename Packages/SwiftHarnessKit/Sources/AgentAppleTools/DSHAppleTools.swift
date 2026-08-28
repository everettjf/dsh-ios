import Foundation
import AgentRuntime
import AgentTools

public protocol DSHAppleRouteExecuting: Sendable {
    func invoke(
        method: String,
        path: String,
        query: [String: String],
        json: DSHJSONValue?
    ) async throws -> DSHJSONValue
}

public enum DSHAppleReadToolKind: Sendable, CaseIterable {
    case location, contacts, calendar, reminders, health
}

public struct DSHAppleReadTool: DSHNativeTool {
    public let kind: DSHAppleReadToolKind
    private let executor: any DSHAppleRouteExecuting

    public init(_ kind: DSHAppleReadToolKind, executor: any DSHAppleRouteExecuting) {
        self.kind = kind
        self.executor = executor
    }

    public var definition: DSHToolDefinition {
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

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments else { throw DSHToolError.invalidArguments("Expected a JSON object.") }
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
            return try await executor.invoke(method: "GET", path: "/v1/reminders", query: compact(["completed": values["completed"]?.boolValue == true ? "true" : nil, "limit": integer(values["limit"], min: 1, max: 200)]), json: nil)
        case .health:
            guard let metric = values["metric"]?.stringValue,
                  ["activity", "heart_rate", "sleep", "workouts"].contains(metric) else {
                throw DSHToolError.invalidArguments("metric must be activity, heart_rate, sleep, or workouts.")
            }
            return try await executor.invoke(method: "GET", path: "/v1/health/\(metric)", query: compact(["days": integer(values["days"], min: 1, max: 366), "limit": integer(values["limit"], min: 1, max: 200)]), json: nil)
        }
    }
}

public enum DSHAppleWriteToolKind: Sendable, CaseIterable {
    case notify, calendarCreate, reminderCreate, fileImport, fileExport, photoImport, share, shortcutRun
}

public struct DSHAppleWriteTool: DSHNativeTool {
    public let kind: DSHAppleWriteToolKind
    private let executor: any DSHAppleRouteExecuting

    public init(_ kind: DSHAppleWriteToolKind, executor: any DSHAppleRouteExecuting) {
        self.kind = kind
        self.executor = executor
    }

    public var definition: DSHToolDefinition {
        switch kind {
        case .notify: return Self.make("notify", "Send a local notification after the user confirms.", strings("title", "body"), ["title"])
        case .calendarCreate: return Self.make("calendar_create_event", "Create an event in the default calendar after showing a confirmation.", strings("title", "start", "end", "location", "notes").merging(["allDay": boolean]) { first, _ in first }, ["title", "start"])
        case .reminderCreate: return Self.make("reminders_create", "Create a reminder after showing a confirmation.", strings("title", "due", "notes"), ["title"])
        case .fileImport: return Self.make("file_import", "Open the document picker so the user can explicitly provide one file.", [:], [])
        case .fileExport: return Self.make("file_export", "Save a base64-encoded file after confirmation, up to 8 MB.", strings("name", "base64"), ["name", "base64"])
        case .photoImport: return Self.make("photo_import", "Open the photo picker so the user can explicitly provide one image.", [:], [])
        case .share: return Self.make("share", "Offer bounded text to the iOS share sheet after confirmation.", strings("text"), ["text"])
        case .shortcutRun: return Self.make("shortcut_run", "Run a named Shortcut after confirmation; this may leave the app.", strings("name", "input"), ["name"])
        }
    }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments else { throw DSHToolError.invalidArguments("Expected a JSON object.") }
        let route: String
        switch kind {
        case .notify: try require(values, "title"); route = "/v1/notify"
        case .calendarCreate: try require(values, "title"); try require(values, "start"); route = "/v1/calendar/events"
        case .reminderCreate: try require(values, "title"); route = "/v1/reminders"
        case .fileImport:
            guard values.isEmpty else { throw DSHToolError.invalidArguments("file_import accepts an empty object.") }; route = "/v1/files/import"
        case .fileExport: try require(values, "name"); try require(values, "base64"); route = "/v1/files/export"
        case .photoImport:
            guard values.isEmpty else { throw DSHToolError.invalidArguments("photo_import accepts an empty object.") }; route = "/v1/photos/import"
        case .share:
            guard try require(values, "text").count <= 4_000 else { throw DSHToolError.invalidArguments("text must be at most 4000 characters.") }; route = "/v1/share"
        case .shortcutRun: try require(values, "name"); route = "/v1/shortcut/run"
        }
        return try await executor.invoke(method: "POST", path: route, query: [:], json: .object(values))
    }
}

private extension DSHAppleReadTool {
    func integer(_ value: DSHJSONValue?, min: Int, max: Int) -> String? {
        guard case .number(let number) = value, number.rounded() == number, number >= Double(min), number <= Double(max) else { return nil }
        return String(Int(number))
    }

    func compact(_ values: [String: String?]) -> [String: String] { values.compactMapValues { $0 } }

    static func definition(_ name: String, _ description: String, _ properties: [String: DSHJSONValue], required: [String]) -> DSHToolDefinition {
        var schema: [String: DSHJSONValue] = ["type": .string("object"), "properties": .object(properties), "additionalProperties": .bool(false)]
        if !required.isEmpty { schema["required"] = .array(required.map(DSHJSONValue.string)) }
        return .init(name: name, description: description, parameters: .object(schema))
    }
}

private extension DSHAppleWriteTool {
    @discardableResult
    func require(_ values: [String: DSHJSONValue], _ key: String) throws -> String {
        guard case .string(let value) = values[key], !value.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty else {
            throw DSHToolError.invalidArguments("\(key) is required.")
        }
        return value
    }

    var boolean: DSHJSONValue { .object(["type": .string("boolean")]) }
    func strings(_ names: String...) -> [String: DSHJSONValue] {
        Dictionary(uniqueKeysWithValues: names.map { ($0, .object(["type": .string("string")])) })
    }
    static func make(_ name: String, _ description: String, _ properties: [String: DSHJSONValue], _ required: [String]) -> DSHToolDefinition {
        var schema: [String: DSHJSONValue] = ["type": .string("object"), "properties": .object(properties), "additionalProperties": .bool(false)]
        if !required.isEmpty { schema["required"] = .array(required.map(DSHJSONValue.string)) }
        return .init(name: name, description: description, parameters: .object(schema))
    }
}

private extension DSHJSONValue {
    var stringValue: String? { guard case .string(let value) = self else { return nil }; return value }
    var boolValue: Bool? { guard case .bool(let value) = self else { return nil }; return value }
}
