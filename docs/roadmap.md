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
| Calendar and Reminders (read) over EventKit | done |
| Apple Health (read): activity, heart rate, sleep, workouts | done |
| Capabilities screen (⋯ ▸ Capabilities) with per-capability switches | done |
| Per-call confirmation for everything that writes | done |
| Power, location, contacts, notifications, files, Shortcuts | done |
| iSH's own `/dev/clipboard` and `/dev/location` removed (they bypassed everything) | done |
| Activity record: every capability call and every guest tool call, with a viewer | done |
| Calendar and Reminders: creating, not just reading | done |
| Emulator fixes: NEON conversions, FMOV immediates, `waitpid`, streaming `fetch()` | done |
| Tests: emulator 3, rootfs 31, app 93 (device + simulator), UI 6 | done |
| Capabilities ship on; the switch turns them off | done |
| One-command release: bump, test, archive, upload (`scripts/release.sh`) | done |
| Distribution: TestFlight (internal) and build-it-yourself | partly open |

Everything runs locally; there is no hosted CI (see [README](../README.md#tests)).

## What to do next, and why in this order

The bridge went from one read-only capability to nineteen routes, including
ones that write to the user's calendar and run arbitrary Shortcuts, and those
capabilities now ship on. That changes which problems matter, and it sharpens
the first and third items in particular: a gate nobody has audited matters more
when it is the only thing left in the way, and attacker-influenceable content
reaches a live capability set rather than one the user had to go and enable.
The ordering below is an argument, not a backlog: each item says why it comes
before the one after it.

### 1. Audit the rest of the emulator's surface

**Why first:** the whole value proposition of the capability system is the
sentence "the app decides, per capability, and nothing reaches iOS without
passing it." That sentence was false for the entire time it was being written
— iSH's `/dev/clipboard` and `/dev/location` sat there, world-readable, doing
exactly what the gates existed to prevent. It was not found by review; it
surfaced because a paste prompt appeared at launch and the explanation did not
add up.

Two devices were found by accident. Nobody has looked for the rest. Until
somebody does, every security claim in the README is an assumption, and every
capability added on top inherits it.

**What it is:** a read of `ish-arm64/app/` and `ish-arm64/fs/` asking one
question — what does this hand the guest that the capability registry does not
know about? Known places to start: `iosfs` (it mounts filesystems named in
`NSUserDefaults`, which is a lot of authority in a settings key),
`IOSCalls.m`/`LinuxInterop.h` (a direct guest → Objective-C call surface),
`Pasteboard`/`Location` device code now that the nodes are gone, and whatever
`dyn_dev_register` is used for elsewhere.

**Cost:** a day of reading, plus tests for anything found. Cheap relative to
being wrong.

### 2. A record of what the agent actually did — *done*

Shipped as `DSHActivityLog`, the Activity screen, and `POST /v1/activity` for
the guest's own tool calls; the design and the recording policy are in
[host-bridge.md §4](host-bridge.md#the-record). The question that was open —
whether arguments get recorded — settled as: effects for writes (the user
already saw them in the confirmation), one-line summaries of arguments for
everything else, and never the contents a read returned.

Three consumers landed with it: "last used" under each switch, an indicator in
the DSH bar copying iOS's privacy light, and repeat context in confirmations
("this is the fifth time in ten minutes") — the last being the only moment a
user gets to notice an agent in a loop.

Two things it does *not* do yet, both deliberately deferred: grouping a
timeline by turn, and using it for injection forensics (what did the agent read
just before it did that). Both want the threat model below to exist first.

### 3. Write down the prompt-injection threat model — and check the copy against it

**Why third:** the capability set crossed a line and the docs have not caught
up. The agent now *reads* attacker-influenceable content (calendar invites from
strangers, contact notes, imported files) and *writes* to the device (events,
reminders, clipboard, Shortcuts). Those two halves in one loop is the classic
injection setup: text inside a calendar event can try to steer the model into
`shortcut_run`.

The confirmation gate is the mitigation and it is a good one — every write is
shown to a human in concrete terms before it happens. But that only holds if
the alert text is *not* attacker-controlled enough to mislead. A shortcut named
"Allow — routine sync" would render as `Run a shortcut? DSH wants to run your
shortcut "Allow — routine sync"`. That is worth looking at hard.

**What it is:** a threat-model section in
[host-bridge.md](host-bridge.md), and a pass over every confirmation string
asking "if this value were chosen by an attacker, does the alert still tell the
truth?" Likely outcomes: quote and length-clamp interpolated values, keep
attacker-controlled text visually distinct from DSH's own words, and never let
it occupy the title.

**Cost:** small in code, and it is the kind of thing that is very expensive to
add after somebody is hurt by it.

### 4. Backgrounding, or: make a turn survivable

**Why fourth:** it is the largest usability ceiling, but it is genuinely hard,
and the three items above are cheap and make it easier. iOS suspends the app,
so a long agent turn dies when the user switches away — and the bridge made
this worse in one specific way: `shortcut_run` *necessarily* backgrounds DSH,
so that capability can never complete a turn today.

**The honest options, in ascending order of ambition:**

- *Explain it.* A line in the UI when a turn is running: leaving DSH stops it.
  Cheap, and better than a mysterious hang. Should happen regardless.
- *Buy 30 seconds.* `beginBackgroundTaskWithExpirationHandler:` covers a
  step that is already in flight. Helps a tool call that started before the
  user left; does not help a long turn.
- *Make turns resumable.* The real answer, and the expensive one: the harness
  keeps enough state that an interrupted turn can be picked up when the app
  returns, rather than being lost. This is mostly a dsh-side question, not an
  iOS one, and worth raising upstream before building anything bespoke.

Anything that pretends the app keeps running in the background (silent audio
and friends) is off the table: it drains the battery, and it is the kind of
trick that gets an app removed rather than shipped.

### 5. Photos and the share sheet

**Why fifth:** they are the last two entries in the capability matrix that need
no new mechanism — `PHPickerViewController` where the picker is the consent
(like file import), and a per-call write for the share sheet. Mechanical, and
therefore the right thing to do *after* the structural work above, not instead
of it.

### 6. Distribution

**Where it stands now:** builds upload. `scripts/release.sh` bumps the version,
runs every suite, archives, validates and uploads to App Store Connect, so
internal TestFlight works and 1.0.2 is there. That settles the mechanics and
leaves the two real questions untouched.

*External testers* need Beta App Review — the first time a reviewer looks at a
Linux emulator that runs arbitrary code. Worth finding out early and cheaply,
because the answer shapes everything after it.

*The App Store itself* is unresolved for a reason that is not technical: the
app is GPL-3.0 because iSH is, and the GPL sits badly with the App Store's
terms, which is why iSH ships the way it does. The realistic options remain
building from source, AltStore-style sideloading, or taking the licence
question seriously. Worth deciding deliberately rather than drifting.

### Later, but worth writing down: run the model on the device

iOS 26 added `FoundationModels.framework`, an on-device LLM, and it is present
in the SDK this app already builds against. dsh speaks an OpenAI-compatible
protocol, and the bridge is already an HTTP server — so this is one more route,
`POST /v1/chat/completions`, backed by the system model, with
`DEEPSEEK_BASE_URL` pointed at it. No API key, no network, and nothing leaves
the device.

That last part is the real argument. The uncomfortable shape of the app right
now is that a user switches on Health, Calendar and Contacts, and that data is
then sent to a remote model to be reasoned about. An on-device model makes
"an agent on your phone, reading your phone" coherent rather than ironic.

The honest caveats: the system model is small, its tool-calling is likely to be
much weaker than DeepSeek's, and the work is not trivial (SSE translation, tool
call format mapping). The way to find out is a half-day prototype that gets one
turn through end to end, then a decision — not a commitment up front.

### Not on this list, deliberately

- **More capabilities.** The matrix has plenty left, and each is now a
  well-worn path: a route, a tool, a capability entry, tests, a README line.
  That is exactly why they should wait — the value of the next capability is
  small next to the value of knowing the ones already shipped are contained.
- **CI.** Dropped earlier on purpose; everything runs locally.

## Smaller things, worth doing when they get in the way

- **Startup time**, ~25 s to a usable harness, dominated by Node's jitless
  start inside the emulator. Measure where it actually goes (module compilation
  vs plugin tree) before optimising; a smaller default plugin set for first
  paint is the obvious lever.
- **Guest image size**, 95 MB compressed, mostly `node_modules`. Pruning
  dev-only files would shrink both the download and the first-launch import.
- **Upstream the emulator fixes.** The NEON conversion gadgets, the
  FMOV-immediate decoding fix, the `waitpid` EINTR fix and the `lld` probe are
  self-contained and useful to iSH-ARM64 generally — see
  [`ish-arm64/UPSTREAM.md`](../ish-arm64/UPSTREAM.md).

## Decisions already made, and why

Kept here so they are not relitigated by accident.

**Per-call confirmation for writes; no session grants.** Session grants were
proposed and dropped: they could not be explained to a user in one line, which
is a bad sign for a consent mechanism. Reads are gated by the switch plus the
framework's own permission; writes ask every time, and the alert names the
effect rather than the capability.

**Three rules make blocking a bridge handler on a dialog safe.** Never wait on
a dialog nobody can see (background → refuse). Never stack them (a second
prompt while one is up → refuse). Always answer (timeout → refuse,
recoverably). Each is a test.

**No clipboard at all.** Reading was built, tried on a device and removed: iOS
confirms every programmatic read of a pasteboard that came from another app and
no API avoids it, so the capability's real behaviour was to interrupt the user
on every use. Writing raises no system prompt and was kept for a while, then
dropped too — the question changed from "which direction" to "is this domain
worth it", and "the agent can silently replace what you are about to paste" is
not worth the convenience.

**Capabilities ship on; the switch turns them off.** They shipped off at first,
which mostly meant a hunt through settings before anything worked. The switch
was never what stood between the agent and the data: a read still waits on
iOS's own permission dialog, a write still asks every single time. What the
switch is for is taking a capability away entirely, and that is one tap. The
consequence is that anything shipping on must have a real gate underneath it —
a test asserts exactly that, and it caught `files.import` sitting behind nothing
else until its own document picker was recognised as the gate.

**Contacts is search-only.** There is deliberately no route that returns the
address book. The agent has to name who it wants.

**Health answers explain their own emptiness.** iOS will not say whether a
*read* was denied, so "no data" and "declined" are indistinguishable. Every
empty answer carries a note saying so, and the tool is told to relay it.

**Files never touch the fakefs.** Contents cross the bridge base64-encoded and
the guest writes them itself. Costs a real 8 MB ceiling; keeps the emulator's
filesystem out of the app.

**Anything a capability does on the main thread has to survive being called
from it.** Capability code is reached two ways — a bridge handler on a
background queue, and a settings switch on the main thread — and a bare
`dispatch_sync` to the main queue deadlocks the second caller. Turning on
Location did exactly that: the main thread waited on itself and the watchdog
killed the app a few seconds later, which reads as a crash and leaves no crash
report. `DSHRunOnMainSync` runs inline when it is already on the main thread and
is now the only way capability code hops to it. The clipboard read that was
removed earlier had the same shape, which is the argument for fixing the class
rather than the instance.

**Contract tests are not enough.** They prove a capability refuses correctly,
which is most of the safety surface and none of the does-it-work surface. Two
bugs — Contacts raising on the first real match, the clipboard read hanging the
handler — survived every one of them and fell out of a single run against real
data on a real device. `DSHCapabilityReportTests` exists to close that gap and
prints what each route actually returned, in shapes rather than values.
