import Foundation
import Observation

@MainActor
@Observable
final class DSHAgentViewModel {
    var snapshot = DSHAgentSnapshot(messages: [], phase: .idle, usage: nil)
    var draft = ""
    var configuration: DSHAgentConfiguration
    var isShowingSettings = false
    var configurationError: String?
    var mcpConfigurations = DSHMCPServerConfigurationStore.load()
    var mcpStatuses: [DSHMCPServerStatus] = []

    @ObservationIgnored private var runtime: DSHAgentRuntime
    @ObservationIgnored private var observationTask: Task<Void, Never>?
    @ObservationIgnored private var sendTask: Task<Void, Never>?
    @ObservationIgnored private var mcpTask: Task<Void, Never>?
    @ObservationIgnored private let sessionStore: DSHSessionStore
    @ObservationIgnored private let toolRegistry: DSHToolRegistry
    @ObservationIgnored private let mcpManager: DSHMCPServerManager
    @ObservationIgnored private var sessionID: UUID
    @ObservationIgnored private var createdAt = Date()

    private static let currentSessionKey = "native.agent.current-session"

    init(
        configuration: DSHAgentConfiguration = DSHAgentConfigurationStore.load(),
        sessionStore: DSHSessionStore = DSHSessionStore()
    ) {
        self.configuration = configuration
        self.sessionStore = sessionStore
        if let value = UserDefaults.standard.string(forKey: Self.currentSessionKey), let id = UUID(uuidString: value) {
            sessionID = id
        } else {
            sessionID = UUID()
        }
        let registry = Self.makeToolRegistry()
        toolRegistry = registry
        mcpManager = DSHMCPServerManager(registry: registry)
        self.runtime = Self.makeRuntime(configuration, messages: [], toolRegistry: registry)
        observeRuntime()
        Task { await restoreCurrentSession() }
        refreshMCPServers()
    }

    var isConfigured: Bool {
        URL(string: configuration.endpoint)?.scheme?.hasPrefix("http") == true && !configuration.apiKey.isEmpty
    }

    var isStreaming: Bool {
        if case .streaming = snapshot.phase { return true }
        return false
    }

    func send() {
        guard isConfigured, !isStreaming else {
            if !isConfigured { isShowingSettings = true }
            return
        }
        let prompt = draft
        draft = ""
        sendTask = Task {
            do {
                _ = try await runtime.send(prompt)
            } catch is CancellationError {
                // Cancellation is an expected result of leaving the screen.
            } catch {
                // The runtime snapshot contains the user-facing failure state.
            }
        }
    }

    func saveConfiguration() {
        do {
            try DSHAgentConfigurationStore.save(configuration)
            try DSHMCPServerConfigurationStore.save(mcpConfigurations)
            configurationError = nil
            observationTask?.cancel()
            sendTask?.cancel()
            runtime = Self.makeRuntime(configuration, messages: snapshot.messages, toolRegistry: toolRegistry)
            snapshot = .init(messages: [], phase: .idle, usage: nil)
            observeRuntime()
            refreshMCPServers()
            isShowingSettings = false
        } catch {
            configurationError = error.localizedDescription
        }
    }

    func saveMCPConfiguration() {
        do {
            try DSHMCPServerConfigurationStore.save(mcpConfigurations)
            configurationError = nil
            refreshMCPServers()
        } catch {
            configurationError = error.localizedDescription
        }
    }

    func refreshMCPServers() {
        mcpTask?.cancel()
        let configurations = mcpConfigurations
        mcpTask = Task {
            mcpStatuses = await mcpManager.refresh(configurations)
        }
    }

    func newSession() {
        observationTask?.cancel()
        sendTask?.cancel()
        sessionID = UUID()
        createdAt = Date()
        UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
        runtime = Self.makeRuntime(configuration, messages: [], toolRegistry: toolRegistry)
        snapshot = .init(messages: [], phase: .idle, usage: nil)
        observeRuntime()
    }

    private func observeRuntime() {
        let runtime = runtime
        observationTask = Task {
            let updates = await runtime.updates()
            for await update in updates {
                guard !Task.isCancelled else { return }
                snapshot = update
                if !update.messages.isEmpty {
                    switch update.phase {
                    case .completed, .failed:
                        await persist(update)
                    case .idle, .streaming:
                        break
                    }
                }
            }
        }
    }

