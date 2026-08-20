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
| Per-call confirmation for everything that writes | done |
| Clipboard write, power, location, contacts, notifications, files, Shortcuts | done |
| Calendar and Reminders: creating, not just reading | done |
| Emulator fixes: NEON conversions, FMOV immediates, `waitpid`, streaming `fetch()` | done |
| Tests: emulator 3, rootfs 32, app 80 (device + simulator), UI 5 | done |
| Distribution: build-it-yourself only | open |

Everything runs locally; there is no hosted CI (see [README](../README.md#tests)).

## Done: the write gate, and nine more capabilities

`DSHCallConfirmation` is the gate everything that changes something now sits
behind. Three rules make blocking a bridge handler on a dialog safe, and each
one is a test:

- **Never wait on a dialog nobody can see.** A call arriving while DSH is in
  the background is refused immediately (`unavailable`, recoverable) rather
  than queueing an alert the user will meet later, out of context.
- **Never stack them.** While one confirmation is up, further ones are refused
  rather than queued, so an agent in a loop cannot build a wall of dialogs.
- **Always answer.** A prompt nobody answers times out and refuses
  recoverably, so the turn ends with an explanation instead of hanging.

The alert names the effect, not the capability — "Add this reminder? “buy
milk”, due Friday, in Home" — and validation happens *before* it, so a
malformed call never costs the user a tap. Session grants were dropped: they
could not be explained in one line, which is a bad sign for a consent
mechanism.

On top of it: clipboard write, battery and thermal, location (single fix, never
tracking), contacts (search only — there is deliberately no route that returns
the address book), notifications (10 an hour), file import/export through the
document picker, Shortcuts, and creating calendar events and reminders.

Clipboard *read* was built and then removed: iOS confirms every programmatic
read of a pasteboard that came from another app, so it interrupted the user on
every use. Ten minutes with it on a device settled it.

Two of these carry a caveat worth repeating in any docs that describe them:

- **Shortcuts suspends the agent.** Opening the Shortcuts app backgrounds DSH,
  which suspends the emulator, so the turn stops and there is no result to
  read. The route says so in its own answer rather than reporting a clean
  success. Getting a result back would need a custom URL scheme *and* a way to
  resume a suspended turn — the second half is the hard part and belongs with
  the backgrounding work below.
- **Files never touch the fakefs.** Contents cross the bridge base64-encoded
  and the guest writes them itself, which keeps the emulator's filesystem out
  of the app entirely. The 8 MB ceiling is real: it is JSON in memory.

## Next

1. **Photos and the share sheet** — the last two entries in the capability
   matrix that need no new mechanism. Photos goes through `PHPickerViewController`,
   where the picker is the consent (like file import); the share sheet is a
   per-call write.
2. **A record of what the agent did.** Every confirmation and every capability
   call is already logged to the server log, but it is mixed in with the
   guest's own output. A dedicated view — what was asked, when, allowed or
   refused — is the thing that makes the switches trustworthy over time, and it
   is more useful than the next capability.
3. **Revisit the read gates.** Nine capabilities in, the pattern "switch plus
   system permission, refuse recoverably" has held up. What has not been tested
   is what happens when a user turns something *off* mid-turn — the registry is
   consulted per call, so it should be immediate, but there is no test that a
   revocation lands between two calls of the same turn.

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
