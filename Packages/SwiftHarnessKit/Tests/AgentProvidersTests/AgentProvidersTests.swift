import Foundation
import XCTest
import AgentRuntime
@testable import AgentProviders

final class AgentProvidersTests: XCTestCase {
    func testSSEDecoderHandlesFragmentedCRLFAndMultipleEvents() throws {
        var decoder = DSHSSEDecoder()
        XCTAssertEqual(try decoder.append(Data("data: one\r\n".utf8)), [])
        XCTAssertEqual(
            try decoder.append(Data("\r\ndata: two\ndata: continued\n\n".utf8)),
            ["one", "two\ncontinued"]
        )
    }

    func testOpenAIRequestUsesStreamingWireShapeAndBearerToken() throws {
        let client = DSHOpenAICompatibleClient(
            baseURL: URL(string: "https://api.example.test/v1")!,
            apiKey: "secret"
        )
        let request = try client.makeURLRequest(.init(
            model: "deepseek-chat",
            messages: [.init(role: .user, content: "hello")]
        ))
        XCTAssertEqual(request.url?.absoluteString, "https://api.example.test/v1/chat/completions")
        XCTAssertEqual(request.value(forHTTPHeaderField: "Authorization"), "Bearer secret")
        let object = try XCTUnwrap(JSONSerialization.jsonObject(with: XCTUnwrap(request.httpBody)) as? [String: Any])
        XCTAssertEqual(object["stream"] as? Bool, true)
        XCTAssertEqual((object["stream_options"] as? [String: Any])?["include_usage"] as? Bool, true)
    }

    func testProviderErrorsExposePrivacySafeCategories() {
        XCTAssertEqual(DSHModelClientError.invalidEndpoint.agentErrorCategory, "invalid_endpoint")
        XCTAssertEqual(DSHModelClientError.httpStatus(429, "secret body").agentErrorCategory, "http_429")
        XCTAssertFalse(DSHModelClientError.httpStatus(429, "secret body").agentErrorCategory.contains("secret"))
    }
}
