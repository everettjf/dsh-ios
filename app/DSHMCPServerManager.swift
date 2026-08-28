import Foundation
import Security
import AgentRuntime
import AgentMCP
import AgentTools

struct DSHMCPServerConfiguration: Identifiable, Equatable, Sendable {
    var id: UUID
    var name: String
    var endpoint: String
    var bearerToken: String
    var isEnabled: Bool

    init(id: UUID = UUID(), name: String, endpoint: String, bearerToken: String = "", isEnabled: Bool = true) {
        self.id = id
        self.name = name
        self.endpoint = endpoint
        self.bearerToken = bearerToken
        self.isEnabled = isEnabled
    }
}

enum DSHMCPServerConfigurationStore {
    private struct Metadata: Codable {
        let id: UUID
        let name: String
        let endpoint: String
        let isEnabled: Bool
    }
    private static let defaultsKey = "native.agent.mcp-servers"
    private static let keychainService = "com.xnuapp.dsh.mcp"

    static func load() -> [DSHMCPServerConfiguration] {
        guard let data = UserDefaults.standard.data(forKey: defaultsKey),
              let metadata = try? JSONDecoder().decode([Metadata].self, from: data) else { return [] }
        return metadata.map { .init(id: $0.id, name: $0.name, endpoint: $0.endpoint, bearerToken: token(for: $0.id), isEnabled: $0.isEnabled) }
    }

    static func save(_ configurations: [DSHMCPServerConfiguration]) throws {
        let metadata = configurations.map { Metadata(id: $0.id, name: $0.name, endpoint: $0.endpoint, isEnabled: $0.isEnabled) }
        UserDefaults.standard.set(try JSONEncoder().encode(metadata), forKey: defaultsKey)
        for configuration in configurations { try saveToken(configuration.bearerToken, for: configuration.id) }
    }

    private static func token(for id: UUID) -> String {
        let query = baseQuery(id).merging([kSecReturnData as String: true, kSecMatchLimit as String: kSecMatchLimitOne]) { _, value in value }
        var result: CFTypeRef?
        guard SecItemCopyMatching(query as CFDictionary, &result) == errSecSuccess, let data = result as? Data else { return "" }
        return String(decoding: data, as: UTF8.self)
    }

    private static func saveToken(_ token: String, for id: UUID) throws {
        let query = baseQuery(id)
        SecItemDelete(query as CFDictionary)
        guard !token.isEmpty else { return }
        let item = query.merging([
            kSecValueData as String: Data(token.utf8),
            kSecAttrAccessible as String: kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
        ]) { _, value in value }
        let status = SecItemAdd(item as CFDictionary, nil)
        guard status == errSecSuccess else { throw NSError(domain: NSOSStatusErrorDomain, code: Int(status)) }
    }

    private static func baseQuery(_ id: UUID) -> [String: Any] {
        [kSecClass as String: kSecClassGenericPassword, kSecAttrService as String: keychainService, kSecAttrAccount as String: id.uuidString]
    }
}

enum DSHMCPConnectionState: Equatable, Sendable {
    case disabled
    case connecting
    case connected(toolCount: Int)
    case failed(String)
}

struct DSHMCPServerStatus: Identifiable, Equatable, Sendable {
    let id: UUID
    let name: String
    let state: DSHMCPConnectionState
}

