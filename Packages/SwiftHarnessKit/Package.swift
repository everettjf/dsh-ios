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
        .library(name: "AgentProviders", targets: ["AgentProviders"]),
        .library(name: "AgentTools", targets: ["AgentTools"]),
        .library(name: "AgentStorage", targets: ["AgentStorage"]),
        .library(name: "AgentAppleTools", targets: ["AgentAppleTools"]),
        .library(name: "AgentMCP", targets: ["AgentMCP"]),
        .library(name: "AgentLinuxGuest", targets: ["AgentLinuxGuest"])
    ],
    dependencies: [
        .package(url: "https://github.com/modelcontextprotocol/swift-sdk.git", exact: "0.12.1")
    ],
    targets: [
        .target(name: "AgentRuntime"),
        .target(name: "AgentProviders", dependencies: ["AgentRuntime"]),
        .target(name: "AgentTools", dependencies: ["AgentRuntime"]),
        .target(name: "AgentStorage", dependencies: ["AgentRuntime"]),
        .target(name: "AgentAppleTools", dependencies: ["AgentRuntime", "AgentTools"]),
        .target(
            name: "AgentLinuxGuest",
            dependencies: ["AgentRuntime", "AgentTools", "AgentStorage"]
        ),
        .target(
            name: "AgentMCP",
            dependencies: [
                "AgentRuntime",
                "AgentProviders",
                "AgentTools",
                .product(name: "MCP", package: "swift-sdk")
            ]
        ),
        .testTarget(name: "AgentRuntimeTests", dependencies: ["AgentRuntime", "AgentTools"]),
        .testTarget(name: "AgentProvidersTests", dependencies: ["AgentRuntime", "AgentProviders"]),
        .testTarget(name: "AgentToolsTests", dependencies: ["AgentRuntime", "AgentTools"]),
        .testTarget(name: "AgentStorageTests", dependencies: ["AgentRuntime", "AgentStorage"]),
        .testTarget(
            name: "AgentAppleToolsTests",
            dependencies: ["AgentRuntime", "AgentTools", "AgentAppleTools"]
        ),
        .testTarget(
            name: "AgentLinuxGuestTests",
            dependencies: ["AgentRuntime", "AgentTools", "AgentStorage", "AgentLinuxGuest"]
        ),
        .testTarget(
            name: "AgentMCPTests",
            dependencies: [
                "AgentRuntime",
                "AgentProviders",
                "AgentTools",
                "AgentMCP",
                .product(name: "MCP", package: "swift-sdk")
            ]
        ),
        .testTarget(
            name: "PublicAPITests",
            dependencies: [
                "AgentRuntime",
                "AgentProviders",
                "AgentTools",
                "AgentStorage",
                "AgentAppleTools",
                "AgentMCP"
            ]
        )
    ]
)
