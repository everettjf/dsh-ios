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
    var sessions: [DSHSessionRecord] = []
    var isShowingSessions = false

    @ObservationIgnored private var runtime: DSHAgentRuntime
    @ObservationIgnored private var observationTask: Task<Void, Never>?
    @ObservationIgnored private var sendTask: Task<Void, Never>?
    @ObservationIgnored private var mcpTask: Task<Void, Never>?
    @ObservationIgnored private var persistenceTask: Task<Void, Never>?
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
        Task { await restoreSessions() }
        refreshMCPServers()
    }

    var isConfigured: Bool {
        URL(string: configuration.endpoint)?.scheme?.hasPrefix("http") == true && !configuration.apiKey.isEmpty
    }

    var isStreaming: Bool {
        if case .streaming = snapshot.phase { return true }
        return false
    }

    var currentSessionID: UUID { sessionID }
    var canRetry: Bool { !isStreaming && snapshot.messages.contains { $0.role == .user } }
    var canContinue: Bool { !isStreaming && snapshot.messages.contains { $0.role == .assistant } }

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

    func stop() {
        sendTask?.cancel()
    }

    func persistForLifecycle() {
        persistenceTask?.cancel()
        let current = snapshot
        guard !current.messages.isEmpty else { return }
        persistenceTask = Task { await persist(current) }
    }

    func retryLastTurn() {
        guard !isStreaming else { return }
        sendTask = Task {
            do { _ = try await runtime.retryLastTurn() }
            catch is CancellationError { }
            catch { }
        }
    }

    func continueResponse() {
        guard !isStreaming else { return }
        sendTask = Task {
            do { _ = try await runtime.continueResponse() }
            catch is CancellationError { }
            catch { }
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
        Task { await createNewSession() }
    }

    func selectSession(_ id: UUID) {
        Task { await switchSession(to: id) }
    }

    func renameSession(_ id: UUID, title: String) {
        let title = title.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !title.isEmpty else { return }
        Task {
            guard var record = try? await sessionStore.load(id: id) else { return }
            record.title = title
            record.updatedAt = Date()
            try? await sessionStore.save(record)
            await reloadSessionList()
        }
    }

    func deleteSession(_ id: UUID) {
        Task {
            try? await sessionStore.delete(id: id)
            if id == sessionID { await createNewSession(persistCurrent: false) }
            else { await reloadSessionList() }
        }
    }

    private func createNewSession(persistCurrent: Bool = true) async {
        persistenceTask?.cancel()
        if persistCurrent, !snapshot.messages.isEmpty { await persist(snapshot) }
        observationTask?.cancel()
        sendTask?.cancel()
        sessionID = UUID()
        createdAt = Date()
        UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
        runtime = Self.makeRuntime(configuration, messages: [], toolRegistry: toolRegistry)
        snapshot = .init(messages: [], phase: .idle, usage: nil)
        observeRuntime()
        isShowingSessions = false
        await reloadSessionList()
    }

    private func observeRuntime() {
        let runtime = runtime
        observationTask = Task {
            let updates = await runtime.updates()
            for await update in updates {
                guard !Task.isCancelled else { return }
                snapshot = update
                if !update.messages.isEmpty { schedulePersistence(update) }
            }
        }
    }

    private func restoreSessions() async {
        await reloadSessionList()
        guard let record = try? await sessionStore.load(id: sessionID) else {
            UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
            return
        }
        observationTask?.cancel()
        createdAt = record.createdAt
        if record.turnState == .running {
            snapshot = .init(
                messages: record.messages,
                phase: .failed(message: "The previous response was interrupted when the app stopped. Retry or continue when ready."),
                usage: nil
            )
        } else {
            snapshot = .init(messages: record.messages, phase: .idle, usage: nil)
        }
        runtime = Self.makeRuntime(configuration, messages: record.messages, toolRegistry: toolRegistry)
        observeRuntime()
        if record.turnState == .running { await persist(snapshot, overrideState: .interrupted) }
    }

    private func schedulePersistence(_ update: DSHAgentSnapshot) {
        persistenceTask?.cancel()
        let terminal: Bool
        switch update.phase {
        case .completed, .cancelled, .failed: terminal = true
        case .idle, .streaming: terminal = false
        }
        persistenceTask = Task {
            if !terminal { try? await Task.sleep(for: .milliseconds(300)) }
            guard !Task.isCancelled else { return }
            await persist(update)
        }
    }

    private func persist(
        _ update: DSHAgentSnapshot,
        overrideState: DSHSessionTurnState? = nil
    ) async {
        let firstPrompt = update.messages.first { $0.role == .user }?.content ?? "New conversation"
        let existingTitle = sessions.first(where: { $0.id == sessionID })?.title
        let title = existingTitle ?? String(firstPrompt.prefix(80))
        let record = DSHSessionRecord(
            id: sessionID,
            title: title,
            messages: update.messages,
            createdAt: createdAt,
            updatedAt: Date(),
            turnState: overrideState ?? Self.turnState(update.phase)
        )
        try? await sessionStore.save(record)
        UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
        if let index = sessions.firstIndex(where: { $0.id == record.id }) { sessions[index] = record }
        else { sessions.append(record) }
        sessions.sort { $0.updatedAt > $1.updatedAt }
    }

    private func switchSession(to id: UUID) async {
        guard id != sessionID, let record = try? await sessionStore.load(id: id) else {
            isShowingSessions = false
            return
        }
        persistenceTask?.cancel()
        if !snapshot.messages.isEmpty { await persist(snapshot) }
        sendTask?.cancel()
        observationTask?.cancel()
        sessionID = id
        createdAt = record.createdAt
        UserDefaults.standard.set(id.uuidString, forKey: Self.currentSessionKey)
        let restoredPhase: DSHAgentPhase = record.turnState == .running
            ? .failed(message: "The previous response was interrupted when the app stopped. Retry or continue when ready.")
            : .idle
        snapshot = .init(messages: record.messages, phase: restoredPhase, usage: nil)
        runtime = Self.makeRuntime(configuration, messages: record.messages, toolRegistry: toolRegistry)
        observeRuntime()
        if record.turnState == .running { await persist(snapshot, overrideState: .interrupted) }
        isShowingSessions = false
    }

    private func reloadSessionList() async {
        sessions = (try? await sessionStore.list()) ?? []
    }

    private static func turnState(_ phase: DSHAgentPhase) -> DSHSessionTurnState {
        switch phase {
        case .idle: return .idle
        case .streaming: return .running
        case .completed: return .completed
        case .cancelled: return .cancelled
        case .failed: return .failed
        }
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
