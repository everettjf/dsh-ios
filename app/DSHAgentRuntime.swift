import Foundation

enum DSHAgentPhase: Equatable, Sendable {
    case idle
    case streaming(step: Int)
    case completed
    case cancelled
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
    case nothingToRetry
    case nothingToContinue

    var errorDescription: String? {
        switch self {
        case .emptyPrompt: return "Enter a message before sending."
        case .alreadyRunning: return "The agent is already responding."
        case .nothingToRetry: return "There is no previous turn to retry."
        case .nothingToContinue: return "There is no response to continue."
        }
    }
}

struct DSHContextPolicy: Equatable, Sendable {
    var maximumEstimatedTokens: Int = 32_000

    func messagesForRequest(_ messages: [DSHChatMessage], systemPrompt: String?) -> [DSHChatMessage] {
        let system = systemPrompt.flatMap { $0.isEmpty ? nil : DSHChatMessage(role: .system, content: $0) }
        let budget = max(1_000, maximumEstimatedTokens - estimatedTokens(system))
        let groups = turnGroups(messages)
        var selected: [[DSHChatMessage]] = []
        var used = 0
        for group in groups.reversed() {
            let cost = group.reduce(0) { $0 + estimatedTokens($1) }
            if !selected.isEmpty, used + cost > budget { break }
            selected.append(group)
            used += cost
        }
        let history = selected.reversed().flatMap { $0 }.map(enrichingAttachments)
        return system.map { [$0] + history } ?? history
    }

    private func enrichingAttachments(_ message: DSHChatMessage) -> DSHChatMessage {
        guard message.role == .user, !message.attachments.isEmpty else { return message }
        var value = message
        let sections = message.attachments.map { attachment in
            var section = "[Attachment: \(attachment.name); id=\(attachment.id.uuidString); type=\(attachment.mediaType); bytes=\(attachment.byteCount)]"
            if let text = attachment.extractedText { section += "\n\(text)\n[End attachment]" }
            else { section += "\n[Binary attachment; use an available file or Linux tool if its contents are needed.]" }
            return section
        }
        value.content = ([message.content ?? ""] + sections).joined(separator: "\n\n")
        return value
    }

    private func turnGroups(_ messages: [DSHChatMessage]) -> [[DSHChatMessage]] {
        var groups: [[DSHChatMessage]] = []
        for message in messages {
            if message.role == .user || groups.isEmpty { groups.append([message]) }
            else { groups[groups.count - 1].append(message) }
        }
        return groups
    }

    private func estimatedTokens(_ message: DSHChatMessage?) -> Int {
        guard let message else { return 0 }
        let characters = (message.content?.count ?? 0) + (message.reasoningContent?.count ?? 0)
            + message.toolCalls.reduce(0) { $0 + $1.name.count + $1.arguments.count }
            + message.attachments.reduce(0) { $0 + $1.name.count + ($1.extractedText?.count ?? 0) }
        return max(4, (characters + 3) / 4 + 8)
    }
}

actor DSHAgentRuntime {
    private let client: any DSHModelClient
    private let model: String
    private let systemPrompt: String?
    private let toolRegistry: DSHToolRegistry?
    private let maximumSteps: Int
    private let contextPolicy: DSHContextPolicy
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
        maximumSteps: Int = 8,
        contextPolicy: DSHContextPolicy = .init()
    ) {
        self.client = client
        self.model = model
        self.systemPrompt = systemPrompt
        self.messages = messages
        self.toolRegistry = toolRegistry
        self.maximumSteps = maximumSteps
        self.contextPolicy = contextPolicy
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
    func send(_ prompt: String, attachments: [DSHAttachment] = []) async throws -> DSHAgentSnapshot {
        guard !isRunning else { throw DSHAgentRuntimeError.alreadyRunning }
        let prompt = prompt.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !prompt.isEmpty || !attachments.isEmpty else { throw DSHAgentRuntimeError.emptyPrompt }
        let content = prompt.isEmpty ? "Please review the attached file(s)." : prompt
        messages.append(.init(role: .user, content: content, attachments: attachments))
        return try await generateResponse()
    }

    @discardableResult
    func retryLastTurn() async throws -> DSHAgentSnapshot {
        guard !isRunning else { throw DSHAgentRuntimeError.alreadyRunning }
        guard let index = messages.lastIndex(where: { $0.role == .user }) else { throw DSHAgentRuntimeError.nothingToRetry }
        messages = Array(messages.prefix(through: index))
        return try await generateResponse()
    }

    @discardableResult
    func continueResponse() async throws -> DSHAgentSnapshot {
        guard !isRunning else { throw DSHAgentRuntimeError.alreadyRunning }
        guard messages.contains(where: { $0.role == .assistant }) else {
            throw DSHAgentRuntimeError.nothingToContinue
        }
        return try await generateResponse()
    }

    private func generateResponse() async throws -> DSHAgentSnapshot {
        guard !isRunning else { throw DSHAgentRuntimeError.alreadyRunning }
        isRunning = true
        defer { isRunning = false }
        usage = nil
        do {
            for step in 1...maximumSteps {
                let assistantIndex = messages.count
                messages.append(.init(role: .assistant))
                phase = .streaming(step: step)
                publish()

                let requestMessages = contextPolicy.messagesForRequest(Array(messages.dropLast()), systemPrompt: systemPrompt)
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
                try Task.checkCancellation()

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
        } catch is CancellationError {
            phase = .cancelled
            publish()
            throw CancellationError()
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
