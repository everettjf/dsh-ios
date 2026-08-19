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
| Emulator fixes: NEON conversions, FMOV immediates, `waitpid`, streaming `fetch()` | done |
| Tests: emulator 3, rootfs 16, app 32 (device + simulator), UI 4 | done |
| Distribution: build-it-yourself only | open |

Everything runs locally; there is no hosted CI (see [README](../README.md#tests)).

## Next: host bridge Phase 1 — settings and confirmation

The bridge can already refuse a call because a capability is off, but nothing
in the UI can turn one on, and nothing asks the user before a sensitive call.
That is the whole of Phase 1.

1. **Capabilities screen.** A list from `DSHCapabilityRegistry`: title, one-line
   description, state, a switch, and when it was last used. Reachable from the
   `⋯` menu. Writes through `setEnabled:forIdentifier:`, which the bridge
   already honours per call, so no restart is needed.
2. **Per-call confirmation.** For `DSHCapabilityGatePerCall`, the handler posts
   a native alert (what is being asked, by which capability) and waits with a
   timeout; on timeout or refusal the route answers `permission_denied` with
   `recoverable: true` so the model can explain rather than hang. The open
   question in [host-bridge.md §6](host-bridge.md#6-open-questions) — per-call
   vs per-session grants — has to be settled here; the current proposal is
   per-session for reads, per-call for writes, with a badge in the DSH bar while
   a session grant is live.
3. **First users of both paths:** Calendar and Reminders are already in and
   need the screen to be switchable at all (they ship off, and today the only
   way to turn them on is a debugger or a test); clipboard (`GET`/`POST
   /v1/clipboard`) and creating a reminder (`POST /v1/reminders`) exercise the
   per-call confirmation. None of these needs an entitlement, so Phase 1 stays
   inside the current signing setup.
4. **Tests.** Registry persistence; a route gated per-call that is refused on
   timeout; XCUITest that flips a switch and sees the tool start failing;
   guest-side round trip for clipboard through `tests/rootfs-test.sh`.

## Then: Phase 2 — Apple Health (read-only)

The motivating capability, and the only one that changes how the app is signed.

- **Signing.** `com.apple.developer.healthkit` is not in the team wildcard
  profile DSH uses today, so this needs an explicit App ID for
  `com.xnuapp.dsh` with HealthKit enabled, plus
  `NSHealthShareUsageDescription`. No Apple approval is required (unlike Font
  Enumeration), but every contributor building the app will need their own
  explicit App ID from that point on — the README has to say so.
- **Routes.** `GET /v1/health/steps|heart_rate|sleep|workouts`, each taking
  `days` and `limit`, aggregated per day rather than per sample, capped
  server-side with `truncated: true` when the cap bites.
- **Authorization.** HealthKit's own dialog is one gate, the capability switch
  is the other. An unauthorized read answers `permission_denied` with
  `recoverable: true` instead of blocking the turn.
- **Tests.** Aggregation unit-tested with injected samples; a device test that
  asserts the `unavailable`/`permission_denied` behaviour so the suite never
  depends on real health data being present.

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
