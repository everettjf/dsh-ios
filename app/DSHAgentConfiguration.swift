import Foundation
import Security

struct DSHAgentConfiguration: Equatable, Sendable {
    var endpoint: String
    var apiKey: String
    var model: String

    static let defaultEndpoint = "https://api.deepseek.com/v1"
    static let defaultModel = "deepseek-chat"
}

enum DSHAgentConfigurationStore {
    private static let endpointKey = "native.agent.endpoint"
    private static let modelKey = "native.agent.model"
    private static let keychainService = "com.xnuapp.dsh.model"
    private static let keychainAccount = "deepseek-api-key"

    static func load() -> DSHAgentConfiguration {
        let defaults = UserDefaults.standard
        return .init(
            endpoint: defaults.string(forKey: endpointKey) ?? DSHAgentConfiguration.defaultEndpoint,
            apiKey: loadAPIKey(),
            model: defaults.string(forKey: modelKey) ?? DSHAgentConfiguration.defaultModel
        )
    }

    static func save(_ configuration: DSHAgentConfiguration) throws {
        UserDefaults.standard.set(configuration.endpoint, forKey: endpointKey)
        UserDefaults.standard.set(configuration.model, forKey: modelKey)
        let query: [String: Any] = [
            kSecClass as String: kSecClassGenericPassword,
            kSecAttrService as String: keychainService,
            kSecAttrAccount as String: keychainAccount
        ]
        SecItemDelete(query as CFDictionary)
        guard !configuration.apiKey.isEmpty else { return }
        var item = query
        item[kSecValueData as String] = Data(configuration.apiKey.utf8)
        item[kSecAttrAccessible as String] = kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
        let status = SecItemAdd(item as CFDictionary, nil)
        guard status == errSecSuccess else {
            throw NSError(domain: NSOSStatusErrorDomain, code: Int(status))
        }
    }

    private static func loadAPIKey() -> String {
        let query: [String: Any] = [
            kSecClass as String: kSecClassGenericPassword,
            kSecAttrService as String: keychainService,
            kSecAttrAccount as String: keychainAccount,
            kSecReturnData as String: true,
            kSecMatchLimit as String: kSecMatchLimitOne
        ]
        var result: CFTypeRef?
        guard SecItemCopyMatching(query as CFDictionary, &result) == errSecSuccess,
              let data = result as? Data else { return "" }
        return String(data: data, encoding: .utf8) ?? ""
    }
}
