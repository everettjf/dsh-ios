import Foundation

protocol DSHAgentTelemetry: Sendable {
    func started(source: String, name: String, detail: String, correlationID: String) async
    func finished(source: String, name: String, detail: String, result: String, outcome: String, duration: TimeInterval, correlationID: String) async
}

struct DSHNoopAgentTelemetry: DSHAgentTelemetry {
    func started(source: String, name: String, detail: String, correlationID: String) async { }
    func finished(source: String, name: String, detail: String, result: String, outcome: String, duration: TimeInterval, correlationID: String) async { }
}

struct DSHActivityAgentTelemetry: DSHAgentTelemetry, @unchecked Sendable {
    func started(source: String, name: String, detail: String, correlationID: String) async {
        DSHNativeToolAudit.recordStarted(withSource: source, name: name, detail: detail, correlationID: correlationID)
    }

    func finished(
        source: String, name: String, detail: String, result: String, outcome: String,
        duration: TimeInterval, correlationID: String
    ) async {
        DSHNativeToolAudit.recordFinished(
            withSource: source, name: name, detail: detail, result: result,
            outcome: outcome, duration: duration, correlationID: correlationID
        )
    }
}

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
    private let telemetry: any DSHAgentTelemetry
    private var messages: [DSHChatMessage]
    private var phase: DSHAgentPhase = .idle
    private var usage: DSHTokenUsage?
    private var isRunning = false
    private var lastStreamingPublishAt: ContinuousClock.Instant?
    private var observers: [UUID: AsyncStream<DSHAgentSnapshot>.Continuation] = [:]

    init(
        client: any DSHModelClient,
        model: String,
        systemPrompt: String? = nil,
        messages: [DSHChatMessage] = [],
        toolRegistry: DSHToolRegistry? = nil,
        maximumSteps: Int = 8,
        contextPolicy: DSHContextPolicy = .init(),
        telemetry: any DSHAgentTelemetry = DSHNoopAgentTelemetry()
    ) {
        self.client = client
        self.model = model
        self.systemPrompt = systemPrompt
        self.messages = messages
        self.toolRegistry = toolRegistry
        self.maximumSteps = maximumSteps
        self.contextPolicy = contextPolicy
        self.telemetry = telemetry
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
        lastStreamingPublishAt = nil
        let turnID = UUID().uuidString
        let turnClock = ContinuousClock()
        let turnStartedAt = turnClock.now
        let attachmentCount = messages.reduce(0) { $0 + $1.attachments.count }
        let turnDetail = "history_messages=\(messages.count) attachments=\(attachmentCount)"
        await telemetry.started(source: "turn", name: "native.turn", detail: turnDetail, correlationID: turnID)
        var completedSteps = 0
        do {
            for step in 1...maximumSteps {
                completedSteps = step
                let assistantIndex = messages.count
                messages.append(.init(role: .assistant))
                phase = .streaming(step: step)
                publish()

                let requestMessages = contextPolicy.messagesForRequest(Array(messages.dropLast()), systemPrompt: systemPrompt)
                let modelID = "\(turnID)-model-\(step)"
                let modelClock = ContinuousClock()
                let modelStartedAt = modelClock.now
                let modelDetail = "step=\(step) messages=\(requestMessages.count) tools=\(toolRegistry?.definitions.count ?? 0)"
                await telemetry.started(source: "model", name: "model.stream", detail: modelDetail, correlationID: modelID)
                var firstEventAt: ContinuousClock.Instant?
                var toolCallFragments: [Int: ToolCallFragment] = [:]
                var finishReason: DSHFinishReason?
                do {
                    for try await event in client.stream(request: .init(
                        model: model,
                        messages: requestMessages,
                        tools: toolRegistry?.definitions ?? []
                    )) {
                        try Task.checkCancellation()
                        if firstEventAt == nil { firstEventAt = modelClock.now }
                        let forcePublish: Bool
                        switch event {
                        case .reasoningDelta(let text):
                            forcePublish = false
                            messages[assistantIndex].reasoningContent =
                                (messages[assistantIndex].reasoningContent ?? "") + text
                        case .contentDelta(let text):
                            forcePublish = false
                            messages[assistantIndex].content = (messages[assistantIndex].content ?? "") + text
                        case .toolCallDelta(let delta):
                            forcePublish = false
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
                            forcePublish = true
                            usage = value
                        case .completed(let reason):
                            forcePublish = true
                            finishReason = reason
                        }
                        publishStreaming(force: forcePublish)
                    }
                    let firstTokenMS = firstEventAt.map { Self.milliseconds(modelStartedAt.duration(to: $0)) } ?? -1
                    let result = "finish=\(finishReason?.rawValue ?? "stream_end") first_event_ms=\(firstTokenMS) prompt_tokens=\(usage?.promptTokens ?? 0) completion_tokens=\(usage?.completionTokens ?? 0)"
                    await telemetry.finished(source: "model", name: "model.stream", detail: modelDetail, result: result, outcome: "ok", duration: Self.seconds(modelStartedAt.duration(to: modelClock.now)), correlationID: modelID)
                } catch {
                    await telemetry.finished(source: "model", name: "model.stream", detail: modelDetail, result: "error=\(Self.errorCategory(error))", outcome: error is CancellationError ? "cancelled" : "error", duration: Self.seconds(modelStartedAt.duration(to: modelClock.now)), correlationID: modelID)
                    throw error
                }
                try Task.checkCancellation()

                let calls = messages[assistantIndex].toolCalls
                guard finishReason == .toolCalls, !calls.isEmpty, let toolRegistry else {
                    phase = .completed
                    publish()
                    await finishTurn(id: turnID, detail: turnDetail, outcome: "ok", steps: completedSteps, startedAt: turnStartedAt)
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
            await finishTurn(id: turnID, detail: turnDetail, outcome: "cancelled", steps: completedSteps, startedAt: turnStartedAt, error: "cancelled")
            throw CancellationError()
        } catch {
            phase = .failed(message: error.localizedDescription)
            publish()
            await finishTurn(id: turnID, detail: turnDetail, outcome: "error", steps: completedSteps, startedAt: turnStartedAt, error: Self.errorCategory(error))
            throw error
        }
    }

    private func finishTurn(
        id: String, detail: String, outcome: String, steps: Int,
        startedAt: ContinuousClock.Instant, error: String? = nil
    ) async {
        var result = "steps=\(steps) total_tokens=\(usage?.totalTokens ?? 0)"
        if let error { result += " error=\(error)" }
        await telemetry.finished(
            source: "turn", name: "native.turn", detail: detail, result: result,
            outcome: outcome, duration: Self.seconds(startedAt.duration(to: ContinuousClock().now)), correlationID: id
        )
    }

    private static func seconds(_ duration: Duration) -> TimeInterval {
        Double(duration.components.seconds) + Double(duration.components.attoseconds) / 1e18
    }

    private static func milliseconds(_ duration: Duration) -> Int {
        Int((seconds(duration) * 1_000).rounded())
    }

    static func errorCategory(_ error: Error) -> String {
        if error is CancellationError { return "cancelled" }
        if let error = error as? DSHModelClientError {
            switch error {
            case .invalidEndpoint: return "invalid_endpoint"
            case .invalidResponse: return "invalid_response"
            case .httpStatus(let status, _): return "http_\(status)"
            case .malformedEvent: return "malformed_stream"
            }
        }
        if let error = error as? URLError {
            switch error.code {
            case .notConnectedToInternet, .networkConnectionLost: return "offline"
            case .timedOut: return "network_timeout"
            case .cancelled: return "cancelled"
            default: return "network_\(error.code.rawValue)"
            }
        }
        if error is DSHToolError { return "tool_error" }
        return "internal_error"
    }

    private func publish() {
        let value = snapshot()
        for continuation in observers.values { continuation.yield(value) }
    }

    /// Streaming providers can deliver hundreds of tiny deltas per second.
    /// Updating SwiftUI and copying the message array for every fragment wastes
    /// CPU and battery; 30 Hz remains visually smooth while terminal events are
    /// always delivered immediately.
    private func publishStreaming(force: Bool) {
        let clock = ContinuousClock()
        let now = clock.now
        if !force, let lastStreamingPublishAt,
           lastStreamingPublishAt.duration(to: now) < .milliseconds(33) { return }
        self.lastStreamingPublishAt = now
        publish()
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
