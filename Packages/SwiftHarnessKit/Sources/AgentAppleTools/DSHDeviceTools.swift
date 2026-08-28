import AgentRuntime
import AgentTools

public struct DSHDeviceInformation: Codable, Equatable, Sendable {
    public let device: String
    public let systemName: String
    public let systemVersion: String
    public let localeIdentifier: String

    public init(device: String, systemName: String, systemVersion: String, localeIdentifier: String) {
        self.device = device
        self.systemName = systemName
        self.systemVersion = systemVersion
        self.localeIdentifier = localeIdentifier
    }
}

public enum DSHBatteryState: String, Codable, Equatable, Sendable {
    case unknown, unplugged, charging, full
}

public enum DSHThermalState: String, Codable, Equatable, Sendable {
    case nominal, fair, serious, critical, unknown
}

public struct DSHDevicePower: Codable, Equatable, Sendable {
    public let batteryLevel: Double?
    public let batteryState: DSHBatteryState
    public let lowPowerMode: Bool
    public let thermalState: DSHThermalState

    public init(
        batteryLevel: Double?,
        batteryState: DSHBatteryState,
        lowPowerMode: Bool,
        thermalState: DSHThermalState
    ) {
        self.batteryLevel = batteryLevel
        self.batteryState = batteryState
        self.lowPowerMode = lowPowerMode
        self.thermalState = thermalState
    }
}

public protocol DSHDeviceInformationProviding: Sendable {
    func information() async -> DSHDeviceInformation
}

public protocol DSHDevicePowerProviding: Sendable {
    func power() async -> DSHDevicePower
}

public struct DSHDeviceInformationTool: DSHNativeTool {
    public let definition = DSHToolDefinition(
        name: "device_info",
        description: "Read non-sensitive information about this iPhone or iPad.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([:]),
            "additionalProperties": .bool(false)
        ])
    )

    private let provider: any DSHDeviceInformationProviding

    public init(provider: any DSHDeviceInformationProviding) { self.provider = provider }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        try requireEmptyObject(arguments, tool: definition.name)
        let value = await provider.information()
        return .object([
            "device": .string(value.device),
            "system_name": .string(value.systemName),
            "system_version": .string(value.systemVersion),
            "locale": .string(value.localeIdentifier)
        ])
    }
}

public struct DSHDevicePowerTool: DSHNativeTool {
    public let definition = DSHToolDefinition(
        name: "device_power",
        description: "Read current battery, Low Power Mode, and thermal state.",
        parameters: .object([
            "type": .string("object"),
            "properties": .object([:]),
            "additionalProperties": .bool(false)
        ])
    )

    private let provider: any DSHDevicePowerProviding

    public init(provider: any DSHDevicePowerProviding) { self.provider = provider }

    public func execute(arguments: DSHJSONValue) async throws -> DSHJSONValue {
        try requireEmptyObject(arguments, tool: definition.name)
        let value = await provider.power()
        return .object([
            "battery_level": value.batteryLevel.map(DSHJSONValue.number) ?? .null,
            "battery_state": .string(value.batteryState.rawValue),
            "low_power_mode": .bool(value.lowPowerMode),
            "thermal_state": .string(value.thermalState.rawValue)
        ])
    }
}

private func requireEmptyObject(_ arguments: DSHJSONValue, tool: String) throws {
    guard case .object(let values) = arguments, values.isEmpty else {
        throw DSHToolError.invalidArguments("\(tool) accepts an empty object.")
    }
}
