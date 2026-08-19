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
| Tests: emulator 3, rootfs 22, app 51 (device + simulator), UI 5 | done |
| Distribution: build-it-yourself only | open |

Everything runs locally; there is no hosted CI (see [README](../README.md#tests)).

## Next: writing, which needs a different kind of consent

Everything shipped so far only *reads*, and two gates cover that: the user's
switch, plus iOS's own permission where the framework has one. Neither is
enough for a call that changes something — a switch flipped last Tuesday is not
consent to put a particular string on the clipboard today, and iOS has no
dialog to lend us for actions inside our own app. `DSHCapabilityGatePerCall`
exists in the registry with nothing behind it; that is the next thing to build.

**1. Settle per-call vs per-session** ([host-bridge.md §6](host-bridge.md#6-open-questions)).
A modal on every call is safe and unusable in a long agent turn; a blanket
session grant is usable and too broad. The proposal to implement: reads keep
today's switch-plus-system-permission model, writes ask every time, and the
alert names the concrete effect ("Put 240 characters on the clipboard?", "Create
reminder “buy milk”, due Friday?") rather than the capability. No session grants
for writes until something proves they are needed.

**2. Build the gate.** `DSHHostBridge` already refuses `Disabled` and
`Unavailable` before the handler runs; per-call slots in beside that: present on
the main queue, wait with a timeout, and on refusal *or* timeout answer
`permission_denied` with `recoverable: true` so the model explains instead of
hanging. Two things that will bite: the app may be in the background when the
call arrives (fail fast with `unavailable`, do not queue a dialog nobody can
see), and a burst of calls must not stack alerts — coalesce or refuse the
extras.

**3. First writers, in this order.**
- **Clipboard** (`GET`/`POST /v1/clipboard`, `UIPasteboard`). Read first: it is
  the smaller change and iOS already shows its own paste banner. Write next —
  the first thing that touches state outside the app.
- **Reminders write** (`POST /v1/reminders`, EventKit). The capability, the
  permission and the read route all exist, so this is purely the write path and
  the confirmation copy.

Neither needs an entitlement, so this stays inside the current signing setup.

**4. Tests.** A per-call route refused on timeout and on decline; a burst that
does not stack alerts; a backgrounded call that fails fast; guest-side round
trips for both writers in `tests/rootfs-test.sh`; an XCUITest that accepts one
confirmation and declines the next. The existing switch XCUITest
(`testCapabilitiesScreenTogglesACapability`) stays as-is.

**What this does not include.** The read capabilities in the matrix that need no
new mechanism — location, notifications, contacts, photos, files, speech — are
deliberately parked until the write gate exists, because each one added now is
another thing to retrofit onto it later. `share` and `shortcut/run` are writes
in disguise and belong after step 3, not beside it.

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
- **Verified on an iPad Air (M3)** with real data — activity and heart rate
  returned daily rows, workouts returned sessions, and sleep came back empty
  *with* its note, which is exactly the case the note exists for.
  `testReportHealthAuthorizationState` prints these shapes (counts only, never
  values) on every run, so a green suite can no longer hide the fact that the
  data tests skip themselves when HealthKit is unavailable.

## Then: the long tail

Once the write gate exists, each remaining capability is a route, a tool, a
capability entry, tests and a README line; they can land independently and in
any order. The permission column of the
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
