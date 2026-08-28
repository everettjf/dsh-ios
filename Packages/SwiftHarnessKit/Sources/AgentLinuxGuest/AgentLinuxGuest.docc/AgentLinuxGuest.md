# ``AgentLinuxGuest``

Attach an optional Linux execution backend without coupling the agent core to
iSH64 or another VM implementation.

``GuestHost`` advertises its streaming and cancellation capabilities plus a
``GuestRuntimeManifest`` containing backend, root filesystem, compatibility,
source, and license metadata. ``LazyGuestManager`` boots only on first use and
enforces bounded command, timeout, and output quotas.

The package contains contracts and tools only. It does not embed iSH64, Alpine,
or a root filesystem.
