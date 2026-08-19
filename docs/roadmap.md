# Roadmap

What is built, what is next, and what each remaining piece actually costs.
The host bridge has its own design document — [host-bridge.md](host-bridge.md) —
which this plan references rather than repeats.

## Where things stand

| Area | State |
|---|---|
| Guest: Alpine 3.21 + Node 22 + dsh 0.1, reproducible image | done |
| App: WKWebView front end, supervised `dsh web`, terminal, server log | done |
| Background boot with progress + ETA (launch watchdog safe) | done |
| Guest image auto-upgrade with user-data migration | done |
| Host bridge: listener, token, capability registry, `device_info` | done |
| Calendar and Reminders (read) over EventKit, off by default | done |
| Apple Health (read): activity, heart rate, sleep, workouts | done |
| Capabilities screen (⋯ ▸ Capabilities) with per-capability switches | done |
| Emulator fixes: NEON conversions, FMOV immediates, `waitpid`, streaming `fetch()` | done |
| Tests: emulator 3, rootfs 24, app 42 (device + simulator), UI 5 | done |
| Distribution: build-it-yourself only | open |

Everything runs locally; there is no hosted CI (see [README](../README.md#tests)).

## Next: per-call confirmation and the first write capability

The Capabilities screen shipped, so switches exist and take effect on the
agent's next tool call. What is still missing is the other half of Phase 1: a
gate for calls that *change* something, and the first capability that needs it.

1. **Per-call confirmation.** For `DSHCapabilityGatePerCall`, the handler posts
   a native alert (what is being asked, by which capability) and waits with a
   timeout; on timeout or refusal the route answers `permission_denied` with
   `recoverable: true` so the model can explain rather than hang. The open
   question in [host-bridge.md §6](host-bridge.md#6-open-questions) — per-call
   vs per-session grants — has to be settled here; the current proposal is
   per-session for reads, per-call for writes, with a badge in the DSH bar while
   a session grant is live.
2. **First users of it:** clipboard (`GET`/`POST /v1/clipboard`) and creating a
   reminder (`POST /v1/reminders`). Neither needs an entitlement, so this stays
   inside the current signing setup.
3. **Tests.** A route gated per-call that is refused on timeout; guest-side
   round trip for clipboard through `tests/rootfs-test.sh`. The XCUITest that
   flips a switch already exists (`testCapabilitiesScreenTogglesHealth`).

## Done: Apple Health (read-only)

Shipped as `health.read` with `GET /v1/health/activity|heart_rate|sleep|workouts`
and a single `health_query` tool. Two notes for anyone building on it:

- **Signing changed.** `com.apple.developer.healthkit` is not in the team
  wildcard profile, so the app now needs an *explicit* App ID for its bundle id
  with HealthKit enabled. Xcode's automatic signing creates one on the first
  build after the capability is added; contributors building the app under their
  own team will each need this — see the README's build section.
- **Read permission is invisible by design** (details in
  [host-bridge.md §4](host-bridge.md#health-is-the-one-capability-that-cannot-report-its-own-permission));
  every empty answer therefore carries a `note`, and the tests assert it.

## Then: Phase 3 — the long tail

Each is a route, a tool, a capability entry, tests and a README line; they can
land independently and in any order. The permission column of the
[capability matrix](host-bridge.md#4-capability-roadmap) is the source of truth
for what each one costs: location, calendar/reminders, contacts, photos,
camera/mic, Shortcuts, files, speech, notifications, battery/thermal detail.

## Independent of the bridge

- **Distribution.** Today the only way in is building from source. TestFlight
  would need a paid Apple Developer account and a review pass; the GPL and the
  App Store's terms are in tension (see [LICENSE.md](../LICENSE.md) and iSH's
  `LICENSE.IOS`), which is why iSH itself ships the way it does. Worth deciding
  deliberately rather than drifting into it.
- **Startup time.** ~25 s from launch to a usable harness, dominated by Node's
  jitless start inside the emulator. Worth measuring where it actually goes
  (module compilation vs plugin tree) before optimising; a smaller default
  plugin set for the first paint is the obvious lever.
- **Background behaviour.** iOS suspends the app, so a long agent turn stops
  when the user leaves. The harness resumes cleanly, but a turn does not. Some
  of this can be softened (a short background task for an in-flight step), and
  the rest should be explained in the UI rather than hidden.
- **Upstreaming the emulator fixes.** The NEON conversion gadgets, the
  FMOV-immediate decoding fix, the `waitpid` EINTR fix and the `lld` probe are
  all self-contained and useful to iSH-ARM64 generally — see
  [`ish-arm64/UPSTREAM.md`](../ish-arm64/UPSTREAM.md) for the vendored base.
- **Guest image size.** 95 MB compressed, mostly `node_modules`. Pruning dev-only
  files and unused optional dependencies would shrink both the app download and
  the first-launch import.
