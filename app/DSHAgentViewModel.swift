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

    @ObservationIgnored private var runtime: DSHAgentRuntime
    @ObservationIgnored private var observationTask: Task<Void, Never>?
    @ObservationIgnored private var sendTask: Task<Void, Never>?
    @ObservationIgnored private let sessionStore: DSHSessionStore
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
        self.runtime = Self.makeRuntime(configuration, messages: [])
        observeRuntime()
        Task { await restoreCurrentSession() }
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
            configurationError = nil
            observationTask?.cancel()
            sendTask?.cancel()
            runtime = Self.makeRuntime(configuration, messages: snapshot.messages)
            snapshot = .init(messages: [], phase: .idle, usage: nil)
            observeRuntime()
            isShowingSettings = false
        } catch {
            configurationError = error.localizedDescription
        }
    }

    func newSession() {
        observationTask?.cancel()
        sendTask?.cancel()
        sessionID = UUID()
        createdAt = Date()
        UserDefaults.standard.set(sessionID.uuidString, forKey: Self.currentSessionKey)
        runtime = Self.makeRuntime(configuration, messages: [])
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
        runtime = Self.makeRuntime(configuration, messages: record.messages)
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
        messages: [DSHChatMessage]
    ) -> DSHAgentRuntime {
        let endpoint = URL(string: configuration.endpoint) ?? URL(string: DSHAgentConfiguration.defaultEndpoint)!
        let client = DSHOpenAICompatibleClient(baseURL: endpoint, apiKey: configuration.apiKey)
        let guest = DSHLazyGuestManager()
        return DSHAgentRuntime(
            client: client,
            model: configuration.model,
            systemPrompt: "You are a fast, capable iOS assistant. Use native tools when appropriate.",
            messages: messages,
            toolRegistry: DSHToolRegistry([DSHDeviceInfoTool(), DSHBashTool(manager: guest)])
        )
    }
}
