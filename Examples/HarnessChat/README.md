# HarnessChat

HarnessChat is an independent iOS 16 reference host for Swift Harness Kit. It
links package products through their public APIs and does not compile SHOS,
iSH64, Alpine, rootfs, or Objective-C capability-bridge sources.

Open `DSH.xcodeproj`, select the `HarnessChat` scheme, run on a simulator, then
enter a DeepSeek/OpenAI-compatible endpoint, API key, and model. The example
demonstrates streaming chat, cancellation, session persistence, a custom Swift
tool, and an injected `AgentAppleTools` device provider.

The API key is kept in memory in this intentionally small sample. Production
hosts should store credentials in Keychain, as SHOS does.
