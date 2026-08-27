import SwiftUI
import UIKit

struct DSHNativeRootView: View {
    @State private var model = DSHAgentViewModel()

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
                composer
            }
            .navigationTitle("DeepSeek")
            .toolbar {
                ToolbarItem(placement: .topBarLeading) {
                    Button("New Conversation", systemImage: "square.and.pencil") { model.newSession() }
                        .accessibilityIdentifier("dsh.native.new-session")
                }
                ToolbarItem(placement: .topBarTrailing) {
                    Button("Settings", systemImage: "gearshape") { model.isShowingSettings = true }
                        .accessibilityIdentifier("dsh.native.settings")
                }
            }
            .sheet(isPresented: $model.isShowingSettings) { settingsView }
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
            .onChange(of: model.snapshot.messages) { _, messages in
                if let id = messages.last?.id { proxy.scrollTo(id, anchor: .bottom) }
            }
            .accessibilityIdentifier("dsh.native.messages")
        }
    }

    private var composer: some View {
        HStack(alignment: .bottom, spacing: 10) {
            TextField("Message DeepSeek", text: $model.draft, axis: .vertical)
                .lineLimit(1...6)
                .textFieldStyle(.roundedBorder)
                .accessibilityIdentifier("dsh.native.composer")
            Button("Send", systemImage: "arrow.up.circle.fill") { model.send() }
                .labelStyle(.iconOnly)
                .font(.title2)
                .disabled(model.draft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty || model.isStreaming)
                .accessibilityIdentifier("dsh.native.send")
        }
        .padding()
        .background(.bar)
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

@MainActor
@objc(DSHNativeRootFactory)
public final class DSHNativeRootFactory: NSObject {
    @objc public static func makeViewController() -> UIViewController {
        UIHostingController(rootView: DSHNativeRootView())
    }
}
