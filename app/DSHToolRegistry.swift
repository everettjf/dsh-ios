import Foundation
import UIKit

enum DSHToolError: Error, LocalizedError, Equatable, Sendable {
    case unknownTool(String)
    case invalidArguments(String)
    case disabled(String)
    case stepLimitExceeded

    var errorDescription: String? {
        switch self {
        case .unknownTool(let name): return "Unknown tool: \(name)"
        case .invalidArguments(let message): return "Invalid tool arguments: \(message)"
        case .disabled(let name): return "The user has disabled \(name)."
        case .stepLimitExceeded: return "The agent exceeded the tool step limit."
        }
    }
}

protocol DSHNativeTool: Sendable {
    var definition: DSHToolDefinition { get }
    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue
}

struct DSHToolRegistry: Sendable {
    private let tools: [String: any DSHNativeTool]

    init(_ tools: [any DSHNativeTool] = []) {
        self.tools = Dictionary(uniqueKeysWithValues: tools.map { ($0.definition.name, $0) })
    }

    var definitions: [DSHToolDefinition] {
        tools.values.map(\.definition).sorted { $0.name < $1.name }
    }

    func execute(_ call: DSHToolCall) async -> String {
        guard let tool = tools[call.name] else {
            return encodeError(DSHToolError.unknownTool(call.name))
        }
        do {
            let arguments: DSHJSONValue
            if call.arguments.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
                arguments = .object([:])
            } else {
                guard let data = call.arguments.data(using: .utf8) else {
                    throw DSHToolError.invalidArguments("Arguments are not UTF-8.")
                }
                do {
                    arguments = try JSONDecoder().decode(DSHJSONValue.self, from: data)
                } catch {
                    throw DSHToolError.invalidArguments("Expected a JSON value.")
                }
            }
            return try encode(["ok": .bool(true), "result": try await tool.execute(arguments: arguments)])
        } catch {
            return encodeError(error)
        }
    }

    private func encodeError(_ error: Error) -> String {
        encode(["ok": .bool(false), "error": .string(error.localizedDescription)])
    }

    private func encode(_ object: [String: DSHJSONValue]) -> String {
        guard let data = try? JSONEncoder().encode(DSHJSONValue.object(object)) else {
            return "{\"ok\":false,\"error\":\"Could not encode tool result.\"}"
        }
        return String(decoding: data, as: UTF8.self)
    }
}

struct DSHDeviceInfoTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "device_info",
        description: "Read non-sensitive information about this iPhone or iPad and its current power state.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([:]),
            "additionalProperties": .bool(false)
        ])
    )

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments, values.isEmpty else {
            throw DSHToolError.invalidArguments("device_info accepts an empty object.")
        }
        return await MainActor.run {
            let device = UIDevice.current
            device.isBatteryMonitoringEnabled = true
            return .object([
                "device": .string(device.model),
                "system_name": .string(device.systemName),
                "system_version": .string(device.systemVersion),
                "locale": .string(Locale.current.identifier),
                "battery_level": device.batteryLevel < 0 ? .null : .number(Double(device.batteryLevel)),
                "low_power_mode": .bool(ProcessInfo.processInfo.isLowPowerModeEnabled),
                "thermal_state": .string(String(describing: ProcessInfo.processInfo.thermalState))
            ])
        }
    }
}
