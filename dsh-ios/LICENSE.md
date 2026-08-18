# License

DSH is licensed under the **GNU General Public License v3.0** (see
[LICENSE](LICENSE)), because it compiles and statically links the
[iSH](https://github.com/ish-app/ish) / [iSH-ARM64](https://github.com/OpenMinis/ish-arm64)
emulator, which is GPLv3 with the additional App Store terms in
[`../ish-arm64/LICENSE.IOS`](../ish-arm64/LICENSE.IOS). Those additional terms
apply to DSH as well.

Third-party components:

| Component | License | How it is used |
|---|---|---|
| iSH / iSH-ARM64 (`../ish-arm64`) | GPLv3 (+ LICENSE.IOS) | compiled into the app |
| libarchive | BSD-2-Clause | linked into the app |
| hterm (libapps) | BSD-3-Clause | bundled JS for the terminal view |
| DeepSeek Harness `@deepseek-ai/dsh` and its npm dependencies | MIT and others (see each package) | shipped inside the guest image `root.tar.gz` |
| Alpine Linux packages (busybox, musl, Node.js, git, …) | various (GPL, MIT, BSD, …) | shipped inside the guest image `root.tar.gz` |

The guest image is built reproducibly by `scripts/build-rootfs.sh` from the
Alpine 3.21 aarch64 repositories and the pinned npm manifest in
`rootfs/staging`; corresponding sources are available from those upstreams.
