import SwiftUI
import UIKit
import UniformTypeIdentifiers

struct DSHNativeRootView: View {
    @State private var model = DSHAgentViewModel()
    @Environment(\.scenePhase) private var scenePhase
    @FocusState private var isComposerFocused: Bool

    var body: some View {
        NavigationStack {
            VStack(spacing: 0) {
                if model.snapshot.messages.isEmpty {
                    ContentUnavailableView(
                        "DeepSeek Agent",
                        systemImage: "sparkles",
                        description: Text(model.isConfigured ? "Ask anything to begin." : "Add your DeepSeek API key to begin.")
                    )
                    .accessibilityIdentifier("dsh.native.empty")
                } else {
                    messageList
                }
            }
            .safeAreaInset(edge: .bottom, spacing: 0) {
                VStack(spacing: 0) {
                    responseStatus
                    composer
                }
                .background(.bar)
            }
            .navigationTitle("DeepSeek")
            .toolbar {
                ToolbarItemGroup(placement: .topBarLeading) {
                    Button("Conversations", systemImage: "sidebar.left") { model.isShowingSessions = true }
                        .accessibilityIdentifier("dsh.native.sessions")
                    Button("New Conversation", systemImage: "square.and.pencil") { model.newSession() }
                        .accessibilityIdentifier("dsh.native.new-session")
                }
                ToolbarItemGroup(placement: .topBarTrailing) {
                    Button("Activity", systemImage: "list.bullet.rectangle") { model.isShowingActivity = true }
                        .accessibilityIdentifier("dsh.native.activity-button")
                    Button("Settings", systemImage: "gearshape") { model.isShowingSettings = true }
                        .accessibilityIdentifier("dsh.native.settings")
                }
            }
            .sheet(isPresented: $model.isShowingSettings) { settingsView }
            .sheet(isPresented: $model.isShowingSessions) { SessionBrowserView(model: model) }
            .sheet(isPresented: $model.isShowingActivity) { ActivityContainer() }
            .fileImporter(
                isPresented: $model.isImportingAttachments,
                allowedContentTypes: [.data],
                allowsMultipleSelection: true
            ) { result in
                switch result {
                case .success(let urls): model.importAttachments(urls)
                case .failure(let error): model.attachmentError = error.localizedDescription
                }
            }
            .alert("Attachment Error", isPresented: Binding(
                get: { model.attachmentError != nil },
                set: { if !$0 { model.attachmentError = nil } }
            )) {
                Button("OK", role: .cancel) { model.attachmentError = nil }
            } message: {
                Text(model.attachmentError ?? "The attachment could not be imported.")
            }
            .onChange(of: scenePhase) { _, phase in
                if phase != .active { model.persistForLifecycle() }
            }
            .toolbar {
                ToolbarItemGroup(placement: .keyboard) {
                    Spacer()
                    Button("Done") { isComposerFocused = false }
                        .accessibilityIdentifier("dsh.native.keyboard.dismiss")
                }
            }
        }
    }

    private var messageList: some View {
        ScrollViewReader { proxy in
            ScrollView {
                LazyVStack(spacing: 12) {
                    ForEach(model.snapshot.messages) { message in
                        MessageBubble(message: message)
                            .id(message.id)
                    }
                }
                .padding()
            }
            .scrollDismissesKeyboard(.interactively)
            .onChange(of: model.snapshot.messages) { _, messages in
                if let id = messages.last?.id { proxy.scrollTo(id, anchor: .bottom) }
            }
            .accessibilityIdentifier("dsh.native.messages")
        }
    }