actor DSHMCPServerManager {
    private let registry: DSHToolRegistry
    private let telemetry: any DSHAgentTelemetry
    private var statuses: [UUID: DSHMCPServerStatus] = [:]
    private var clients: [UUID: DSHMCPClient] = [:]

    init(registry: DSHToolRegistry, telemetry: any DSHAgentTelemetry = DSHActivityAgentTelemetry()) {
        self.registry = registry
        self.telemetry = telemetry
    }

    func refresh(_ configurations: [DSHMCPServerConfiguration]) async -> [DSHMCPServerStatus] {
        for client in clients.values { await client.disconnect() }
        clients.removeAll()
        registry.replaceTools(withPrefix: "mcp__", with: [])
        var tools: [any DSHNativeTool] = []
        var next: [UUID: DSHMCPServerStatus] = [:]
        var usedNames = Set<String>()
        for configuration in configurations {
            guard configuration.isEnabled else {
                next[configuration.id] = .init(id: configuration.id, name: configuration.name, state: .disabled)
                continue
            }
            next[configuration.id] = .init(id: configuration.id, name: configuration.name, state: .connecting)
            let connectionID = UUID().uuidString
            let connectionDetail = "server_id=\(configuration.id.uuidString.prefix(8))"
            let clock = ContinuousClock()
            let startedAt = clock.now
            await telemetry.started(source: "mcp", name: "mcp.connect", detail: connectionDetail, correlationID: connectionID)
            guard let endpoint = URL(string: configuration.endpoint), endpoint.scheme == "https" || Self.isLocalHTTP(endpoint) else {
                next[configuration.id] = .init(id: configuration.id, name: configuration.name, state: .failed("Use HTTPS, or HTTP only for localhost."))
                await telemetry.finished(source: "mcp", name: "mcp.connect", detail: connectionDetail, result: "error=invalid_endpoint", outcome: "error", duration: Self.seconds(startedAt.duration(to: clock.now)), correlationID: connectionID)
                continue
            }
            let serverName = Self.uniqueName(configuration.name, id: configuration.id, used: &usedNames)
            let headers = configuration.bearerToken.isEmpty ? [:] : ["Authorization": "Bearer \(configuration.bearerToken)"]
            let client = DSHMCPClient(endpoint: endpoint, headers: headers)
            do {
                try await client.connect()
                let descriptions = try await client.listTools()
                tools.append(contentsOf: descriptions.map {
                    DSHAuditedTool(
                        DSHMCPTool(serverName: serverName, description: $0, client: client),
                        source: "mcp", auditName: "mcp.tool"
                    )
                })
                clients[configuration.id] = client
                next[configuration.id] = .init(id: configuration.id, name: configuration.name, state: .connected(toolCount: descriptions.count))
                await telemetry.finished(source: "mcp", name: "mcp.connect", detail: connectionDetail, result: "tools=\(descriptions.count)", outcome: "ok", duration: Self.seconds(startedAt.duration(to: clock.now)), correlationID: connectionID)
            } catch {
                next[configuration.id] = .init(id: configuration.id, name: configuration.name, state: .failed(error.localizedDescription))
                await telemetry.finished(source: "mcp", name: "mcp.connect", detail: connectionDetail, result: "error=\(Self.errorCategory(error))", outcome: "error", duration: Self.seconds(startedAt.duration(to: clock.now)), correlationID: connectionID)
            }
        }
        registry.replaceTools(withPrefix: "mcp__", with: tools)
        statuses = next
        return configurations.compactMap { next[$0.id] }
    }

    func currentStatuses() -> [DSHMCPServerStatus] { Array(statuses.values) }

    private static func isLocalHTTP(_ url: URL) -> Bool {
        guard url.scheme == "http" else { return false }
        return ["127.0.0.1", "localhost", "::1"].contains(url.host?.lowercased() ?? "")
    }

    private static func uniqueName(_ value: String, id: UUID, used: inout Set<String>) -> String {
        let normalized = value.lowercased().map { $0.isLetter || $0.isNumber ? $0 : "_" }
        var name = String(normalized).trimmingCharacters(in: CharacterSet(charactersIn: "_"))
        if name.isEmpty { name = "server" }
        if used.contains(name) { name += "_\(id.uuidString.prefix(6).lowercased())" }
        used.insert(name)
        return name
    }

    private static func seconds(_ duration: Duration) -> TimeInterval {
        Double(duration.components.seconds) + Double(duration.components.attoseconds) / 1e18
    }

    private static func errorCategory(_ error: Error) -> String {
        if let error = error as? DSHMCPError {
            switch error {
            case .invalidResponse: return "invalid_response"
            case .httpStatus(let status): return "http_\(status)"
            case .protocolError(let code, _): return "protocol_\(code)"
            case .unsupportedProtocol: return "unsupported_protocol"
            case .notInitialized: return "not_initialized"
            }
        }
        if let error = error as? URLError {
            return error.code == .timedOut ? "network_timeout" : "network_\(error.code.rawValue)"
        }
        return "connection_error"
    }
}
