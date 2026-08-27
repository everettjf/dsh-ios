import Foundation

enum DSHAgentPhase: Equatable, Sendable {
    case idle
    case streaming(step: Int)
    case completed
    case failed(message: String)
}

struct DSHAgentSnapshot: Equatable, Sendable {
    let messages: [DSHChatMessage]
    let phase: DSHAgentPhase
    let usage: DSHTokenUsage?
}

enum DSHAgentRuntimeError: Error, LocalizedError, Equatable {
    case emptyPrompt
    case alreadyRunning

    var errorDescription: String? {
        switch self {
        case .emptyPrompt: return "Enter a message before sending."
        case .alreadyRunning: return "The agent is already responding."
        }
    }
}

actor DSHAgentRuntime {
    private let client: any DSHModelClient
    private let model: String
    private let systemPrompt: String?
    private let toolRegistry: DSHToolRegistry?
    private let maximumSteps: Int
    private var messages: [DSHChatMessage]
    private var phase: DSHAgentPhase = .idle
    private var usage: DSHTokenUsage?
    private var isRunning = false
    private var observers: [UUID: AsyncStream<DSHAgentSnapshot>.Continuation] = [:]

    init(
        client: any DSHModelClient,
        model: String,
        systemPrompt: String? = nil,
        messages: [DSHChatMessage] = [],
        toolRegistry: DSHToolRegistry? = nil,
        maximumSteps: Int = 8
    ) {
        self.client = client
        self.model = model
        self.systemPrompt = systemPrompt
        self.messages = messages
        self.toolRegistry = toolRegistry
        self.maximumSteps = maximumSteps
    }

    func snapshot() -> DSHAgentSnapshot {
        DSHAgentSnapshot(messages: messages, phase: phase, usage: usage)
    }

    func updates() -> AsyncStream<DSHAgentSnapshot> {
        let id = UUID()
        return AsyncStream(bufferingPolicy: .bufferingNewest(1)) { continuation in
            observers[id] = continuation
            continuation.yield(snapshot())
            continuation.onTermination = { @Sendable _ in
                Task { await self.removeObserver(id) }
            }
        }
    }

    @discardableResult
    func send(_ prompt: String) async throws -> DSHAgentSnapshot {
        let prompt = prompt.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !prompt.isEmpty else { throw DSHAgentRuntimeError.emptyPrompt }
        guard !isRunning else { throw DSHAgentRuntimeError.alreadyRunning }

        isRunning = true
        defer { isRunning = false }
        usage = nil
        messages.append(.init(role: .user, content: prompt))
        do {
            for step in 1...maximumSteps {
                let assistantIndex = messages.count
                messages.append(.init(role: .assistant))
                phase = .streaming(step: step)
                publish()

                var requestMessages = messages
                requestMessages.removeLast()
                if let systemPrompt, !systemPrompt.isEmpty {
                    requestMessages.insert(.init(role: .system, content: systemPrompt), at: 0)
                }
                var toolCallFragments: [Int: ToolCallFragment] = [:]
                var finishReason: DSHFinishReason?
                for try await event in client.stream(request: .init(
                    model: model,
                    messages: requestMessages,
                    tools: toolRegistry?.definitions ?? []
                )) {
                    try Task.checkCancellation()
                    switch event {
                    case .reasoningDelta(let text):
                        messages[assistantIndex].reasoningContent =
                            (messages[assistantIndex].reasoningContent ?? "") + text
                    case .contentDelta(let text):
                        messages[assistantIndex].content = (messages[assistantIndex].content ?? "") + text
                    case .toolCallDelta(let delta):
                        var fragment = toolCallFragments[delta.index] ?? ToolCallFragment()
                        fragment.id += delta.id ?? ""
                        fragment.name += delta.name ?? ""
                        fragment.arguments += delta.arguments ?? ""
                        toolCallFragments[delta.index] = fragment
                        messages[assistantIndex].toolCalls = toolCallFragments.keys.sorted().compactMap { index in
                            guard let value = toolCallFragments[index], !value.id.isEmpty, !value.name.isEmpty else {
                                return nil
                            }
                            return DSHToolCall(id: value.id, name: value.name, arguments: value.arguments)
                        }
                    case .usage(let value):
                        usage = value
                    case .completed(let reason):
                        finishReason = reason
                    }
                    publish()
                }

                let calls = messages[assistantIndex].toolCalls
                guard finishReason == .toolCalls, !calls.isEmpty, let toolRegistry else {
                    phase = .completed
                    publish()
                    return snapshot()
                }
                for call in calls {
                    let result = await toolRegistry.execute(call)
                    messages.append(.init(role: .tool, content: result, toolCallID: call.id))
                    publish()
                }
            }
            throw DSHToolError.stepLimitExceeded
        } catch {
            phase = .failed(message: error.localizedDescription)
            publish()
            throw error
        }
    }

    private func publish() {
        let value = snapshot()
        for continuation in observers.values { continuation.yield(value) }
    }

    private func removeObserver(_ id: UUID) {
        observers.removeValue(forKey: id)
    }
}

private struct ToolCallFragment {
    var id = ""
    var name = ""
    var arguments = ""
}
