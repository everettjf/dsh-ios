# Host Bridge — giving the agent access to iOS capabilities

**Status:** implemented — the bridge, the capability registry, the Capabilities
settings screen, the per-call confirmation gate, and fifteen tools across
device/power, clipboard, calendar, reminders, health, location, contacts,
notifications, files and Shortcuts · **Tracking PR:** this one · **Author:** @everettjf

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
| Clipboard ❌ | — | `UIPasteboard` | — | no | medium | *not offered — see below* |
| Battery / thermal ✅ | `/v1/device/power` | `UIDevice`, `NSProcessInfo` | — | no | low | no |
| Share sheet | `/v1/share` | `UIActivityViewController` | — | no | medium | user picks target |
| Notifications ✅ | `/v1/notify` | `UNUserNotificationCenter` | — | no | low | switch + system, 10/hour |
| **Health (read)** ✅ | `/v1/health/*` | HealthKit | `NSHealthShareUsageDescription` + `com.apple.developer.healthkit` | **yes** | high | switch + system |
| Location ✅ | `/v1/location` | CoreLocation | `NSLocationWhenInUseUsageDescription` | no | high | switch + system |
| Calendar (read) ✅ | `/v1/calendar/events` | EventKit | `NSCalendarsFullAccessUsageDescription` (+ pre-17 key) | no | high | switch + system |
| Calendar (write) ✅ | `/v1/calendar/events` (POST) | EventKit | as above | no | high | per call |
| Reminders (read) ✅ | `/v1/reminders` | EventKit | `NSRemindersFullAccessUsageDescription` (+ pre-17 key) | no | high | switch + system |
| Reminders (write) ✅ | `/v1/reminders` (POST) | EventKit | as above | no | high | per call |
| Contacts ✅ | `/v1/contacts?q=` | Contacts | `NSContactsUsageDescription` | no | high | switch + system, search only |
| Photos (read/pick) | `/v1/photos/*` | PhotosUI picker | `NSPhotoLibraryUsageDescription` | no | high | user picks items |
| Camera / mic capture | `/v1/capture/*` | AVFoundation | `NSCameraUsageDescription`, `NSMicrophoneUsageDescription` | no | high | per call |
| Shortcuts ✅ | `/v1/shortcut/run` | `x-callback-url` | — | no | high | per call (and DSH is suspended) |
| Files (import) ✅ | `/v1/files/import` | `UIDocumentPicker` | — | no | medium | the picker is the consent |
| Files (export) ✅ | `/v1/files/export` | `UIDocumentPicker` | — | no | medium | per call, then the picker |
| Speech (TTS/STT) | `/v1/speech/*` | AVSpeechSynthesizer, Speech | `NSSpeechRecognitionUsageDescription` | no | medium | system prompt |

Health is deliberately *not* first in implementation order — it is the one that
forces a provisioning change, so it lands once the plumbing is proven.

### Tool surface

One tool per thing the agent can *do*, which is not the same as one per route —
`health_query` covers four routes behind a `metric`, while the clipboard's read
and write are separate tools because they are separately gated:

```
device_info()                              → model, OS, locale, battery, thermal state
device_power()                             → battery, heat, and shouldDeferExpensiveWork
calendar_query(days?, limit?)              → events
calendar_create_event(title, start, …)     → one event
reminders_query(completed?, limit?)        → reminders
reminders_create(title, due?, notes?)      → one reminder
health_query(metric, days?, limit?)        → activity | heart_rate | sleep | workouts
location_query()                           → one fix, with its accuracy
contacts_search(query, limit?)             → matching people (search only, never a dump)
notify(title, body?)                       → local notification, 10 an hour
file_import() / file_export(name, base64)  → through the iOS document picker
shortcut_run(name, input?)                 → runs one of the user's shortcuts
```

Files cross the bridge as base64 in the JSON body and the guest writes them
into `/root/workspace` itself, so the app never reaches into the emulator's
fakefs.

### dsh's own approval does not cover these tools

Worth stating plainly, because it is load-bearing and not obvious: the image
ships `defaultPreset: guest-ask`, so dsh asks the user before risky tool calls
— and that has nothing to do with the bridge's capabilities.

dsh runs every tool through a `tools/pre-execute` waterfall whose default is
`{kind: "allow"}`; it only prompts when some plugin returns `{kind: "ask"}`.
The packages that do are `dsh-sandbox`, `dsh-tool-bash`, `dsh-tool-fs` and
`dsh-pwsh-sandbox` — the sandboxed execution tools. A plugin tool like
`reminders_create` matches none of them, so dsh allows it silently.

