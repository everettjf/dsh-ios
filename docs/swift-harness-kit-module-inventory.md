# Swift Harness Kit module inventory

This document began as the Phase 0 ownership baseline for extracting the
reusable runtime from SHOS. It now records both that baseline and the verified
completion state of the in-repository Swift Harness Kit 0.1 extraction.

## Baseline evidence

- Branch: `rewrite-deepseek-harness-with-swift`
- Baseline commit: `b56614a`
- Xcode: 27 beta, Release configuration
- Simulator: iPad Air 11-inch (M4), iOS 27
- `DSHNativeCoreTests`: 40 tests, 0 failures

The baseline covers fragmented SSE, OpenAI wire encoding, reasoning/content,
tool-call assembly, multi-step execution, cancellation, retry, continuation,
bounded context, 10,000 deltas, sessions, workspace isolation, governed tools,
native routes, MCP, lazy guest boot, attachment staging and private telemetry.

## Target dependency graph

```text
AgentRuntime       Foundation-only models, runtime, events and protocols
    ↑
AgentProviders     OpenAI-compatible/DeepSeek transport and SSE
AgentTools         registry, governance and audit contracts
AgentStorage       sessions, workspaces and attachments
AgentMCP           official MCP SDK adapter and tool projection
    ↑
AgentAppleTools    Apple-framework implementations
AgentLinuxGuest    portable lazy Linux host, bash and attachment-staging contracts
AgentUI            reusable SwiftUI components
    ↑
SHOS            app composition, Keychain settings and product UI
```

Arrows point from a consumer to its lower-level dependency. No lower-level
module may import a higher-level module.

## Swift source ownership

| Current file | Target owner | Required extraction work |
|---|---|---|
| `DSHNativeModels.swift` | `AgentRuntime` | Make stable value types and `ModelProvider` public; remove product prefix in a later API pass |
| `DSHAgentRuntime.swift` | `AgentRuntime` | Move Objective-C activity adapter out; depend on tool-providing protocol instead of concrete registry |
| `DSHSSEDecoder.swift` | `AgentProviders` | Public/testable streaming decoder; retain bounded buffering behavior |
| `DSHOpenAICompatibleClient.swift` | `AgentProviders` | Import Runtime; expose Provider implementation and HTTP test seam |
| `DSHToolRegistry.swift` | `AgentTools` + `AgentAppleTools` | Split UIKit device implementations from Foundation-only registry |
| `DSHNativeToolPolicy.swift` | `AgentTools` + SHOS adapter | Keep policy/contracts in package; move defaults and Objective-C audit sink to app integration |
| `DSHSessionStore.swift` | `AgentStorage` | Split UniformTypeIdentifiers import and file import policy if needed; expose storage protocols |
| `DSHMCPClient.swift` | `AgentMCP` | Replace hand-written protocol layer behind adapter with official MCP Swift SDK |
| `DSHMCPServerManager.swift` | `AgentMCP` + SHOS | Move Keychain configuration persistence to SHOS; keep connection manager in package |
| `DSHLazyGuestManager.swift` | `AgentLinuxGuest` + SHOS adapter | Package owns the iSH-free lazy host/tools; SHOS owns iSH and native confirmation adapters |
| `DSHNativeReadTools.swift` | `AgentAppleTools` | Keep route executor injectable; remove app singleton assumptions |
| `DSHNativeWriteTools.swift` | `AgentAppleTools` | Keep validation before UI/system access; retain stable schemas |
| `DSHAgentConfiguration.swift` | SHOS | Product settings and Keychain storage stay in app composition |
| `DSHAgentViewModel.swift` | SHOS / later `AgentUI` seams | Keep product orchestration in app; expose only reusable event-to-view state where proven |
| `DSHNativeRootView.swift` | SHOS | Product UI; split reusable components only after runtime boundaries stabilize |

## Objective-C and iSH ownership

The existing Objective-C capability implementations, confirmations, activity
view, App/Scene delegates and host bridge remain SHOS/`AgentAppleTools`
integration code. They are not copied into the pure Swift Core.

`DSHGuestRuntime`, `DSHGuestLauncher`, the vendored `ish-arm64` tree and the
Alpine rootfs belong to the separately licensed `AgentLinuxGuest` boundary.
Their types must never appear in `AgentRuntime` public signatures.

## Resolved baseline dependency violations

1. Runtime telemetry is injected; the Objective-C activity adapter lives in SHOS.
2. Device schemas/providers live in `AgentAppleTools`; UIKit adapters stay in SHOS.
3. MCP protocol behavior uses the official Swift SDK in `AgentMCP`; Keychain
   configuration stays in SHOS.
4. Reusable session/workspace storage lives in `AgentStorage`; host file UI stays
   outside the core package.
5. `AgentLinuxGuest` exposes an iSH-free execution contract; the concrete iSH64
   host remains in SHOS.
6. SHOS, SHOSLite, and HarnessChat link package products through their public APIs.

## Enforced extraction rules

- `AgentRuntime` may import only Foundation (and Swift standard-library
  modules).
- `AgentProviders`, `AgentTools` and `AgentStorage` may not import UIKit,
  SwiftUI, HealthKit, EventKit, Photos or iSH headers.
- Security/Keychain persistence belongs to the app unless a separately tested
  credential-store product is introduced.
- `AgentLinuxGuest` is optional; `NO_LINUX_GUEST` must compile and run native
  agent, storage, native tools and MCP flows.
- `SHOSLite` is the executable acceptance fixture for that boundary. Its
  Release bundle is rejected if it contains iSH/rootfs files, emulator
  libraries, or guest-tool symbols.
- SHOS must compile against package products rather than duplicate the same
  source files in the app target.
- Package tests are the authority for pure Swift behavior; hosted XCTest covers
  Apple integration and Objective-C bridges.

## In-repository extraction status

Phases 0–6 of the in-repository extraction are complete for Swift Harness Kit
0.1.0. The package exposes Runtime, Providers, Tools, Storage, AppleTools, MCP,
and LinuxGuest products with DocC and package-native tests. The official MCP
Swift SDK adapter is exercised against independent Node and Python fixtures.
HarnessChat is a second iOS 16 host, and SHOSLite proves a Release bundle can be
built without iSH symbols, rootfs, or guest tools.

The remaining Phase 7 work is intentionally a separate public-distribution
milestone: legal/trademark review, moving the package to its own repository,
Swift Package Index publication, and validation by an external adopter. Those
external publication steps are not requirements of the SHOS 1.0.15 TestFlight
release.