    private func restoreCurrentSession() async {
        guard let record = try? await sessionStore.load(id: sessionID) else {
            UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
            return
        }
        observationTask?.cancel()
        createdAt = record.createdAt
        snapshot = .init(messages: record.messages, phase: .idle, usage: nil)
        runtime = Self.makeRuntime(configuration, messages: record.messages, toolRegistry: toolRegistry)
        observeRuntime()
    }

    private func persist(_ update: DSHAgentSnapshot) async {
        let firstPrompt = update.messages.first { $0.role == .user }?.content ?? "New conversation"
        let title = String(firstPrompt.prefix(80))
        let record = DSHSessionRecord(
            id: sessionID,
            title: title,
            messages: update.messages,
            createdAt: createdAt,
            updatedAt: Date()
        )
        try? await sessionStore.save(record)
        UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
    }

    private static func makeRuntime(
        _ configuration: DSHAgentConfiguration,
        messages: [DSHChatMessage],
        toolRegistry: DSHToolRegistry
    ) -> DSHAgentRuntime {
        let endpoint = URL(string: configuration.endpoint) ?? URL(string: DSHAgentConfiguration.defaultEndpoint)!
        let client = DSHOpenAICompatibleClient(baseURL: endpoint, apiKey: configuration.apiKey)
        return DSHAgentRuntime(
            client: client,
            model: configuration.model,
            systemPrompt: "You are a fast, capable iOS assistant. Use native tools when appropriate.",
            messages: messages,
            toolRegistry: toolRegistry
        )
    }

    private static func makeToolRegistry() -> DSHToolRegistry {
        let guest = DSHLazyGuestManager()
        let authorization = DSHDefaultsToolAuthorizationPolicy()
        let deviceInfo = DSHGovernedTool(
            DSHDeviceInfoTool(),
            permission: .init(identifier: "device.info", title: "Device information", gate: .enabledOnly, enabledByDefault: true),
            authorization: authorization
        )
        let devicePower = DSHGovernedTool(
            DSHDevicePowerTool(),
            permission: .init(identifier: "device.power", title: "Battery and thermal state", gate: .enabledOnly, enabledByDefault: true),
            authorization: authorization
        )
        let location = DSHGovernedTool(
            DSHNativeReadTool(.location),
            permission: .init(identifier: "location.read", title: "Current location", gate: .systemPermission, enabledByDefault: true),
            authorization: authorization
        )
        let contacts = DSHGovernedTool(
            DSHNativeReadTool(.contacts),
            permission: .init(identifier: "contacts.read", title: "Contacts search", gate: .systemPermission, enabledByDefault: true),
            authorization: authorization
        )
        let calendar = DSHGovernedTool(
            DSHNativeReadTool(.calendar),
            permission: .init(identifier: "calendar.read", title: "Calendar access", gate: .systemPermission, enabledByDefault: true),
            authorization: authorization
        )
        let reminders = DSHGovernedTool(
            DSHNativeReadTool(.reminders),
            permission: .init(identifier: "reminders.read", title: "Reminders access", gate: .systemPermission, enabledByDefault: true),
            authorization: authorization
        )
        let health = DSHGovernedTool(
            DSHNativeReadTool(.health),
            permission: .init(identifier: "health.read", title: "Apple Health access", gate: .systemPermission, enabledByDefault: true),
            authorization: authorization
        )
        let nativeWrites: [DSHGovernedTool] = [
            (.notify, "notifications.post", "Notifications"),
            (.calendarCreate, "calendar.write", "Create calendar event"),
            (.reminderCreate, "reminders.write", "Create reminder"),
            (.fileImport, "files.import", "Choose a file"),
            (.fileExport, "files.export", "Save a file"),
            (.photoImport, "photos.import", "Choose a photo"),
            (.share, "share.present", "Share content"),
            (.shortcutRun, "shortcuts.run", "Run Shortcut")
        ].map { kind, identifier, title in
            // These adapters present their own native per-call confirmation or
            // picker. The outer gate enforces the persistent capability switch;
            // keeping confirmation in the adapter avoids asking twice.
            DSHGovernedTool(
                DSHNativeWriteTool(kind),
                permission: .init(identifier: identifier, title: title, gate: .enabledOnly, enabledByDefault: true),
                authorization: authorization
            )
        }
        return DSHToolRegistry([
                deviceInfo, devicePower, location, contacts, calendar, reminders, health,
                DSHBashTool(manager: guest)
            ] + nativeWrites)
    }
}
