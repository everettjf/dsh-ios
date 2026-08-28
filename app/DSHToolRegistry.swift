import Foundation
import UIKit

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
