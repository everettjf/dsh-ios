# TestFlight feedback loop

External feedback is handled against the exact app build, not as an unstructured
message. Ask testers to use the **TestFlight feedback** issue form and include the
version/build, device and OS, impact, reproduction steps, and expected/actual
result. Screenshots and **⋯ ▸ Server Log** are useful, but must be redacted of
API keys, bearer tokens, personal data, and conversation contents.

## Triage

| Impact | First action | Release decision |
|---|---|---|
| Startup failure or possible data loss | Reproduce immediately; preserve the previous root and logs | Stop the rollout until fixed or disproved |
| Core feature blocked | Reproduce on the reported OS/device class | Fix in the next TestFlight build |
| Incorrect with a workaround | Add a regression test where practical | Schedule by frequency and user impact |
| Cosmetic or suggestion | Confirm scope; avoid mixing it into stability work | Backlog unless it obscures state or consent |

For every accepted report, link the fixing commit/PR and record the first build
containing the fix. Close it only after the reporter or a clean-device regression
test verifies that build. Duplicate reports remain linked to the canonical issue
so frequency is visible.

## Build checklist

Before assigning an external group:

1. Run `make test` and retain `build/test-sim.xcresult`.
2. Archive through `scripts/release.sh`; it checks every required privacy purpose
   string before App Store validation.
3. Smoke-test fresh install, upgrade with an existing session/workspace,
   background/foreground during a turn, denied permissions, and Location Services
   switched off.
4. Put user-visible changes and known issues in TestFlight **What to Test**.
5. After processing, verify the version/build shown in TestFlight before enabling
   the external group.
