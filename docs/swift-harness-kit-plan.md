# Swift Harness Kit product and extraction plan

## Decision

This Swift rewrite branch is the incubation line for a reusable, Swift-native
agent runtime. The work is no longer scoped as a source-compatible port of the
Node.js DeepSeek Harness. Dashros (the current DSHIOS application target)
remains the reference application and the first production consumer of the
library.

**Swift Harness Kit** is the current internal working name. The user-facing app
and product brand is **Dashros**. The framework name communicates its role
clearly, but it is not yet the final package or repository name: `HarnessKit`
and `Swift Harness` are already used by other projects. A distinct final
package identity must be selected before publishing packages or moving the code
to a new repository.

The product promise is:

> A Swift-native agent runtime for Apple platforms with streaming model
> providers, governed tools, MCP, durable sessions, and an optional lazy Linux
> workspace.

DeepSeek is a supported provider and the default in the demo, not the identity
or compatibility boundary of the library.

## Principles

- Swift concurrency is the runtime foundation: actors, `Sendable`, structured
  cancellation, and `AsyncSequence` event streams.
- The core package has no UI, iSH, DeepSeek, UIKit, or application-singleton
  dependency.
- Model providers, storage, tools, authorization, telemetry, and execution
  backends are replaceable through public protocols.
- Native Apple tools and SwiftUI components are optional products.
- Linux starts only after a governed tool explicitly requests it.
- MCP and native tools are the supported extension surfaces. Compatibility with
  arbitrary legacy dsh plugins is not a goal.
- Dashros must consume the same public API that third-party applications use.
- Public APIs follow semantic versioning; persisted schemas migrate forward.

## Package products

| Product | Responsibility | Dependencies |
|---|---|---|
| `AgentRuntime` | Turn/step orchestration, context limits, retries, cancellation, event stream | Foundation only |
| `AgentProviders` | OpenAI-compatible and DeepSeek transports, SSE and wire models | `AgentRuntime` |
| `AgentTools` | Tool definitions, registry, policies, confirmations, audit events | `AgentRuntime` |
| `AgentMCP` | MCP discovery, connections and tool adapters | official MCP Swift SDK |
| `AgentStorage` | Sessions, workspaces, attachments and schema migration | `AgentRuntime` |
| `AgentAppleTools` | Health, Location, Contacts, Calendar, Reminders, Photos and sharing | selected Apple frameworks |
| `AgentUI` | Optional SwiftUI chat, tool activity and settings components | runtime products only |
| `AgentLinuxGuest` | Lazy iSH-ARM64/Alpine execution backend and workspace staging | separate GPL distribution |

The exact public product names remain provisional until the final brand is
chosen. Source types should avoid a new global brand prefix where Swift module
names already provide sufficient namespace.

## Licensing and distribution boundary

The reusable pure-Swift packages should use a permissive license such as
Apache-2.0 or MIT so they can be embedded in commercial Apple-platform apps.

The iSH-derived emulator is GPL software and substantially increases the
download and build size. It must not be an unconditional dependency of the
core package. Distribute it as a separately selected `AgentLinuxGuest` product
or repository, with its source, license text, notices, and App Store obligations
preserved. Dashros may remain GPL while it bundles that guest.

Applications should be able to choose one of three execution configurations:

1. Native tools and MCP only, with no Linux payload.
2. The explicitly selected GPL Linux guest.
3. A custom `ExecutionBackend`, such as a remote container or application-owned
   sandbox.

Legal review is required before publishing the split packages. This document
records the intended engineering boundary, not legal advice.

## Target public API

The first stable API should be small and protocol-oriented:

```swift
public actor AgentRuntime {
    public init(
        model: any ModelProvider,
        tools: any ToolProviding,
        storage: any SessionStoring,
        policy: any ToolAuthorizationPolicy,
        telemetry: any AgentTelemetry
    )

    public func run(_ input: AgentInput) -> AsyncThrowingStream<AgentEvent, Error>
    public func cancel()
}

public protocol ModelProvider: Sendable { /* streaming completion */ }
public protocol AgentTool: Sendable { /* schema and execution */ }
public protocol SessionStoring: Sendable { /* durable sessions */ }
public protocol ExecutionBackend: Sendable { /* optional shell/workspace */ }
```

`AgentEvent` is the sole streaming contract for text deltas, reasoning deltas,
tool lifecycle, usage, recoverable errors, cancellation, and completion. UI and
telemetry consumers observe events without reaching into runtime internals.

## Extraction phases

### Phase 0 — Freeze the boundary

- Record the product and licensing decisions in this document.
- Inventory every current `DSH*` Swift type and classify it as core, provider,
  tool, storage, MCP, Apple integration, guest, UI, or app composition.
