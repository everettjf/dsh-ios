import Foundation
import XCTest
import AgentRuntime
@testable import AgentStorage

final class AgentStorageTests: XCTestCase {
    private var temporaryDirectories: [URL] = []

    override func tearDownWithError() throws {
        for directory in temporaryDirectories { try? FileManager.default.removeItem(at: directory) }
        temporaryDirectories = []
    }

    func testSessionStorePersistsListsAndDeletes() async throws {
        let store = DSHSessionStore(directory: makeTemporaryDirectory())
        let now = Date()
        let first = DSHSessionRecord(
            id: UUID(), title: "First", messages: [.init(role: .user, content: "one")],
            createdAt: now, updatedAt: now
        )
        let second = DSHSessionRecord(
            id: UUID(), title: "Second", messages: [.init(role: .user, content: "two")],
            createdAt: now, updatedAt: now.addingTimeInterval(1)
        )
        try await store.save(first)
        try await store.save(second)
        let listed = try await store.list()
        let loaded = try await store.load(id: first.id)
        XCTAssertEqual(listed.map(\.id), [second.id, first.id])
        XCTAssertEqual(loaded, first)
        try await store.delete(id: first.id)
        let deleted = try await store.load(id: first.id)
        XCTAssertNil(deleted)
    }

    func testSessionStoreMigratesOlderSchemaOnLoad() async throws {
        let store = DSHSessionStore(directory: makeTemporaryDirectory())
        var record = DSHSessionRecord(
            id: UUID(), title: "Legacy", messages: [], createdAt: Date(), updatedAt: Date()
        )
        record.schemaVersion = 1
        try await store.save(record)
        let loaded = try await store.load(id: record.id)
        let migrated = try XCTUnwrap(loaded)
        XCTAssertEqual(migrated.schemaVersion, DSHSessionRecord.currentSchemaVersion)
    }

    func testSessionStoreReadsLegacyISO8601Dates() async throws {
        let directory = makeTemporaryDirectory()
        let id = UUID()
        let legacy: [String: Any] = [
            "schemaVersion": 3,
            "id": id.uuidString,
            "title": "Legacy ISO",
            "messages": [],
            "createdAt": "2026-08-28T17:44:12Z",
            "updatedAt": "2026-08-28T17:44:12.125Z",
            "turnState": "completed"
        ]
        let data = try JSONSerialization.data(withJSONObject: legacy, options: [.sortedKeys])
        try data.write(to: directory.appendingPathComponent(id.uuidString).appendingPathExtension("json"))
        let store = DSHSessionStore(directory: directory)
        let loaded = try await store.load(id: id)
        let record = try XCTUnwrap(loaded)
        XCTAssertEqual(record.schemaVersion, DSHSessionRecord.currentSchemaVersion)
        XCTAssertEqual(record.title, "Legacy ISO")
        XCTAssertEqual(record.updatedAt.timeIntervalSince(record.createdAt), 0.125, accuracy: 0.001)
    }

    func testWorkspaceImportsTextAndIsolatesSessions() async throws {
        let root = makeTemporaryDirectory()
        let source = root.appendingPathComponent("notes.txt")
        try Data("private notes".utf8).write(to: source)
        let workspace = DSHWorkspaceStore(directory: root.appendingPathComponent("workspace"))
        let session = UUID()
        let attachment = try await workspace.importFile(at: source, sessionID: session)
        XCTAssertEqual(attachment.extractedText, "private notes")
        let storedData = try await workspace.data(for: attachment, sessionID: session)
        XCTAssertEqual(storedData, Data("private notes".utf8))
        do {
            _ = try await workspace.data(for: attachment, sessionID: UUID())
            XCTFail("Expected cross-session access to fail")
        } catch {
            XCTAssertEqual(error as? DSHWorkspaceError, .attachmentMissing)
        }
    }

    func testWorkspaceRejectsEmptyAndOversizedFiles() async throws {
        let root = makeTemporaryDirectory()
        let workspace = DSHWorkspaceStore(directory: root.appendingPathComponent("workspace"))
        let empty = root.appendingPathComponent("empty.txt")
        try Data().write(to: empty)
        do {
            _ = try await workspace.importFile(at: empty, sessionID: UUID())
            XCTFail("Expected empty file rejection")
        } catch {
            XCTAssertEqual(error as? DSHWorkspaceError, .emptyFile)
        }

        let large = root.appendingPathComponent("large.bin")
        try Data(count: DSHWorkspaceStore.maximumFileBytes + 1).write(to: large)
        do {
            _ = try await workspace.importFile(at: large, sessionID: UUID())
            XCTFail("Expected oversized file rejection")
        } catch {
            XCTAssertEqual(error as? DSHWorkspaceError, .fileTooLarge(DSHWorkspaceStore.maximumFileBytes))
        }
    }

    func testWorkspacePrunesOnlyUnreferencedAttachments() async throws {
        let root = makeTemporaryDirectory()
        let source = root.appendingPathComponent("source.txt")
        try Data("text".utf8).write(to: source)
        let workspace = DSHWorkspaceStore(directory: root.appendingPathComponent("workspace"))
        let session = UUID()
        let retained = try await workspace.importFile(at: source, sessionID: session)
        let removed = try await workspace.importFile(at: source, sessionID: session)
        try await workspace.pruneOrphans(referencedAttachmentIDs: [retained.id])
        _ = try await workspace.data(for: retained, sessionID: session)
        do {
            _ = try await workspace.data(for: removed, sessionID: session)
            XCTFail("Expected orphan to be removed")
        } catch {
            XCTAssertEqual(error as? DSHWorkspaceError, .attachmentMissing)
        }
    }

    private func makeTemporaryDirectory() -> URL {
        let directory = FileManager.default.temporaryDirectory
            .appendingPathComponent("AgentStorageTests-\(UUID().uuidString)", isDirectory: true)
        try? FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        temporaryDirectories.append(directory)
        return directory
    }
}