    private var composer: some View {
        VStack(alignment: .leading, spacing: 8) {
            if !model.pendingAttachments.isEmpty {
                ScrollView(.horizontal) {
                    HStack {
                        ForEach(model.pendingAttachments) { attachment in
                            PendingAttachmentChip(attachment: attachment) {
                                model.removePendingAttachment(attachment)
                            }
                        }
                    }
                }
                .scrollIndicators(.hidden)
                .accessibilityIdentifier("dsh.native.pending-attachments")
            }
            HStack(alignment: .bottom, spacing: 10) {
                Button("Attach File", systemImage: "paperclip") { model.isImportingAttachments = true }
                    .labelStyle(.iconOnly)
                    .disabled(model.isStreaming || !model.hasRestoredSessions)
                    .accessibilityIdentifier("dsh.native.attach")
                TextField("Message DeepSeek", text: $model.draft, axis: .vertical)
                    .lineLimit(1...6)
                    .focused($isComposerFocused)
                    .textFieldStyle(.plain)
                    .padding(.horizontal, 12)
                    .padding(.vertical, 10)
                    .background(.secondary.opacity(0.12), in: .rect(cornerRadius: 18))
                    .onSubmit {
                        guard !model.draft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty else { return }
                        model.send()
                    }
                    .accessibilityIdentifier("dsh.native.composer")
                if model.isStreaming {
                    Button("Stop", systemImage: "stop.circle.fill", role: .destructive) { model.stop() }
                        .labelStyle(.iconOnly)
                        .font(.title2)
                        .accessibilityIdentifier("dsh.native.stop")
                } else {
                    Menu("Response Actions", systemImage: "ellipsis.circle") {
                        Button("Retry Last Turn", systemImage: "arrow.counterclockwise") { model.retryLastTurn() }
                            .disabled(!model.canRetry)
                        Button("Continue Response", systemImage: "text.append") { model.continueResponse() }
                            .disabled(!model.canContinue)
                    }
                    .labelStyle(.iconOnly)
                    Button("Send", systemImage: "arrow.up.circle.fill") { model.send() }
                        .labelStyle(.iconOnly)
                        .font(.title2)
                        .disabled(model.draft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty && model.pendingAttachments.isEmpty)
                        .accessibilityIdentifier("dsh.native.send")
                }
            }
        }
        .padding(.horizontal, 12)
        .padding(.vertical, 8)
    }

    @ViewBuilder private var responseStatus: some View {
        switch model.snapshot.phase {
        case .failed(let message):
            Label(message, systemImage: "exclamationmark.triangle")
                .font(.caption)
                .foregroundStyle(.red)
                .frame(maxWidth: .infinity, alignment: .leading)
                .padding(.horizontal)
                .accessibilityIdentifier("dsh.native.failure")
        case .cancelled:
            Label("Response stopped", systemImage: "stop.circle")
                .font(.caption)
                .foregroundStyle(.secondary)
                .frame(maxWidth: .infinity, alignment: .leading)
                .padding(.horizontal)
                .accessibilityIdentifier("dsh.native.cancelled")
        case .idle, .streaming, .completed:
            EmptyView()
        }
    }

