# Upstream

This directory is a vendored copy of https://github.com/OpenMinis/ish-arm64
(branch `master`, commit `7e100366a4b59557a4a0c4657d0d6115e99d1f5e`), itself a
fork of https://github.com/ish-app/ish, with the changes DSH needs (see
`../dsh-ios/README.md`, "Changes made to the emulator"). `deps/libarchive` and
`deps/libapps` were git submodules upstream and are vendored here as plain
directories (`fc6563f5130d8a7ee1fc27c0e55baef35119f26c` and
`b8cacae35e5b11d64bb736a053921c16ca7faf9e`).
