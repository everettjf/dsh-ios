# Swift Harness Kit API evolution

The package follows Semantic Versioning. The current development release is
`0.1.0` and supports iOS 16 or newer and macOS 13 or newer.

## Public API contract

- Unprefixed symbols such as `HarnessAgent`, `ModelProvider`, `AgentTool`, and
  `SessionStore` are the supported public vocabulary from 0.1 onward.
- Existing `DSH*` declarations remain source-compatible aliases during the 0.x
  series so SHOS can migrate incrementally. New integrations should not use
  them.
- A breaking source change increments the minor version before 1.0. Additive,
  source-compatible work increments the patch version.
- After 1.0, breaking changes require a major version increment. Deprecated
  APIs remain available for at least one minor release when practical.
- Codable session records and model/tool wire payloads are versioned contracts.
  Readers must tolerate additive fields; incompatible persisted formats require
  an explicit migration.
- `AgentLinuxGuest` is an optional adapter contract. iSH64 and its filesystem
  are not embedded in this Swift package and follow their own licenses.

The file `VERSION` records the intended package release. Git tags for package
releases use the form `swift-harness-kit-<version>`.
