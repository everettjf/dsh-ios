import XCTest
import AgentRuntime
import AgentProviders
import AgentTools
import AgentStorage
import AgentAppleTools
import AgentMCP

final class PublicAPITests: XCTestCase {
    func testStableVocabularyBuildsAsACompleteHostSurface() async throws {
        let provider: any ModelProvider = StubProvider()
        let tools = ToolRegistry([EchoTool()])
        let agent = HarnessAgent(client: provider, model: "test", toolRegistry: tools)
        let snapshot: AgentSnapshot = try await agent.send("hello")

        XCTAssertEqual(snapshot.messages.last?.content, "ready")
        let _: SessionStore = SessionStore()
        let _: DeviceInformationTool = DeviceInformationTool(provider: DeviceProvider())
        let _: MCPTransport.Type = URLSessionMCPTransport.self
    }
}

private struct StubProvider: ModelProvider {
    func stream(request: CompletionRequest) -> AsyncThrowingStream<ModelEvent, Error> {
        AsyncThrowingStream(ModelEvent.self, bufferingPolicy: .unbounded) { continuation in
            continuation.yield(.contentDelta("ready"))
            continuation.yield(.completed(.stop))
            continuation.finish()
        }
    }
}

private struct EchoTool: AgentTool {
    let definition = ToolDefinition(name: "echo", description: "Echo", parameters: .object([:]))

    func execute(arguments: JSONValue) async throws -> JSONValue { arguments }
}

private struct DeviceProvider: DeviceInformationProviding {
    func information() async -> DeviceInformation {
        .init(device: "test", systemName: "iOS", systemVersion: "16", localeIdentifier: "en_US")
    }
}
