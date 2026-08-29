# Resumable turns: upstream contract

DSH cannot keep an arbitrary agent turn executing while iOS suspends the app.
The app now persists that a turn was active, preserves the current step for the
background time iOS grants, and reconciles server availability on return. Full
resume belongs in DeepSeek Harness because only the harness owns turn state.

## Required harness contract

1. Every turn has a stable `turn_id` and monotonically increasing `revision`.
2. `GET /sessions/:session/turns/:turn` returns `running`, `completed`,
   `interrupted`, or `failed`, plus the last committed revision.
3. `POST .../resume` takes the expected revision and an idempotency key. A
   second request with the same key returns the first result.
4. Before a tool call, the harness durably records its call id and arguments.
   Afterward it durably records the result. Resume never repeats a call whose
   result was committed.
5. A call that began but has no committed result is reported as `uncertain`.
   DSH must ask the user before retrying any write-capability call; reads may be
   retried automatically.
6. Session events expose turn id, revision and call id so Activity can group the
   local audit timeline without recording tool result contents.

## iOS reconciliation

On foreground, DSH first health-checks the local server, then queries the saved
turn id. Completed turns simply reload the Web UI. Running turns reconnect.
Interrupted turns offer Resume. Missing state is explained as lost rather than
silently starting another turn. Until the upstream endpoints exist, DSH only
reports the interruption and asks the user to inspect the conversation before
retrying.

## Acceptance tests

- suspension between two read tools resumes at the next call;
- suspension after a committed calendar write does not create a duplicate;
- an uncertain write is never retried without native confirmation;
- two resume requests with one idempotency key execute once;
- guest restart and app process termination produce the same reconciliation;
- Activity groups the pre- and post-resume events under one turn id.
