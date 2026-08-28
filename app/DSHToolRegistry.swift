import Foundation
import UIKit
import AgentRuntime
import AgentTools
import AgentStorage
import AgentMCP
import AgentAppleTools

struct DSHSystemDeviceInformationProvider: DSHDeviceInformationProviding {
    func information() async -> DSHDeviceInformation {
        await MainActor.run {
            let device = UIDevice.current
            return DSHDeviceInformation(
                device: device.model,
                systemName: device.systemName,
                systemVersion: device.systemVersion,
                localeIdentifier: Locale.current.identifier
            )
        }
    }
}

struct DSHSystemDevicePowerProvider: DSHDevicePowerProviding {
    func power() async -> DSHDevicePower {
        await MainActor.run {
            let device = UIDevice.current
            device.isBatteryMonitoringEnabled = true
            return DSHDevicePower(
                batteryLevel: device.batteryLevel < 0 ? nil : Double(device.batteryLevel),
                batteryState: Self.batteryState(device.batteryState),
                lowPowerMode: ProcessInfo.processInfo.isLowPowerModeEnabled,
                thermalState: Self.thermalState(ProcessInfo.processInfo.thermalState)
            )
        }
    }

    private static func batteryState(_ state: UIDevice.BatteryState) -> DSHBatteryState {
        switch state {
        case .unknown: return .unknown
        case .unplugged: return .unplugged
        case .charging: return .charging
        case .full: return .full
        @unknown default: return .unknown
        }
    }

    private static func thermalState(_ state: ProcessInfo.ThermalState) -> DSHThermalState {
        switch state {
        case .nominal: return .nominal
        case .fair: return .fair
        case .serious: return .serious
        case .critical: return .critical
        @unknown default: return .unknown
        }
    }
}
