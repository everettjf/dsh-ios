# ``AgentStorage``

Persist sessions and manage per-session workspaces.

``SessionStore`` saves Codable conversation records. ``WorkspaceStore`` stages
attachments in isolated workspaces and prevents paths from escaping their
workspace root.
