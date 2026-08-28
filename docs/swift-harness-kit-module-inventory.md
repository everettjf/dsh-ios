# Swift Harness Kit module inventory

This is the Phase 0 ownership baseline for extracting the reusable runtime from
the current Dashros (DSHIOS target) implementation. It records current source
authority, intended package ownership, known dependency violations, and the
evidence that must remain green during extraction.

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
Dashros            app composition, Keychain settings and product UI
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
| `DSHNativeToolPolicy.swift` | `AgentTools` + Dashros adapter | Keep policy/contracts in package; move defaults and Objective-C audit sink to app integration |
| `DSHSessionStore.swift` | `AgentStorage` | Split UniformTypeIdentifiers import and file import policy if needed; expose storage protocols |
| `DSHMCPClient.swift` | `AgentMCP` | Replace hand-written protocol layer behind adapter with official MCP Swift SDK |
| `DSHMCPServerManager.swift` | `AgentMCP` + Dashros | Move Keychain configuration persistence to Dashros; keep connection manager in package |
| `DSHLazyGuestManager.swift` | `AgentLinuxGuest` + Dashros adapter | Package owns the iSH-free lazy host/tools; Dashros owns iSH and native confirmation adapters |
| `DSHNativeReadTools.swift` | `AgentAppleTools` | Keep route executor injectable; remove app singleton assumptions |
| `DSHNativeWriteTools.swift` | `AgentAppleTools` | Keep validation before UI/system access; retain stable schemas |
| `DSHAgentConfiguration.swift` | Dashros | Product settings and Keychain storage stay in app composition |
| `DSHAgentViewModel.swift` | Dashros / later `AgentUI` seams | Keep product orchestration in app; expose only reusable event-to-view state where proven |
| `DSHNativeRootView.swift` | Dashros | Product UI; split reusable components only after runtime boundaries stabilize |

## Objective-C and iSH ownership

The existing Objective-C capability implementations, confirmations, activity
view, App/Scene delegates and host bridge remain Dashros/`AgentAppleTools`
integration code. They are not copied into the pure Swift Core.

`DSHGuestRuntime`, `DSHGuestLauncher`, the vendored `ish-arm64` tree and the
Alpine rootfs belong to the separately licensed `AgentLinuxGuest` boundary.
Their types must never appear in `AgentRuntime` public signatures.

## Confirmed dependency violations to remove

1. `DSHAgentRuntime.swift` implements `DSHActivityAgentTelemetry` by directly
   calling the Objective-C `DSHNativeToolAudit` singleton.
2. `DSHToolRegistry.swift` imports UIKit and includes `UIDevice` tools beside
   the otherwise reusable registry.
3. `DSHMCPServerManager.swift` combines reusable connection management with
   Security/Keychain product configuration.
4. `DSHSessionStore.swift` combines durable storage with Apple-specific file
   type handling.
5. `DSHLazyGuestManager.swift` combines generic approval/tool contracts with
   the concrete iSH host.
6. The generated Xcode target compiles every `app/*.swift` file directly, so
   Dashros does not yet prove that it consumes package public APIs.

## Enforced extraction rules

- `AgentRuntime` may import only Foundation (and Swift standard-library
  modules).
- `AgentProviders`, `AgentTools` and `AgentStorage` may not import UIKit,
  SwiftUI, HealthKit, EventKit, Photos or iSH headers.
- Security/Keychain persistence belongs to the app unless a separately tested
  credential-store product is introduced.
- `AgentLinuxGuest` is optional; `NO_LINUX_GUEST` must compile and run native
  agent, storage, native tools and MCP flows.
- `DashrosLite` is the executable acceptance fixture for that boundary. Its
  Release bundle is rejected if it contains iSH/rootfs files, emulator
  libraries, or guest-tool symbols.
- Dashros must compile against package products rather than duplicate the same
  source files in the app target.
- Package tests are the authority for pure Swift behavior; hosted XCTest covers
  Apple integration and Objective-C bridges.

## Phase 0 exit status

Phase 0 is complete when this inventory is committed, the 40-test baseline is
green, and the next change creates package targets without weakening any
existing acceptance requirement. The first extraction slice is:

1. Runtime value models and protocols.
2. Foundation-only tool protocol/registry.
3. Runtime state machine using the tool-providing abstraction.
4. SSE and OpenAI-compatible provider.
5. Package-native copies of the corresponding deterministic tests.
