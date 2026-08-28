# ``AgentAppleTools``

Expose Apple-native capabilities without moving permission UI into the package.

The host implements providers such as ``DeviceInformationProviding`` and route
execution, then registers the matching tools. This keeps system-framework
ownership, entitlements, and permission prompts in the application target.
