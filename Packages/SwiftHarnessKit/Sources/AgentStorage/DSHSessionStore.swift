import Foundation
import UniformTypeIdentifiers
#if canImport(AgentRuntime)
import AgentRuntime
#endif

public enum DSHWorkspaceError: Error, LocalizedError, Equatable {
    case fileTooLarge(Int)
    case emptyFile
    case unreadableFile
    case attachmentMissing

    public var errorDescription: String? {
        switch self {
        case .fileTooLarge(let maximum): return "Attachments must be smaller than \(maximum / 1_048_576) MB."
        case .emptyFile: return "The selected file is empty."
        case .unreadableFile: return "The selected file could not be read."
        case .attachmentMissing: return "The attachment is no longer available on this device."
        }
    }
}

public actor DSHWorkspaceStore {
    public static let maximumFileBytes = 8 * 1_024 * 1_024
    public static let maximumExtractedTextCharacters = 128_000
    private let directory: URL

    public init(directory: URL? = nil) {
        if let directory { self.directory = directory }
        else {
            let support = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask)[0]
            self.directory = support.appendingPathComponent("NativeWorkspace", isDirectory: true)
        }
    }

    public func importFile(at url: URL, sessionID: UUID) throws -> DSHAttachment {
        let access = url.startAccessingSecurityScopedResource()
        defer { if access { url.stopAccessingSecurityScopedResource() } }
        guard let values = try? url.resourceValues(forKeys: [.fileSizeKey, .contentTypeKey, .nameKey]),
              let size = values.fileSize else { throw DSHWorkspaceError.unreadableFile }
        guard size > 0 else { throw DSHWorkspaceError.emptyFile }
        guard size <= Self.maximumFileBytes else { throw DSHWorkspaceError.fileTooLarge(Self.maximumFileBytes) }
        let data: Data
        do { data = try Data(contentsOf: url, options: .mappedIfSafe) }
        catch { throw DSHWorkspaceError.unreadableFile }
        guard data.count == size else { throw DSHWorkspaceError.unreadableFile }

        let id = UUID()
        let sessionDirectory = directory.appendingPathComponent(sessionID.uuidString, isDirectory: true)
        try FileManager.default.createDirectory(at: sessionDirectory, withIntermediateDirectories: true)
        try data.write(to: fileURL(sessionID: sessionID, attachmentID: id), options: .atomic)
        let type = values.contentType ?? UTType(filenameExtension: url.pathExtension) ?? .data
        return DSHAttachment(
            id: id,
            name: Self.displayName(values.name ?? url.lastPathComponent),
            mediaType: type.preferredMIMEType ?? "application/octet-stream",
            byteCount: data.count,
            extractedText: Self.extractText(data: data, type: type)
        )
    }

    public func data(for attachment: DSHAttachment, sessionID: UUID) throws -> Data {
        let url = fileURL(sessionID: sessionID, attachmentID: attachment.id)
        guard FileManager.default.fileExists(atPath: url.path) else { throw DSHWorkspaceError.attachmentMissing }
        return try Data(contentsOf: url, options: .mappedIfSafe)
    }

    public func data(attachmentID: UUID, sessionID: UUID) throws -> Data {
        let url = fileURL(sessionID: sessionID, attachmentID: attachmentID)
        guard FileManager.default.fileExists(atPath: url.path) else { throw DSHWorkspaceError.attachmentMissing }
        return try Data(contentsOf: url, options: .mappedIfSafe)
    }

    public func delete(_ attachment: DSHAttachment, sessionID: UUID) throws {
        let url = fileURL(sessionID: sessionID, attachmentID: attachment.id)
        if FileManager.default.fileExists(atPath: url.path) { try FileManager.default.removeItem(at: url) }
    }

    public func deleteSession(_ sessionID: UUID) throws {
        let url = directory.appendingPathComponent(sessionID.uuidString, isDirectory: true)
        if FileManager.default.fileExists(atPath: url.path) { try FileManager.default.removeItem(at: url) }
    }

    public func pruneOrphans(referencedAttachmentIDs: Set<UUID>) throws {
        guard FileManager.default.fileExists(atPath: directory.path) else { return }
        let sessionDirectories = try FileManager.default.contentsOfDirectory(
            at: directory,
            includingPropertiesForKeys: [.isDirectoryKey],
            options: [.skipsHiddenFiles]
        )
        for sessionDirectory in sessionDirectories {
            let files = (try? FileManager.default.contentsOfDirectory(
                at: sessionDirectory,
                includingPropertiesForKeys: nil,
                options: [.skipsHiddenFiles]
            )) ?? []
            for file in files {
                guard let id = UUID(uuidString: file.lastPathComponent), referencedAttachmentIDs.contains(id) else {
                    try? FileManager.default.removeItem(at: file)
                    continue
                }
            }
            if (try? FileManager.default.contentsOfDirectory(atPath: sessionDirectory.path).isEmpty) == true {
                try? FileManager.default.removeItem(at: sessionDirectory)
            }
        }
    }

    private func fileURL(sessionID: UUID, attachmentID: UUID) -> URL {
        directory.appendingPathComponent(sessionID.uuidString, isDirectory: true)
            .appendingPathComponent(attachmentID.uuidString, isDirectory: false)
    }

    private static func displayName(_ value: String) -> String {
        let name = value.replacingOccurrences(of: "\\", with: "/").split(separator: "/").last.map(String.init) ?? "Attachment"
        let cleaned = name.unicodeScalars.filter { !CharacterSet.controlCharacters.contains($0) }.map(String.init).joined()
        return String((cleaned.isEmpty ? "Attachment" : cleaned).prefix(160))
    }

    private static func extractText(data: Data, type: UTType) -> String? {
        guard type.conforms(to: .plainText) || type.conforms(to: .json) || type.conforms(to: .sourceCode) else { return nil }
        guard var text = String(data: data, encoding: .utf8) else { return nil }
        if text.count > maximumExtractedTextCharacters {
            text = String(text.prefix(maximumExtractedTextCharacters)) + "\n[Attachment text truncated]"
        }
        return text
    }
}

