import Testing
import AgentRuntime
import AgentTools
@testable import AgentAppleTools

@Suite("Agent Apple tools")
struct AgentAppleToolsTests {
    @Test("device tools expose stable privacy-safe values")
    func deviceTools() async throws {
        let info = DSHDeviceInformationTool(provider: FixedDeviceInformationProvider())
        let power = DSHDevicePowerTool(provider: FixedDevicePowerProvider())

        #expect(info.definition.name == "device_info")
        #expect(power.definition.name == "device_power")
        #expect(try await info.execute(arguments: .object([:])) == .object([
            "device": .string("Phone"),
            "system_name": .string("iOS"),
            "system_version": .string("16.0"),
            "locale": .string("en_US")
        ]))
        #expect(try await power.execute(arguments: .object([:])) == .object([
            "battery_level": .number(0.5),
            "battery_state": .string("charging"),
            "low_power_mode": .bool(true),
            "thermal_state": .string("fair")
        ]))
    }

    @Test("read tools validate and map bounded arguments")
    func readRoutes() async throws {
        let executor = RecordingExecutor()
        _ = try await DSHAppleReadTool(.contacts, executor: executor).execute(arguments: .object([
            "query": .string("Ada"), "limit": .number(3)
        ]))
        _ = try await DSHAppleReadTool(.health, executor: executor).execute(arguments: .object([
            "metric": .string("activity"), "days": .number(7)
        ]))

        let calls = await executor.calls
        #expect(calls.map(\.path) == ["/v1/contacts", "/v1/health/activity"])
        #expect(calls[0].query == ["q": "Ada", "limit": "3"])
        #expect(calls[1].query == ["days": "7"])
    }

    @Test("write tools preserve body and reject oversized sharing")
    func writeRoutes() async throws {
        let executor = RecordingExecutor()
        _ = try await DSHAppleWriteTool(.notify, executor: executor).execute(arguments: .object([
            "title": .string("Done")
        ]))
        await #expect(throws: DSHToolError.invalidArguments("text must be at most 4000 characters.")) {
            _ = try await DSHAppleWriteTool(.share, executor: executor).execute(arguments: .object([
                "text": .string(String(repeating: "x", count: 4_001))
            ]))
        }

        let calls = await executor.calls
        #expect(calls.count == 1)
        #expect(calls[0].method == "POST")
        #expect(calls[0].path == "/v1/notify")
    }

    @Test("product defines all thirteen stable tool names")
    func definitions() {
        let executor = RecordingExecutor()
        let reads = DSHAppleReadToolKind.allCases.map { DSHAppleReadTool($0, executor: executor).definition.name }
        let writes = DSHAppleWriteToolKind.allCases.map { DSHAppleWriteTool($0, executor: executor).definition.name }
        #expect(Set(reads + writes).count == 13)
        #expect(reads.contains("health_query"))
        #expect(writes.contains("calendar_create_event"))
    }
}

private struct FixedDeviceInformationProvider: DSHDeviceInformationProviding {
    func information() async -> DSHDeviceInformation {
        .init(device: "Phone", systemName: "iOS", systemVersion: "16.0", localeIdentifier: "en_US")
    }
}

private struct FixedDevicePowerProvider: DSHDevicePowerProviding {
    func power() async -> DSHDevicePower {
        .init(batteryLevel: 0.5, batteryState: .charging, lowPowerMode: true, thermalState: .fair)
    }
}

private actor RecordingExecutor: DSHAppleRouteExecuting {
    struct Call: Sendable {
        let method: String
        let path: String
        let query: [String: String]
        let json: DSHJSONValue?
    }

    private(set) var calls: [Call] = []

    func invoke(method: String, path: String, query: [String: String], json: DSHJSONValue?) async throws -> DSHJSONValue {
        calls.append(.init(method: method, path: path, query: query, json: json))
        return .object(["accepted": .bool(true)])
    }
}
