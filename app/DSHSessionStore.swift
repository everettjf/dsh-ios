import Foundation

enum DSHSessionTurnState: String, Codable, Equatable, Sendable {
    case idle
    case running
    case completed
    case cancelled
    case failed
    case interrupted
}

struct DSHSessionRecord: Codable, Equatable, Identifiable, Sendable {
    static let currentSchemaVersion = 2

    var schemaVersion: Int
    let id: UUID
    var title: String
    var messages: [DSHChatMessage]
    let createdAt: Date
    var updatedAt: Date
    var turnState: DSHSessionTurnState

    init(
        id: UUID,
        title: String,
        messages: [DSHChatMessage],
        createdAt: Date,
        updatedAt: Date,
        turnState: DSHSessionTurnState = .completed
    ) {
        schemaVersion = Self.currentSchemaVersion
        self.id = id
        self.title = title
        self.messages = messages
        self.createdAt = createdAt
        self.updatedAt = updatedAt
        self.turnState = turnState
    }

    private enum CodingKeys: String, CodingKey {
        case schemaVersion, id, title, messages, createdAt, updatedAt, turnState
    }

    init(from decoder: Decoder) throws {
        let values = try decoder.container(keyedBy: CodingKeys.self)
        schemaVersion = try values.decodeIfPresent(Int.self, forKey: .schemaVersion) ?? 1
        id = try values.decode(UUID.self, forKey: .id)
        title = try values.decode(String.self, forKey: .title)
        messages = try values.decode([DSHChatMessage].self, forKey: .messages)
        createdAt = try values.decode(Date.self, forKey: .createdAt)
        updatedAt = try values.decode(Date.self, forKey: .updatedAt)
        turnState = try values.decodeIfPresent(DSHSessionTurnState.self, forKey: .turnState) ?? .completed
    }
}

actor DSHSessionStore {
    private let directory: URL
    private let encoder: JSONEncoder
    private let decoder: JSONDecoder

    init(directory: URL? = nil) {
        if let directory {
            self.directory = directory
        } else {
            let support = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask)[0]
            self.directory = support.appendingPathComponent("NativeSessions", isDirectory: true)
        }
        encoder = JSONEncoder()
        encoder.dateEncodingStrategy = .iso8601
        decoder = JSONDecoder()
        decoder.dateDecodingStrategy = .iso8601
    }

    func save(_ record: DSHSessionRecord) throws {
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        let data = try encoder.encode(record)
        try data.write(to: fileURL(for: record.id), options: .atomic)
    }

    func load(id: UUID) throws -> DSHSessionRecord? {
        let url = fileURL(for: id)
        guard FileManager.default.fileExists(atPath: url.path) else { return nil }
        var record = try decoder.decode(DSHSessionRecord.self, from: Data(contentsOf: url))
        if record.schemaVersion < DSHSessionRecord.currentSchemaVersion {
            record.schemaVersion = DSHSessionRecord.currentSchemaVersion
            try save(record)
        }
        return record
    }

    func list() throws -> [DSHSessionRecord] {
        guard FileManager.default.fileExists(atPath: directory.path) else { return [] }
        let records = try FileManager.default.contentsOfDirectory(
            at: directory,
            includingPropertiesForKeys: nil,
            options: [.skipsHiddenFiles]
        )
        .filter { $0.pathExtension == "json" }
        .compactMap { url -> DSHSessionRecord? in
            guard var record = try? decoder.decode(DSHSessionRecord.self, from: Data(contentsOf: url)) else { return nil }
            if record.schemaVersion < DSHSessionRecord.currentSchemaVersion {
                record.schemaVersion = DSHSessionRecord.currentSchemaVersion
                try? save(record)
            }
            return record
        }
        return records.sorted { $0.updatedAt > $1.updatedAt }
    }

    func delete(id: UUID) throws {
        let url = fileURL(for: id)
        if FileManager.default.fileExists(atPath: url.path) {
            try FileManager.default.removeItem(at: url)
        }
    }

    private func fileURL(for id: UUID) -> URL {
        directory.appendingPathComponent(id.uuidString).appendingPathExtension("json")
    }
}
