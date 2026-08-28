import Foundation

enum DSHNativeWriteToolKind: Sendable, CaseIterable {
    case notify, calendarCreate, reminderCreate, fileImport, fileExport, photoImport, share, shortcutRun
}

struct DSHNativeWriteTool: DSHNativeTool {
    let kind: DSHNativeWriteToolKind
    let executor: any DSHNativeRouteExecuting

    init(_ kind: DSHNativeWriteToolKind, executor: any DSHNativeRouteExecuting = DSHInProcessRouteExecutor()) {
        self.kind = kind
        self.executor = executor
    }

    var definition: DSHToolDefinition {
        switch kind {
        case .notify: return Self.make("notify", "Send a local notification after the user confirms.", strings("title", "body"), ["title"])
        case .calendarCreate:
            return Self.make("calendar_create_event", "Create an event in the default calendar after showing a confirmation.", strings("title", "start", "end", "location", "notes").merging(["allDay": boolean]) { a, _ in a }, ["title", "start"])
        case .reminderCreate: return Self.make("reminders_create", "Create a reminder after showing a confirmation.", strings("title", "due", "notes"), ["title"])
        case .fileImport: return Self.make("file_import", "Open the document picker so the user can explicitly provide one file.", [:], [])
        case .fileExport: return Self.make("file_export", "Save a base64-encoded file after confirmation, up to 8 MB.", strings("name", "base64"), ["name", "base64"])
        case .photoImport: return Self.make("photo_import", "Open the photo picker so the user can explicitly provide one image.", [:], [])
        case .share: return Self.make("share", "Offer bounded text to the iOS share sheet after confirmation.", strings("text"), ["text"])
        case .shortcutRun: return Self.make("shortcut_run", "Run a named Shortcut after confirmation; this may leave the app.", strings("name", "input"), ["name"])
        }
    }

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments else { throw DSHToolError.invalidArguments("Expected a JSON object.") }
        let route: String
        switch kind {
        case .notify:
            try require(values, "title"); route = "/v1/notify"
        case .calendarCreate:
            try require(values, "title"); try require(values, "start"); route = "/v1/calendar/events"
        case .reminderCreate:
            try require(values, "title"); route = "/v1/reminders"
        case .fileImport:
            guard values.isEmpty else { throw DSHToolError.invalidArguments("file_import accepts an empty object.") }
            route = "/v1/files/import"
        case .fileExport:
            try require(values, "name"); try require(values, "base64"); route = "/v1/files/export"
        case .photoImport:
            guard values.isEmpty else { throw DSHToolError.invalidArguments("photo_import accepts an empty object.") }
            route = "/v1/photos/import"
        case .share:
            let text = try require(values, "text")
            guard text.count <= 4_000 else { throw DSHToolError.invalidArguments("text must be at most 4000 characters.") }
            route = "/v1/share"
        case .shortcutRun:
            try require(values, "name"); route = "/v1/shortcut/run"
        }
        return try await executor.invoke(method: "POST", path: route, query: [:], json: .object(values))
    }

    @discardableResult
    private func require(_ values: [String: DSHJSONValue], _ key: String) throws -> String {
        guard case .string(let value) = values[key], !value.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty else {
            throw DSHToolError.invalidArguments("\(key) is required.")
        }
        return value
    }

    private var boolean: DSHJSONValue { .object(["type": .string("boolean")]) }
    private func strings(_ names: String...) -> [String: DSHJSONValue] {
        Dictionary(uniqueKeysWithValues: names.map { ($0, .object(["type": .string("string")])) })
    }
    private static func make(_ name: String, _ description: String, _ properties: [String: DSHJSONValue], _ required: [String]) -> DSHToolDefinition {
        var schema: [String: DSHJSONValue] = ["type": .string("object"), "properties": .object(properties), "additionalProperties": .bool(false)]
        if !required.isEmpty { schema["required"] = .array(required.map(DSHJSONValue.string)) }
        return .init(name: name, description: description, parameters: .object(schema))
    }
}