- Define the minimum supported Swift and Apple platform versions.
- Add an architecture dependency test that rejects core imports of UIKit,
  SwiftUI, Security, HealthKit, EventKit, Photos, or iSH symbols.

Exit: an approved module map and dependency graph with no ambiguous ownership.

### Phase 1 — Create the local Swift package

- Add `Package.swift` inside this repository; do not create a new repository yet.
- Extract models, SSE, model-provider protocol, agent loop, tool contracts, and
  in-memory test doubles.
- Make core tests run with `swift test`, independently of Xcode and the guest.
- Preserve current Dashros behavior by adapting the app at each extraction step.

Exit: Dashros builds using package products and the core suite passes on macOS
and the iOS simulator.

### Phase 2 — Stabilize runtime and providers

- Replace app-specific names, singletons, defaults, and Objective-C telemetry
  calls with injected protocols.
- Formalize bounded multi-step execution, tool-call fragment assembly,
  cancellation, retry and continuation behavior.
- Ship DeepSeek/OpenAI-compatible support as a provider implementation rather
  than core behavior.
- Add protocol fixtures for fragmented SSE, malformed payloads, parallel tool
  calls, rate limits and resumable failures.

Exit: the same deterministic conformance suite can test any model provider.

### Phase 3 — Tools, authorization and storage

- Move the registry, governed-tool wrapper, confirmation policy, audit events,
  sessions, workspaces and attachments behind public protocols.
- Keep platform permission prompts in `AgentAppleTools` or the application.
- Define secure defaults: bounded output, timeouts, write confirmation,
  redacted telemetry and explicit workspace scopes.

Exit: a sample app can replace storage and authorization without forking the
runtime.

### Phase 4 — Adopt the official MCP Swift SDK

- Use the official MCP Swift SDK for protocol types and supported transports.
- Keep an adapter layer so MCP version changes do not leak through every public
  API.
- Add interoperability fixtures for discovery, cancellation, reconnect,
  authentication, duplicate tool names and schema errors.

Exit: at least two independent MCP servers pass the integration suite.

### Phase 5 — Isolate the Linux guest

- Define `ExecutionBackend` without iSH-specific types.
- Move lazy boot, process execution, staging, quotas and lifecycle events behind
  the backend.
- Make Dashros compile and function in a `NO_LINUX_GUEST` configuration.
- Produce and document the separately licensed guest distribution.

Exit: the lightweight demo has no guest payload; the full demo downloads or
bundles the guest only when explicitly selected.

### Phase 6 — Reference app and developer experience

- Refactor Dashros into a thin composition root and polished reference client.
- Provide DocC documentation, a minimal chat example, an Apple-tools example,
  an MCP example and a full Linux-workspace example.
- Add semantic versioning, changelog, API compatibility checks and CI across
  supported platforms.
- Measure cold launch, first token, memory, energy, package size and lazy guest
  startup as release gates.

Exit: a third-party developer can add the package and run a tool-using agent
without copying code from Dashros.

### Phase 7 — Independent release

- Complete the naming and trademark/package-index collision check.
- Select the permissive core license after confirming code provenance.
- Move the stabilized packages to their independent repository or repositories.
- Point Dashros at tagged package releases instead of local source targets.
- Publish `1.0.0` only after the public API, documentation and compatibility
  suite have been exercised by at least one second application.

Exit: the library and Dashros have independent release cadences.

## Immediate implementation backlog

1. Produce the current-type inventory and proposed module map.
2. Add `Package.swift` with an internal working package name.
3. Extract `DSHJSONValue`, message/tool models, `DSHModelClient`, SSE decoding,
   and the runtime into `AgentRuntime` and `AgentProviders`.
4. Move their XCTest coverage to package tests and run it with `swift test`.
5. Adapt Dashros to those package products without changing user-visible
   behavior.
6. Extract registry, policy and storage after the runtime seam is proven.
7. Integrate the official MCP Swift SDK only after the core dependency boundary
   is stable.

Every step on this branch must leave Dashros buildable, tested, committed, and
pushed. Extraction commits should be small enough that API and ownership
changes remain reviewable even though the product migration is forward-only.

The authoritative Phase 0 ownership audit is maintained in [the module
inventory](swift-harness-kit-module-inventory.md).

## Naming gate

`Swift Harness Kit` is a good descriptive internal program name, but a weak
final unique package brand. Current ecosystem conflicts include existing
projects named `HarnessKit` and `Swift Harness`. Before Phase 7, choose a
distinctive repository and package identity while retaining a descriptive
subtitle such as “a Swift-native agent harness for Apple platforms.” Until
then, use **Swift Harness Kit** in planning documents and internal milestones;
use **Dashros** for the app and user-facing product.
