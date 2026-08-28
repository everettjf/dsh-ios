# Swift Harness Kit product and extraction plan

## Decision

This Swift rewrite branch is the incubation line for a reusable, Swift-native
agent runtime. The work is no longer scoped as a source-compatible port of the
Node.js DeepSeek Harness. SHOS (the current DSHIOS application target)
remains the reference application and the first production consumer of the
library.

**Swift Harness Kit** is the framework name. The user-facing app and product
brand is **SHOS** (Swift Harness OS). Before public package distribution, the
framework still needs repository, Swift Package Index, trademark, and license
checks, but it will not be renamed again as part of this plan.

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
- SHOS must consume the same public API that third-party applications use.
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
| `AgentLinuxGuest` | Lazy iSH64/Alpine execution backend and workspace staging | separate optional GPL distribution |

The product names are stable for planning. Source types should avoid a new
global brand prefix where Swift module names already provide sufficient
namespace.

## Licensing and distribution boundary

The reusable pure-Swift packages should use a permissive license such as
Apache-2.0 or MIT so they can be embedded in commercial Apple-platform apps.

The iSH-derived emulator is GPL software and substantially increases the
download and build size. It must not be an unconditional dependency of the
core package. Distribute it as a separately selected `AgentLinuxGuest` product
or repository, with its source, license text, notices, and App Store obligations
preserved. SHOS may remain GPL while it bundles that guest.

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
- Preserve current SHOS behavior by adapting the app at each extraction step.

Exit: SHOS builds using package products and the core suite passes on macOS
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
- Make SHOS compile and function in a `NO_LINUX_GUEST` configuration.
- Produce and document the separately licensed guest distribution.

Exit: the lightweight demo has no guest payload; the full demo downloads or
bundles the guest only when explicitly selected.

### Phase 6 — Reference app and developer experience

- Refactor SHOS into a thin composition root and polished reference client.
- Provide DocC documentation, a minimal chat example, an Apple-tools example,
  an MCP example and a full Linux-workspace example.
- Add semantic versioning, changelog, API compatibility checks and CI across
  supported platforms.
- Measure cold launch, first token, memory, energy, package size and lazy guest
  startup as release gates.

Exit: a third-party developer can add the package and run a tool-using agent
without copying code from SHOS.

### Phase 7 — Independent release

- Complete the naming and trademark/package-index collision check.
- Select the permissive core license after confirming code provenance.
- Move the stabilized packages to their independent repository or repositories.
- Point SHOS at tagged package releases instead of local source targets.
- Publish `1.0.0` only after the public API, documentation and compatibility
  suite have been exercised by at least one second application.

Exit: the library and SHOS have independent release cadences.

## Immediate implementation backlog

1. Produce the current-type inventory and proposed module map.
2. Add `Package.swift` with an internal working package name.
3. Extract `DSHJSONValue`, message/tool models, `DSHModelClient`, SSE decoding,
   and the runtime into `AgentRuntime` and `AgentProviders`.
4. Move their XCTest coverage to package tests and run it with `swift test`.
5. Adapt SHOS to those package products without changing user-visible
   behavior.
6. Extract registry, policy and storage after the runtime seam is proven.
7. Integrate the official MCP Swift SDK only after the core dependency boundary
   is stable.

Every step on this branch must leave SHOS buildable, tested, committed, and
pushed. Extraction commits should be small enough that API and ownership
changes remain reviewable even though the product migration is forward-only.

The authoritative Phase 0 ownership audit is maintained in [the module
inventory](swift-harness-kit-module-inventory.md).

## Publication naming gate

Use **Swift Harness Kit** for the framework and **SHOS** for the app. Before
Phase 7, verify that the repository/package identity and legal presentation are
publishable, while keeping the Swift module names (`AgentRuntime`,
`AgentProviders`, and so on) stable.

All forward development stays on
`rewrite-deepseek-harness-with-swift`. Do not merge this branch into `main`;
`main` remains the Node.js DeepSeek Harness line. Every modification on the
rewrite branch must be committed and pushed.
