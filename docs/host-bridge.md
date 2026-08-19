# Host Bridge — giving the agent access to iOS capabilities

**Status:** implemented — the bridge, the capability registry, `device_info`,
and Calendar/Reminders (read); Health and the settings UI still designed only · **Tracking PR:** this one · **Author:** @everettjf

DSH runs DeepSeek Harness inside an emulated Linux guest. The guest is a good
sandbox but a poor citizen of the device: it cannot read Apple Health, take a
photo, look at the clipboard, or share a file. This document proposes a small,
auditable bridge between the guest and the app so that iOS capabilities can be
exposed to the agent one at a time, as ordinary dsh tools.

The first capability is Apple Health (read-only), but the point of the design is
that every further capability is *one route in the app plus one tool in the
plugin*.

## 1. Why this shape

Two facts decide the design.

**The guest can already reach the app over loopback.** The emulator's sockets
are pass-through host sockets. We rely on the opposite direction today (the
WKWebView loads `http://127.0.0.1:3080`, served by the guest), and
`tests/rootfs-test.sh` proves the guest → host direction: the harness inside the
guest completes a full LLM round trip against a mock server running on the Mac.
So an HTTP listener inside the app is reachable from the guest with no new
plumbing, no FFI, and no changes to the emulator.

**dsh tools are plugins.** A dsh plugin is an ES module exporting
`name` / `inject` / `Config` / `apply(ctx, config)`, and a tool is registered with
`ctx.tools.register(defineTool({...}))` (see `@deepseek-ai/dsh-tool-todo` for the
canonical shape). Adding a capability therefore needs no fork of dsh — we mount
one extra plugin through the profile patch we already ship in
`rootfs/overlay/usr/local/share/dsh/cordis.patch.yml`.

```
┌─ DSH.app ─────────────────────────────────────────────────────────────┐
│  WKWebView ──────────────────────────────► http://127.0.0.1:3080 ──┐  │
│                                                                    │  │
│  DSHHostBridge (NWListener, 127.0.0.1:<random>)                    │  │
│    ├── GET  /v1/capabilities                                       │  │
│    ├── GET  /v1/device                                             │  │
│    ├── GET  /v1/health/steps?days=7      ← HealthKit               │  │
│    └── …one route per capability                                   │  │
│         ▲ Bearer <token>                                           │  │
│  ┌──────┴──────── iSH-ARM64 guest (Alpine + Node 22 + dsh) ────────▼┐ │
│  │  dsh-host-bridge plugin → tools: health_query, device_info, …    │ │
│  │  dsh web ────────────────────────────────────────────────────────┘ │
│  └──────────────────────────────────────────────────────────────────┘ │
└───────────────────────────────────────────────────────────────────────┘
```

## 2. Protocol

Plain HTTP/1.1 + JSON on `127.0.0.1`, port chosen at launch (same free-port
logic as `DSHPortAllocator`). Requests carry `Authorization: Bearer <token>`.

| | |
|---|---|
| Discovery | `GET /v1/capabilities` → `{ "capabilities": [{ "id": "health.read", "state": "granted\|denied\|prompt\|unavailable" }] }` |
| Call | `GET`/`POST /v1/<domain>/<action>`, JSON body/query in, JSON out |
| Errors | HTTP status + `{ "error": { "code": "permission_denied", "message": "…", "recoverable": true } }` |
| Codes | `unauthorized`, `permission_denied`, `unavailable` (capability absent on this OS/device), `invalid_request`, `internal` |

Two rules keep the model's experience sane:

- **Never hang.** Anything that needs a system prompt (HealthKit authorization,
  photo picker) returns `permission_denied` with `recoverable: true` and posts a
  request to the app's UI, rather than blocking the agent's turn for a minute.
  The tool tells the model to retry after the user approves.
- **Bounded results.** Every list route takes a `limit`, caps it server-side and
  reports `truncated: true`. Health data over months is easily megabytes; the
  model must not be handed all of it.

## 3. Security model

The threat model deserves care, because the thing calling this bridge is an LLM.

**What the token protects.** Any app on the device can connect to
`127.0.0.1:<port>`. The token (32 random bytes, new on every launch) is what
stops another app from port-scanning its way into the user's health data. It is
necessary and sufficient *for that threat*.

**What the token does not protect.** Inside the guest, the agent runs as root
and inherits the environment of `dsh-serve` — so an agent that wants to bypass
the tool layer can read `DSH_HOST_BRIDGE_TOKEN` and `curl` the bridge directly.
No secret placed inside the guest can prevent that. Therefore:

> **The real gate is on the app side, not in the guest.**

Concretely:

1. **Capabilities are off by default** and switched on by the user in DSH's
   settings (a new screen). A route whose capability is off returns
   `permission_denied` regardless of the token.
2. **Sensitive capabilities require a per-session (or per-call) confirmation in
   the app**, on top of the system permission dialog. The tool call shows up in
   the UI like any other; the confirmation is native and cannot be forged from
   inside the guest.
3. **Read-only first.** Anything that writes to the device or leaves it (send a
   message, post to a calendar, run a Shortcut) stays behind an explicit
   per-call confirmation, forever — never a "remember my choice".
4. **Everything is logged.** Each bridge call appends to `DSHLogBuffer` (visible
   in *Server Log*): timestamp, capability, arguments summary, decision. The
   user can see what the agent asked for.
5. **The bridge binds `127.0.0.1` only** and refuses requests with a `Host`
   header that is not loopback, so it can never be reached from the network.

Data minimisation: routes return aggregates where an aggregate answers the
question (e.g. daily step totals rather than every sample), and never return raw
identifiers (contact record ids, photo asset ids) unless the tool needs them.

## 4. Capability roadmap

Each row is "one route + one tool". The permission column is what has to be true
before it can ship — the current DSH signs with the team wildcard profile, which
carries **no** special entitlements, so anything in the "explicit App ID" column
forces a signing change (create an explicit App ID with that capability enabled;
none of these need Apple's approval, unlike e.g. Font Enumeration).

| Capability | Route | iOS API | Info.plist / entitlement | Explicit App ID? | Risk | Confirm |
|---|---|---|---|---|---|---|
| Device info ✅ | `/v1/device` | `UIDevice`, `NSProcessInfo` | — | no | low | no |
| Clipboard read | `/v1/clipboard` | `UIPasteboard` | — | no | medium | system paste banner |
| Clipboard write | `/v1/clipboard` (POST) | `UIPasteboard` | — | no | medium | per call |
| Battery / thermal | `/v1/device/power` | `UIDevice`, `NSProcessInfo` | — | no | low | no |
| Share sheet | `/v1/share` | `UIActivityViewController` | — | no | medium | user picks target |
| Notifications | `/v1/notify` | `UNUserNotificationCenter` | — | no | low | system prompt |
| **Health (read)** | `/v1/health/*` | HealthKit | `NSHealthShareUsageDescription` + `com.apple.developer.healthkit` | **yes** | high | system + app toggle |
| Location | `/v1/location` | CoreLocation | `NSLocationWhenInUseUsageDescription` | no | high | system prompt |
| Calendar (read) ✅ | `/v1/calendar/events` | EventKit | `NSCalendarsFullAccessUsageDescription` (+ pre-17 key) | no | high | switch + system |
| Reminders (read) ✅ | `/v1/reminders` | EventKit | `NSRemindersFullAccessUsageDescription` (+ pre-17 key) | no | high | switch + system |
| Reminders (write) | `/v1/reminders` (POST) | EventKit | as above | no | high | per call |
| Contacts | `/v1/contacts` | Contacts | `NSContactsUsageDescription` | no | high | system + app toggle |
| Photos (read/pick) | `/v1/photos/*` | PhotosUI picker | `NSPhotoLibraryUsageDescription` | no | high | user picks items |
| Camera / mic capture | `/v1/capture/*` | AVFoundation | `NSCameraUsageDescription`, `NSMicrophoneUsageDescription` | no | high | per call |
| Shortcuts | `/v1/shortcut/run` | `x-callback-url` / App Intents | — | no | high | per call |
| Files (import/export) | `/v1/files/*` | `UIDocumentPicker` | — | no | medium | user picks |
| Speech (TTS/STT) | `/v1/speech/*` | AVSpeechSynthesizer, Speech | `NSSpeechRecognitionUsageDescription` | no | medium | system prompt |

Health is deliberately *not* first in implementation order — it is the one that
forces a provisioning change, so it lands once the plumbing is proven.

### Tool surface

The plugin registers one tool per domain, not per route, so the model's tool
list stays small:

```
device_info(fields?)                  → model, OS, locale, battery, thermal state
clipboard(action: read|write, text?)  → the pasteboard
health_query(metric, days?, limit?)   → steps | heart_rate | sleep | workouts | …
location_query(accuracy?)             → one fix, or the last known one
calendar_query(range, limit?)         → events / reminders
photos_pick(count?)                   → user-picked images, written into the workspace
share(path|text)                      → opens the share sheet
notify(title, body)                   → local notification
```

Tools that produce files write them into `/root/workspace` inside the guest, so
the agent can then read them with the tools it already has.

## 5. Delivery plan

Phase-by-phase status, plus the work that is independent of this bridge, lives
in [roadmap.md](roadmap.md); the phases below give the design detail.

**Phase 0 — bridge skeleton (no new permissions).** ✅ *shipped in this PR*
`DSHHostBridge` (NWListener on loopback, token, routing, JSON, logging into
`DSHLogBuffer`), capability registry with per-capability on/off state persisted
in `NSUserDefaults`, `GET /v1/capabilities` + `GET /v1/device`. Guest side: the
`dsh-host-bridge` plugin package baked into the image under
`/usr/local/lib/dsh-plugins/`, mounted from `cordis.patch.yml`, exposing
`device_info`. Env (`DSH_HOST_BRIDGE_URL`, `DSH_HOST_BRIDGE_TOKEN`) injected via
the existing `DSHHarness.extraEnvironment`.
*Tests (all green, run locally — `make test` plus `make test-device-unit`):* `DSHHostBridgeTests` covers auth, the loopback `Host`
check, unknown routes, the body limit, capability gating and the
snapshot/schema contract; `DSHGuestIntegrationTests` calls the real bridge from
inside the guest on device (and asserts an unauthenticated guest process gets
401); `tests/rootfs-test.sh` runs a whole agent turn — mock LLM asks for
`device_info`, the plugin calls a stub bridge, the result reaches the model —
plus the wrong-token and no-bridge-environment cases.

What Phase 0 taught us, worth keeping in mind for later capabilities:

- **A response must not close the socket while the client is still sending.**
  Refusing an oversized body with 413 and closing immediately made the client
  see a connection reset instead of the answer — on device, not in the
  simulator. The bridge now half-closes and drains before closing.
- **An image update must not silently keep the previous image's configuration.**
  `DSHRootUpgrader` copies the whole harness home for the user's data, which
  also copied the old `cordis.patch.yml` — so a new plugin shipped with a new
  image never got mounted. Migration now restores the image's own patches, and
  `dsh-serve` re-installs them on every start so the state is self-healing.

- Tool registration must be **synchronous** inside `apply()`. Cordis tracks
  registrations as reversible effects of the plugin; an async registration both
  escapes that scope and misses the first request. Whether a capability is
  usable is therefore decided per call, by the app — which is also what lets the
  user flip a switch without restarting the harness.
- `output.schema` needs `additionalProperties: false` and `output.render` must
  return `ContentBlock[]`, not a string. A field the app adds without updating
  the plugin's schema fails every call; `testDeviceSnapshotMatchesThePluginSchema`
  is the tripwire.
- The plugin is mounted from the **home-level** patch
  (`~/.dsh/cordis.patch.yml`, written by `scripts/build-rootfs.sh`) so every
  profile gets it — `web` for the app, `headless` for the tests.

**Phase 1 — settings + confirmation UI.**
A capabilities screen in the app (list, toggles, "last used"), and the
confirmation flow for per-call capabilities (native alert, timeout →
`permission_denied`). Clipboard read/write and share sheet ship here — they need
no entitlement and exercise both the toggle and the per-call paths.

**Phase 2 — Health (read-only).**
Explicit App ID `com.xnuapp.dsh` with HealthKit enabled, `NSHealthShareUsageDescription`,
`HKHealthStore` queries for steps / heart rate / sleep / workouts, aggregated by
day, capped by `limit`. Signing docs updated in the README (the current wildcard
profile stops working for this target — that is the notable cost of this phase).
*Tests:* unit tests over the aggregation with injected samples; a device test
that asserts `unavailable`/`permission_denied` behaviour when authorization is
absent, so CI does not depend on real health data.

**Phase 3 — the long tail.**
Location, calendar, contacts, photos, notifications, Shortcuts, speech — each is
a route, a tool, a capability entry, a test, and a README line. They can land
independently and in any order.

## 6. Open questions

- **Per-call confirmation UX.** A modal per call is safe but hostile in a long
  agent turn. Proposal: per-session grant for read capabilities (with a visible
  badge in the DSH bar) and per-call for writes. Needs a decision before Phase 1.
- **Backgrounding.** iOS suspends the app; a bridge call from a background agent
  turn will fail. Should the bridge queue the request and resume on foreground,
  or fail fast with `unavailable`? Fail fast is proposed for now.
- **Guest-side transport.** HTTP is simple and already proven. A Unix socket
  shared through a bind mount would be marginally harder to reach from a stray
  guest process, but the emulator's `fakefs_bind_mount` path is less tested and
  the threat it addresses is already covered by app-side gating.
- **Naming.** `dsh-host-bridge` as the plugin/npm name, `/v1` for the routes.