    private var settingsView: some View {
        NavigationStack {
            Form {
                Section("Model API") {
                    TextField("Endpoint", text: $model.configuration.endpoint)
                        .textInputAutocapitalization(.never)
                        .keyboardType(.URL)
                        .accessibilityIdentifier("dsh.native.endpoint")
                    SecureField("API key", text: $model.configuration.apiKey)
                        .textInputAutocapitalization(.never)
                        .accessibilityIdentifier("dsh.native.apikey")
                    TextField("Model", text: $model.configuration.model)
                        .textInputAutocapitalization(.never)
                        .accessibilityIdentifier("dsh.native.model")
                }
                Section("MCP Servers") {
                    ForEach($model.mcpConfigurations) { $server in
                        VStack(alignment: .leading, spacing: 10) {
                            HStack {
                                TextField("Name", text: $server.name)
                                    .textInputAutocapitalization(.never)
                                Toggle("Enabled", isOn: $server.isEnabled).labelsHidden()
                                Button("Remove", systemImage: "trash", role: .destructive) {
                                    model.mcpConfigurations.removeAll { $0.id == server.id }
                                }
                                .labelStyle(.iconOnly)
                            }
                            TextField("HTTPS endpoint", text: $server.endpoint)
                                .textInputAutocapitalization(.never)
                                .keyboardType(.URL)
                            SecureField("Bearer token (optional)", text: $server.bearerToken)
                                .textInputAutocapitalization(.never)
                            if let status = model.mcpStatuses.first(where: { $0.id == server.id }) {
                                Text(Self.mcpStatusText(status.state))
                                    .font(.caption)
                                    .foregroundStyle(Self.mcpStatusColor(status.state))
                            }
                        }
                        .accessibilityElement(children: .contain)
                    }
                    Button("Add MCP Server", systemImage: "plus") {
                        model.mcpConfigurations.append(.init(name: "server", endpoint: "https://"))
                    }
                    Button("Reconnect", systemImage: "arrow.clockwise") { model.refreshMCPServers() }
                        .disabled(model.mcpConfigurations.isEmpty)
                }
                Section("Linux Workspace") {
                    LabeledContent("Startup", value: "On demand")
                    Text("Linux starts only when a shell, attachment staging, or another Linux tool needs it.")
                    Text("Existing guest files remain available. Legacy dsh web conversations are not imported into native conversations.")
                        .accessibilityIdentifier("dsh.native.legacy-session-compatibility")
                    Text("Arbitrary dsh plugins are not guaranteed to work; use native tools or MCP for supported extensions.")
                }
                if let error = model.configurationError {
                    Section { Text(error).foregroundStyle(.red) }
                }
            }
            .navigationTitle("Agent Settings")
            .toolbar {
                ToolbarItem(placement: .cancellationAction) {
                    Button("Cancel") { model.isShowingSettings = false }
                }
                ToolbarItem(placement: .confirmationAction) {
                    Button("Save") { model.saveConfiguration() }
                        .accessibilityIdentifier("dsh.native.settings.save")
                }
            }
        }
    }

    private static func mcpStatusText(_ state: DSHMCPConnectionState) -> String {
        switch state {
        case .disabled: return "Disabled"
        case .connecting: return "Connecting…"
        case .connected(let count): return "Connected · \(count) tool(s)"
        case .failed(let message): return "Connection failed: \(message)"
        }
    }

    private static func mcpStatusColor(_ state: DSHMCPConnectionState) -> Color {
        switch state {
        case .connected: return .green
        case .failed: return .red
        case .disabled, .connecting: return .secondary
        }
    }
}

private struct ActivityContainer: UIViewControllerRepresentable {
    func makeUIViewController(context: Context) -> UIViewController {
        UINavigationController(rootViewController: DSHActivityViewController())
    }

    func updateUIViewController(_ uiViewController: UIViewController, context: Context) { }
}

private struct SessionBrowserView: View {
    let model: DSHAgentViewModel
    @Environment(\.dismiss) private var dismiss
    @State private var renameID: UUID?
    @State private var renameTitle = ""
    @State private var deleteID: UUID?

    var body: some View {
        NavigationStack {
            Group {
                if model.sessions.isEmpty {
                    ContentUnavailableView("No Conversations", systemImage: "bubble.left.and.bubble.right")
                } else {
                    List(model.sessions) { session in
                        Button {
                            model.selectSession(session.id)
                        } label: {
                            SessionRow(session: session, selected: session.id == model.currentSessionID)
                        }
                        .buttonStyle(.plain)
                        .swipeActions(edge: .trailing) {
                            Button("Delete", systemImage: "trash", role: .destructive) { deleteID = session.id }
                            Button("Rename", systemImage: "pencil") {
                                renameID = session.id
                                renameTitle = session.title
                            }
                            .tint(.blue)
                        }
                    }
                }
            }
            .navigationTitle("Conversations")
            .toolbar {
                ToolbarItem(placement: .cancellationAction) { Button("Done") { dismiss() } }
                ToolbarItem(placement: .primaryAction) {
                    Button("New", systemImage: "square.and.pencil") { model.newSession() }
                }
            }
            .alert("Rename Conversation", isPresented: Binding(
                get: { renameID != nil },
                set: { if !$0 { renameID = nil } }
            )) {
                TextField("Title", text: $renameTitle)
                Button("Rename") {
                    if let renameID { model.renameSession(renameID, title: renameTitle) }
                    renameID = nil
                }
                Button("Cancel", role: .cancel) { renameID = nil }
            }
            .confirmationDialog("Delete this conversation?", isPresented: Binding(
                get: { deleteID != nil },
                set: { if !$0 { deleteID = nil } }
            )) {
                Button("Delete Conversation", role: .destructive) {
                    if let deleteID { model.deleteSession(deleteID) }
                    deleteID = nil
                }
                Button("Cancel", role: .cancel) { deleteID = nil }
            } message: {
                Text("This removes its local message history.")
            }
        }
    }
}

