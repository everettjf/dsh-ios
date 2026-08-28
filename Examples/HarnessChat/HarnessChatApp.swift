import SwiftUI
import UIKit
import AgentRuntime
import AgentProviders
import AgentTools
import AgentStorage
import AgentAppleTools
import AgentMCP

@main
struct HarnessChatApp: App {
    var body: some Scene { WindowGroup { HarnessChatView() } }
}

@MainActor
private final class HarnessChatModel: ObservableObject {
    @Published var messages: [DSHChatMessage] = []
    @Published var draft = ""
    @Published var endpoint = "https://api.deepseek.com/v1"
    @Published var model = "deepseek-chat"
    @Published var apiKey = ""
    @Published var isStreaming = false
    @Published var errorMessage: String?

    private let sessionID = UUID(uuidString: "A7518468-1038-4CB4-8385-C0BFA8B52C67")!
    private let store = DSHSessionStore()
    private var responseTask: Task<Void, Never>?
    private var updatesTask: Task<Void, Never>?

    init() { Task { await restore() } }

    func send() {
        let prompt = draft.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !prompt.isEmpty, !isStreaming else { return }
        draft = ""
        errorMessage = nil
        let runtime = makeRuntime()
        updatesTask?.cancel()
        updatesTask = Task { [weak self] in
            for await snapshot in await runtime.updates() {
                guard !Task.isCancelled else { break }
                self?.messages = snapshot.messages
                if case .streaming = snapshot.phase { self?.isStreaming = true }
            }
        }
        responseTask = Task { [weak self] in
            do {
                let snapshot = try await runtime.send(prompt)
                self?.messages = snapshot.messages
                await self?.persist(snapshot.messages)
            } catch is CancellationError {
                self?.errorMessage = "Response stopped."
            } catch {
                self?.errorMessage = error.localizedDescription
            }
            self?.isStreaming = false
        }
    }

    func stop() { responseTask?.cancel(); responseTask = nil }

    private func makeRuntime() -> DSHAgentRuntime {
        let url = URL(string: endpoint) ?? URL(string: "https://api.deepseek.com/v1")!
        let tools = DSHToolRegistry([
            ExampleEchoTool(),
            DSHDeviceInformationTool(provider: ExampleDeviceProvider())
        ])
        return DSHAgentRuntime(
            client: DSHOpenAICompatibleClient(baseURL: url, apiKey: apiKey),
            model: model,
            systemPrompt: "You are a concise assistant. Use tools when useful.",
            messages: messages,
            toolRegistry: tools
        )
    }

    private func restore() async {
        messages = (try? await store.load(id: sessionID))?.messages ?? []
    }

    private func persist(_ messages: [DSHChatMessage]) async {
        let now = Date()
        let title = messages.first(where: { $0.role == .user })?.content.map { String($0.prefix(60)) } ?? "Conversation"
        try? await store.save(.init(id: sessionID, title: title, messages: messages, createdAt: now, updatedAt: now))
    }
}

private struct ExampleEchoTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "echo",
        description: "Echo text to demonstrate a custom Swift tool.",
        parameters: .object(["type": .string("object"), "properties": .object(["text": .object(["type": .string("string")])]), "required": .array([.string("text")])])
    )

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments, case .string(let text) = values["text"] else {
            throw DSHToolError.invalidArguments("text is required.")
        }
        return .object(["text": .string(text)])
    }
}

private struct ExampleDeviceProvider: DSHDeviceInformationProviding {
    func information() async -> DSHDeviceInformation {
        await MainActor.run {
            let device = UIDevice.current
            return .init(device: device.model, systemName: device.systemName, systemVersion: device.systemVersion, localeIdentifier: Locale.current.identifier)
        }
    }
}

private struct HarnessChatView: View {
    @StateObject private var model = HarnessChatModel()
    @State private var showingSettings = false
    @FocusState private var composerFocused: Bool

    var body: some View {
        NavigationStack {
            VStack(spacing: 0) {
                ScrollViewReader { proxy in
                    ScrollView {
                        LazyVStack(spacing: 12) {
                            if model.messages.isEmpty {
                                VStack(spacing: 10) {
                                    Image(systemName: "bubble.left.and.bubble.right").font(.largeTitle).accessibilityHidden(true)
                                    Text("HarnessChat").font(.title2.bold())
                                    Text("Swift Harness Kit reference host").foregroundStyle(.secondary)
                                }.padding(.top, 64).accessibilityElement(children: .combine)
                            }
                            ForEach(model.messages.filter { $0.role != .tool }) { message in
                                Text(message.content ?? "…")
                                    .frame(maxWidth: .infinity, alignment: message.role == .user ? .trailing : .leading)
                                    .padding(12)
                                    .background(Color.secondary.opacity(message.role == .user ? 0.18 : 0.09), in: .rect(cornerRadius: 14))
                                    .accessibilityLabel(message.role == .user ? "You: \(message.content ?? "")" : "Assistant: \(message.content ?? "")")
                            }
                            Color.clear.frame(height: 1).id("bottom")
                        }.padding()
                    }
                    .scrollDismissesKeyboard(.interactively)
                    .onChange(of: model.messages) { _ in proxy.scrollTo("bottom", anchor: .bottom) }
                }
                if let error = model.errorMessage {
                    Text(error).font(.caption).foregroundStyle(.red).frame(maxWidth: .infinity, alignment: .leading).padding(.horizontal)
                }
                HStack(alignment: .bottom) {
                    TextField("Message", text: $model.draft, axis: .vertical)
                        .lineLimit(1...5).focused($composerFocused).padding(10)
                        .background(Color.secondary.opacity(0.12), in: .rect(cornerRadius: 16))
                        .onSubmit { model.send() }
                    Button(model.isStreaming ? "Stop" : "Send", systemImage: model.isStreaming ? "stop.circle.fill" : "arrow.up.circle.fill") {
                        model.isStreaming ? model.stop() : model.send()
                        composerFocused = false
                    }
                    .labelStyle(.iconOnly).font(.title2)
                    .disabled(!model.isStreaming && model.draft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty)
                }.padding().background(.bar)
            }
            .navigationTitle("HarnessChat")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) { Button("Settings", systemImage: "gearshape") { showingSettings = true } }
                ToolbarItemGroup(placement: .keyboard) { Spacer(); Button("Done") { composerFocused = false } }
            }
            .sheet(isPresented: $showingSettings) {
                NavigationStack {
                    Form { Section("Model API") { TextField("Endpoint", text: $model.endpoint).textInputAutocapitalization(.never).keyboardType(.URL); SecureField("API key", text: $model.apiKey); TextField("Model", text: $model.model).textInputAutocapitalization(.never) } }
                        .navigationTitle("Settings")
                        .toolbar { ToolbarItem(placement: .confirmationAction) { Button("Done") { showingSettings = false } } }
                }
            }
        }
    }
}