Two consequences:

1. **`DSHCallConfirmation` is the only gate on a write.** Remove it and the
   agent creates calendar events, runs shortcuts and saves files out of DSH
   with nothing asked, in a build whose settings screen says otherwise.
2. **There is no double prompt.** A user does not confirm the same action twice
   — dsh's approval covers what happens *inside* the guest, the app's covers
   what leaves it.

And even if dsh's approval did cover these, it could not replace this one: its
configuration lives in the guest filesystem, where the agent runs as root and
can rewrite it. A gate the agent can switch off is not a gate. That is the same
reason the bridge's token is described as keeping *other apps* out rather than
the agent.

### The record

A switch the user cannot audit is a promise, not a control. Every capability
call and every confirmation was being logged from the start — into the same
buffer as the guest's stdout, where nobody would ever find it. `DSHActivityLog`
is the version that can be read: one timeline, persisted across launches,
covering both sides of the boundary.

The guest half is the part that needed a new idea. The app can see every bridge
call by construction, but not what the agent does *inside* the guest — the bash
it runs, the files it edits, the searches it makes — and that is most of what an
agent actually does. dsh publishes each of those as a session event, so the
bridge plugin subscribes to `session/event` (globally), matches `tool/call` to
`tool/result` by id, and posts batches to `POST /v1/activity`. That route is
deliberately *not* a capability: it carries nothing off the device, and a
switch that could silently make the record incomplete would be worse than no
record.

**What is recorded is asymmetric on purpose.** Names, times, durations and
outcomes always. Arguments only as a one-line summary — the shell command,
the path, the query — because that is what distinguishes two calls. The
*contents* a read returned, never: `contacts_search → 3 contacts`, not the
names. A log of the user's address book would be a worse leak than the
capability it is supposed to make auditable.

Three things consume it, and they are the reason it is worth having rather than
just correct:

- **"Last used" on each switch**, which turns a claim into a checkable fact.
- **An indicator in the DSH bar** when a capability has just been used, tapping
  through to the record. It copies iOS's own privacy indicator on purpose:
  users already know what a light that means "something was just used" is for.
- **Repeat context in confirmations.** A single prompt in a runaway loop looks
  exactly like a single prompt; from the fourth call in ten minutes the alert
  says which one it is. This is the only moment a user gets to notice an agent
  that has gone wrong, and one dialog on its own cannot show it.

### The bridge was not the only way out

iSH registers character devices for the pasteboard and for CoreLocation in its
app delegate and mknods them world-readable at boot. DSH links that code, so
for the whole of this work any process in the guest could have run
`cat /dev/clipboard` and read the user's clipboard with no switch, no
confirmation, and no line in the log — bypassing the entire capability system,
for two of the capabilities it exists to protect. `/dev/location` was the same.

DSH no longer registers either device. Skipping the registration turned out not
to be enough: `mknod` writes a real node into the guest's filesystem, which
survives every later boot, so any install that had ever run an earlier build
kept its backdoor. The nodes are unlinked at boot as well, and
`DSHCapabilityReportTests.testISHDeviceNodesDoNotBypassTheBridge` asserts they
are gone — it failed on the first attempt, which is how the difference between
"not created" and "not there" was found.

The lesson generalises past these two devices: the capability system only means
what it says as long as nothing *else* in the app hands the guest a way around
it, and this app is built on someone else's emulator that was designed to be
generous with exactly these things. Anything added to the vendored iSH sources
needs reading with that question in mind.

### What only a real device with real data showed

Every capability had contract tests passing on both the simulator and the iPad
before any of it had touched real data. Two bugs survived all of them, and both
are worth remembering when adding the next capability:

- **Contacts 500'd on the first real match.** `CNContactFormatter` requires its
  own key descriptor, and asking it to format a contact fetched without those
  keys raises rather than returning nil. Searches that matched *nobody* — which
  is every search on a test device — never reached the formatter, so the bug sat
  behind a green suite. The regression test now asserts the descriptor is in
  `keysToFetch`, because "search returns something" cannot be tested portably.
- **The clipboard read hung the handler.** It called `UIPasteboard` with
  `dispatch_sync` to the main queue while iOS was waiting for the user to
  confirm a cross-app paste, so the call blocked until the caller gave up. This
  is the same lesson as the confirmation gate, arriving from a direction nobody
  was watching: *anything that can end up behind a system dialog needs a bounded
  wait*, not just the dialogs we raise ourselves.