private struct SessionRow: View {
    let session: DSHSessionRecord
    let selected: Bool

    var body: some View {
        HStack(spacing: 12) {
            Image(systemName: selected ? "checkmark.circle.fill" : "bubble.left")
                .foregroundStyle(selected ? Color.accentColor : Color.secondary)
            VStack(alignment: .leading, spacing: 3) {
                Text(session.title).lineLimit(1)
                Text(session.updatedAt, style: .relative)
                    .font(.caption)
                    .foregroundStyle(.secondary)
            }
            Spacer()
            if session.turnState == .running || session.turnState == .interrupted {
                Image(systemName: "exclamationmark.circle")
                    .foregroundStyle(.orange)
                    .accessibilityLabel("Interrupted response")
            }
        }
        .contentShape(.rect)
        .accessibilityElement(children: .combine)
    }
}

private struct MessageBubble: View {
    let message: DSHChatMessage

    var body: some View {
        VStack(alignment: message.role == .user ? .trailing : .leading, spacing: 6) {
            if let reasoning = message.reasoningContent, !reasoning.isEmpty {
                DisclosureGroup("Reasoning") {
                    Text(reasoning).frame(maxWidth: .infinity, alignment: .leading)
                }
                .font(.caption)
                .foregroundStyle(.secondary)
            }
            Text(message.content ?? (message.role == .assistant ? "…" : ""))
                .textSelection(.enabled)
            if !message.attachments.isEmpty {
                VStack(alignment: .leading, spacing: 4) {
                    ForEach(message.attachments) { attachment in
                        Label(attachment.name, systemImage: "doc")
                            .font(.caption)
                            .lineLimit(1)
                    }
                }
                .accessibilityElement(children: .combine)
            }
            if !message.toolCalls.isEmpty {
                Text("Requested \(message.toolCalls.count) tool call(s)")
                    .font(.caption)
                    .foregroundStyle(.secondary)
            }
        }
        .padding(12)
        .frame(maxWidth: .infinity, alignment: message.role == .user ? .trailing : .leading)
        .background(message.role == .user ? Color.accentColor.opacity(0.18) : Color.secondary.opacity(0.12))
        .clipShape(RoundedRectangle(cornerRadius: 14))
        .accessibilityIdentifier("dsh.native.message.\(message.role.rawValue)")
    }
}

private struct PendingAttachmentChip: View {
    let attachment: DSHAttachment
    let remove: () -> Void

    var body: some View {
        HStack(spacing: 6) {
            Label(attachment.name, systemImage: "doc")
                .lineLimit(1)
            Button("Remove \(attachment.name)", systemImage: "xmark.circle.fill", role: .destructive, action: remove)
                .labelStyle(.iconOnly)
        }
        .font(.caption)
        .padding(.horizontal, 10)
        .padding(.vertical, 6)
        .background(.secondary.opacity(0.12))
        .clipShape(.capsule)
        .accessibilityElement(children: .contain)
    }
}

@MainActor
@objc(DSHNativeRootFactory)
public final class DSHNativeRootFactory: NSObject {
    @objc public static func makeViewController() -> UIViewController {
        UIHostingController(rootView: DSHNativeRootView())
    }
}
