// swift-tools-version: 6.0
import PackageDescription

let package = Package(
    name: "SwiftHarnessKit",
    platforms: [
        .iOS(.v16),
        .macOS(.v13)
    ],
    products: [
        .library(name: "AgentRuntime", targets: ["AgentRuntime"]),
        .library(name: "AgentProviders", targets: ["AgentProviders"])
    ],
    targets: [
        .target(name: "AgentRuntime"),
        .target(name: "AgentProviders", dependencies: ["AgentRuntime"]),
        .testTarget(name: "AgentRuntimeTests", dependencies: ["AgentRuntime"]),
        .testTarget(name: "AgentProvidersTests", dependencies: ["AgentRuntime", "AgentProviders"])
    ]
)
