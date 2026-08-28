import Foundation

/// The minimal tool surface required by AgentRuntime. Concrete registries,
/// governance and platform tools live in AgentTools or higher-level modules.
public protocol DSHToolProviding: Sendable {
    var definitions: [DSHToolDefinition] { get }
    func execute(_ call: DSHToolCall) async -> String
}
