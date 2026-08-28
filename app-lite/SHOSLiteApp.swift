import SwiftUI
import UIKit
import AgentRuntime
import AgentProviders
import AgentTools
import AgentStorage
import AgentMCP

@main
struct SHOSLiteApp: App {
    var body: some Scene { WindowGroup { SHOSLiteRootView() } }
}

@MainActor
private final class SHOSLiteModel: ObservableObject {
    @Published var messages: [DSHChatMessage] = []
    @Published var draft = ""
    @Published var endpoint = "https://api.deepseek.com/v1"
    @Published var model = "deepseek-chat"
    @Published var apiKey = ""
    @Published var isStreaming = false
    @Published var errorMessage: String?

    private let sessionID = UUID()
    private let store = DSHSessionStore()
    private var runtime: DSHAgentRuntime?
    private var responseTask: Task<Void, Never>?
    private var observationTask: Task<Void, Never>?

    func send() {
        let prompt = draft.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !prompt.isEmpty, !isStreaming else { return }
        draft = ""
        errorMessage = nil
        let runtime = makeRuntime()
        self.runtime = runtime
        observationTask?.cancel()
        observationTask = Task { [weak self] in
            for await snapshot in await runtime.updates() {
                guard !Task.isCancelled else { break }
                self?.messages = snapshot.messages
                self?.isStreaming = {
                    if case .streaming = snapshot.phase { return true }
                    return false
                }()
            }
        }
        responseTask = Task { [weak self] in
            do {
                let snapshot = try await runtime.send(prompt)
                self?.messages = snapshot.messages
                self?.persist(snapshot.messages)
            } catch is CancellationError {
                self?.errorMessage = "Response stopped."
            } catch {
                self?.errorMessage = error.localizedDescription
            }
            self?.isStreaming = false
        }
    }

    func stop() {
        responseTask?.cancel()
        responseTask = nil
    }

    private func makeRuntime() -> DSHAgentRuntime {
        let baseURL = URL(string: endpoint) ?? URL(string: "https://api.deepseek.com/v1")!
        let tools = DSHToolRegistry([LiteDeviceInfoTool()])
        return DSHAgentRuntime(
            client: DSHOpenAICompatibleClient(baseURL: baseURL, apiKey: apiKey),
            model: model,
            systemPrompt: "You are SHOS, a native iOS assistant. Use native tools when useful.",
            messages: messages,
            toolRegistry: tools
        )
    }

    private func persist(_ messages: [DSHChatMessage]) {
        let now = Date()
        let title = messages.first(where: { $0.role == .user })?.content.map { String($0.prefix(60)) } ?? "Conversation"
        let record = DSHSessionRecord(
            id: sessionID,
            title: title,
            messages: messages,
            createdAt: now,
            updatedAt: now
        )
        Task { try? await store.save(record) }
    }
}

private struct LiteDeviceInfoTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "device_info",
        description: "Read non-sensitive device model and operating-system information.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([:]),
            "additionalProperties": .bool(false)
        ])
    )

    @MainActor
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        .object([
            "model": .string(UIDevice.current.model),
            "system_name": .string(UIDevice.current.systemName),
            "system_version": .string(UIDevice.current.systemVersion)
        ])
    }
}

private struct SHOSLiteRootView: View {
    @StateObject private var model = SHOSLiteModel()
    @State private var showingSettings = false
    @FocusState private var composerFocused: Bool

    var body: some View {
        NavigationStack {
            VStack(spacing: 0) {
                ScrollViewReader { proxy in
                    ScrollView {
                        LazyVStack(spacing: 10) {
                            if model.messages.isEmpty {
                                VStack(spacing: 10) {
                                    Image(systemName: "sparkles").font(.largeTitle)
                                    Text("SHOS Lite").font(.title2.bold())
                                    Text("Native agent without the Linux guest")
                                        .foregroundStyle(.secondary)
                                }
                                .padding(.top, 80)
                            }
                            ForEach(model.messages) { message in
                                if message.role != .tool {
                                    Text(message.content ?? "…")
                                        .frame(maxWidth: .infinity, alignment: message.role == .user ? .trailing : .leading)
                                        .padding(12)
                                        .background(Color.secondary.opacity(message.role == .user ? 0.18 : 0.1))
                                        .clipShape(RoundedRectangle(cornerRadius: 14))
                                }
                            }
                            Color.clear.frame(height: 1).id("bottom")
                        }
                        .padding()
                    }
                    .scrollDismissesKeyboard(.interactively)
                    .onChange(of: model.messages) { _ in proxy.scrollTo("bottom", anchor: .bottom) }
                }
                if let error = model.errorMessage {
                    Text(error).font(.caption).foregroundStyle(.red).frame(maxWidth: .infinity, alignment: .leading).padding(.horizontal)
                }
                HStack(alignment: .bottom, spacing: 10) {
                    TextField("Message SHOS", text: $model.draft, axis: .vertical)
                        .lineLimit(1...5)
                        .focused($composerFocused)
                        .padding(10)
                        .background(Color.secondary.opacity(0.12), in: RoundedRectangle(cornerRadius: 16))
                    if model.isStreaming {
                        Button("Stop", systemImage: "stop.circle.fill") { model.stop() }.labelStyle(.iconOnly)
                    } else {
                        Button("Send", systemImage: "arrow.up.circle.fill") {
                            model.send()
                            composerFocused = false
                        }
                        .labelStyle(.iconOnly)
                        .disabled(model.draft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty)
                    }
                }
                .font(.title2)
                .padding()
                .background(.bar)
            }
            .navigationTitle("SHOS Lite")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button("Settings", systemImage: "gearshape") { showingSettings = true }
                }
                ToolbarItemGroup(placement: .keyboard) {
                    Spacer()
                    Button("Done") { composerFocused = false }
                }
            }
            .sheet(isPresented: $showingSettings) {
                NavigationStack {
                    Form {
                        Section("Model API") {
                            TextField("Endpoint", text: $model.endpoint)
                                .textInputAutocapitalization(.never)
                                .keyboardType(.URL)
                            SecureField("API key", text: $model.apiKey)
                            TextField("Model", text: $model.model)
                                .textInputAutocapitalization(.never)
                        }
                        Section("Build") {
                            LabeledContent("Linux guest", value: "Not included")
                            LabeledContent("MCP client", value: "Available")
                        }
                    }
                    .navigationTitle("Lite Settings")
                    .toolbar { Button("Done") { showingSettings = false } }
                }
            }
        }
    }
}
