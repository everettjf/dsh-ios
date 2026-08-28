# ``AgentRuntime``

Build streaming, tool-using agents in Swift without coupling the core loop to a
specific model provider, user interface, or execution environment.

## Overview

``HarnessAgent`` owns the turn/step state machine. A host supplies a
``ModelProvider``, optionally supplies tools through ``ToolProviding``, observes
``AgentSnapshot`` updates, and persists ``ChatMessage`` values using the storage
adapter of its choice.

Swift Harness Kit supports iOS 16 and macOS 13. Linux execution is optional and
is kept outside the core runtime.

## Topics

### Essentials

- <doc:GettingStarted>
- ``HarnessAgent``
- ``ModelProvider``
- ``AgentSnapshot``

### Messages and model events

- ``ChatMessage``
- ``CompletionRequest``
- ``ModelEvent``
- ``JSONValue``

### Tools

- <doc:CustomTools>
- ``ToolProviding``