The general shape: contract tests prove a capability refuses correctly, which is
most of the safety surface but none of the "does it work" surface. A report that
prints what each route actually returned on a real device — counts and shapes,
never values — is what closes that gap, and
`DSHCapabilityReportTests` exists for exactly that.

### Two capabilities cost more than a route each

**Shortcuts leaves.** `shortcuts://x-callback-url/run-shortcut` opens the
Shortcuts app, which backgrounds DSH, which suspends the emulator — so the
agent's turn stops mid-call and there is no result to read. The route returns
`started: true` with a note saying exactly that, rather than a success the
model would reasonably read as "it ran and here is the outcome". Getting a
result back needs a custom URL scheme *and* a way to resume a suspended turn;
the second half is the same problem as backgrounding generally, so it is parked
with it. The shortcut name is percent-encoded with `&`, `=`, `+`, `?` and `#`
removed from the allowed set, so a name cannot smuggle in extra x-callback
parameters — there is a test for that specifically.

**There is no clipboard capability.** Reading was built and removed first: iOS
confirms *every* programmatic read of a pasteboard that came from another app,
and no API avoids it (`detectPatterns` reports that text exists, not what it
is), so the capability's real behaviour was to interrupt the user each time the
agent looked. Writing survived that round — it raises no system prompt — and
was then removed too, on the same judgement applied to the whole domain rather
than to one direction of it: the clipboard is a small convenience next to
"the agent can silently replace what you are about to paste", and the tool it
justified was not worth that sentence being true.

The read left something behind that outlived it: it blocked the bridge handler
on `dispatch_sync` to the main queue, so while iOS waited for a tap the whole
call hung until the caller gave up. Bounded waits are now the rule for anything
that can sit behind a system dialog — that lesson is the durable part.

**Files never touch the fakefs.** The app does not write into the guest's
filesystem; contents cross the bridge base64-encoded in the JSON body and the
guest writes them itself with `fs`. That keeps the emulator's internals out of
the app, at the price of a real 8 MB ceiling — it is JSON held in memory on
both sides.

### Health is the one capability that cannot report its own permission

Every other framework here will tell the app whether access was granted.
HealthKit deliberately will not: revealing that the user declined *heart rate*
but allowed *steps* would itself leak health information. `authorizationStatus`
answers only for **write** access, and a read query on a declined type returns
an empty result — indistinguishable from a genuinely empty week.

Two consequences, both load-bearing:

0. Switching the capability on in **⋯ ▸ Capabilities** triggers the HealthKit
   sheet immediately (`DSHCapability.requestSystemPermission`), so the user
   answers it while they are looking at the screen instead of discovering the
   permission through the agent's first failed call. The same hook backs
   Calendar and Reminders.
1. The only signal the app can act on is
   `getRequestStatusForAuthorizationToShareTypes:readTypes:`, which says whether
   the sheet still has to be shown. `shouldRequest` triggers the sheet and
   answers `permission_denied` / `recoverable`; anything else means "asked
   already", so the query runs and the result speaks for itself.
2. Every empty answer carries a `note` saying that an empty window may equally
   mean the user declined that category, and the tool description tells the
   model to relay it rather than conclude the user never sleeps. Without this
   the failure mode is a confident model telling someone they took zero steps
   this month.

All read types are requested in a single sheet, so the user makes one decision
with a full view of what is being asked for.

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

- **Per-call confirmation UX.** *Settled:* reads are gated by the switch plus
  the framework's own dialog; everything that writes asks every time, and the
  alert names the concrete effect ("Add this reminder? “buy milk”, due Friday,
  in Home") rather than the capability. No session grants — they were the part
  that could not be explained to a user in one line. `DSHCallConfirmation`
  enforces the three rules that make blocking a bridge handler on a dialog
  safe: never wait on a dialog nobody can see (background → refuse), never
  stack them (a second prompt while one is up → refuse), and always answer
  (timeout → refuse, recoverably).
- **Backgrounding.** iOS suspends the app; a bridge call from a background agent
  turn will fail. Should the bridge queue the request and resume on foreground,
  or fail fast with `unavailable`? Fail fast is proposed for now.
- **Guest-side transport.** HTTP is simple and already proven. A Unix socket
  shared through a bind mount would be marginally harder to reach from a stray
  guest process, but the emulator's `fakefs_bind_mount` path is less tested and
  the threat it addresses is already covered by app-side gating.
- **Naming.** `dsh-host-bridge` as the plugin/npm name, `/v1` for the routes.