public enum DSHSessionTurnState: String, Codable, Equatable, Sendable {
    case idle
    case running
    case completed
    case cancelled
    case failed
    case interrupted
}

public struct DSHSessionRecord: Codable, Equatable, Identifiable, Sendable {
    public static let currentSchemaVersion = 4

    public var schemaVersion: Int
    public let id: UUID
    public var title: String
    public var messages: [DSHChatMessage]
    public let createdAt: Date
    public var updatedAt: Date
    public var turnState: DSHSessionTurnState

    public init(
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

    public init(from decoder: Decoder) throws {
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

public actor DSHSessionStore {
    private let directory: URL
    private let encoder: JSONEncoder
    private let decoder: JSONDecoder

    public init(directory: URL? = nil) {
        if let directory {
            self.directory = directory
        } else {
            let support = FileManager.default.urls(for: .applicationSupportDirectory, in: .userDomainMask)[0]
            self.directory = support.appendingPathComponent("NativeSessions", isDirectory: true)
        }
        encoder = JSONEncoder()
        // Preserve the exact Date payload. ISO-8601's default formatter drops
        // subsecond precision, so a save/load round-trip was not value-equal.
        encoder.dateEncodingStrategy = .custom { date, encoder in
            var container = encoder.singleValueContainer()
            try container.encode(date.timeIntervalSinceReferenceDate)
        }
        decoder = JSONDecoder()
        decoder.dateDecodingStrategy = .custom { decoder in
            let container = try decoder.singleValueContainer()
            if let interval = try? container.decode(Double.self) {
                return Date(timeIntervalSinceReferenceDate: interval)
            }
            let legacy = try container.decode(String.self)
            if let value = try? Date.ISO8601FormatStyle(includingFractionalSeconds: true).parse(legacy) {
                return value
            }
            if let value = try? Date.ISO8601FormatStyle().parse(legacy) {
                return value
            }
            throw DecodingError.dataCorruptedError(in: container, debugDescription: "Invalid session date")
        }
    }

    public func save(_ record: DSHSessionRecord) throws {
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        let data = try encoder.encode(record)
        try data.write(to: fileURL(for: record.id), options: .atomic)
    }

    public func load(id: UUID) throws -> DSHSessionRecord? {
        let url = fileURL(for: id)
        guard FileManager.default.fileExists(atPath: url.path) else { return nil }
        var record = try decoder.decode(DSHSessionRecord.self, from: Data(contentsOf: url))
        if record.schemaVersion < DSHSessionRecord.currentSchemaVersion {
            record.schemaVersion = DSHSessionRecord.currentSchemaVersion
            try save(record)
        }
        return record
    }

    public func list() throws -> [DSHSessionRecord] {
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

    public func delete(id: UUID) throws {
        let url = fileURL(for: id)
        if FileManager.default.fileExists(atPath: url.path) {
            try FileManager.default.removeItem(at: url)
        }
    }

    private func fileURL(for id: UUID) -> URL {
        directory.appendingPathComponent(id.uuidString).appendingPathExtension("json")
    }
}
