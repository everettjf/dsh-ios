import Foundation
import UIKit

enum DSHToolError: Error, LocalizedError, Equatable, Sendable {
    case unknownTool(String)
    case invalidArguments(String)
    case disabled(String)
    case permissionDenied(String)
    case stepLimitExceeded

    var errorDescription: String? {
        switch self {
        case .unknownTool(let name): return "Unknown tool: \(name)"
        case .invalidArguments(let message): return "Invalid tool arguments: \(message)"
        case .disabled(let message): return message
        case .permissionDenied(let message): return message
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
        description: "Read non-sensitive information about this iPhone or iPad.",
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
            return .object([
                "device": .string(device.model),
                "system_name": .string(device.systemName),
                "system_version": .string(device.systemVersion),
                "locale": .string(Locale.current.identifier)
            ])
        }
    }
}

struct DSHDevicePowerTool: DSHNativeTool {
    let definition = DSHToolDefinition(
        name: "device_power",
        description: "Read current battery, Low Power Mode, and thermal state.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([:]),
            "additionalProperties": .bool(false)
        ])
    )

    func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        guard case .object(let values) = arguments, values.isEmpty else {
            throw DSHToolError.invalidArguments("device_power accepts an empty object.")
        }
        return await MainActor.run {
            let device = UIDevice.current
            device.isBatteryMonitoringEnabled = true
            return .object([
                "battery_level": device.batteryLevel < 0 ? .null : .number(Double(device.batteryLevel)),
                "battery_state": .string(Self.batteryState(device.batteryState)),
                "low_power_mode": .bool(ProcessInfo.processInfo.isLowPowerModeEnabled),
                "thermal_state": .string(Self.thermalState(ProcessInfo.processInfo.thermalState))
            ])
        }
    }

    private static func batteryState(_ state: UIDevice.BatteryState) -> String {
        switch state {
        case .unknown: return "unknown"
        case .unplugged: return "unplugged"
        case .charging: return "charging"
        case .full: return "full"
        @unknown default: return "unknown"
        }
    }

    private static func thermalState(_ state: ProcessInfo.ThermalState) -> String {
        switch state {
        case .nominal: return "nominal"
        case .fair: return "fair"
        case .serious: return "serious"
        case .critical: return "critical"
        @unknown default: return "unknown"
        }
    }
}
