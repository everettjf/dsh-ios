<h1 align="center">
  <img src="app/DSHAssets.xcassets/DSHAppIcon.appiconset/icon-1024.png" width="96" alt="DSH 图标"><br>
  DSH — 在 iPad / iPhone 上运行 DeepSeek Harness
</h1>

<p align="center">
  <b>把 <a href="https://github.com/deepseek-ai/deepseek-harness">DeepSeek Harness</a>（<code>dsh</code>）完整地跑在你的 iPad 或 iPhone 上——不越狱、不需要服务器、不依赖 Mac。</b>
</p>

<p align="center">
  <a href="https://xnu.app/dsh-ios/">项目主页</a> ·
  <a href="README.md">English</a> ·
  <a href="#快速开始">快速开始</a> ·
  <a href="#工作原理">工作原理</a> ·
  <a href="#测试">测试</a> ·
  <a href="#常见问题">常见问题</a>
</p>

<p align="center">
  <img alt="Platform" src="https://img.shields.io/badge/iOS%20%7C%20iPadOS-16%2B-blue">
  <img alt="Guest" src="https://img.shields.io/badge/guest-Alpine%203.21%20%C2%B7%20Node%2022%20%C2%B7%20dsh%200.1-1f6feb">
  <img alt="Tests" src="https://img.shields.io/badge/tests-emu%20%C2%B7%20rootfs%20%C2%B7%20XCTest%20%C2%B7%20XCUITest-success">
  <a href="LICENSE"><img alt="License" src="https://img.shields.io/badge/license-GPL--3.0-green"></a>
</p>

DSH 是一个原生 iOS app：它内嵌 [iSH-ARM64](ish-arm64) 用户态 Linux 模拟器，启动内置的
Alpine Linux 镜像（含 Node.js 22 和 `@deepseek-ai/dsh`），托管 `dsh web` 进程，并在
`WKWebView` 里显示 harness 自己的 Web 界面。Agent 循环、会话、工具、shell 全部在设备本地
运行，只有模型 API 请求会离开设备。

| iPad Air 真机（M3，iPadOS 27）首次启动 | 会话与工作区 |
|---|---|
| ![iPad Air 首次启动](docs/screenshots/ipad-air-m3-first-launch.png) | ![iPad Air 工作区](docs/screenshots/ipad-air-workspace.png) |

<sub>左：guest 已启动，DeepSeek Harness 服务在 127.0.0.1:3080（DSH 状态栏绿点）。右：带会话的
工作区——模型选择、"Guest Ask" 权限预设等都是 dsh 原生的 Web UI。</sub>

<details>
<summary>iPhone 17 Pro：启动页、界面、终端、服务日志</summary>
<p align="center"><img src="docs/screenshots/iphone-17-pro-montage.png" alt="iPhone 17 Pro 上的 DSH"></p>
</details>

<details>
<summary>也能在 Apple Silicon 的 iPad 模拟器上运行</summary>
<p align="center"><img src="docs/screenshots/simulator-ipad-air-m4.png" width="420" alt="iPad Air 模拟器上的 DSH"></p>
</details>

## 特性

- **完全本地运行**——app 内部就是 Alpine 3.21（aarch64）+ Node 22 + dsh 0.1；除模型 API 外可离线使用。
- **原汁原味的 harness 界面**——dsh 自己的 Web 应用通过本机回环端口提供：会话、工作区、工具、权限预设、设置。
- **随时可用的 shell**——DSH 状态栏的 `>_` 打开同一 guest 里的 Alpine 终端（`apk add`、`npm i -g`、查看 `~/.dsh`）；`⋯` 菜单提供 重新加载 / 服务日志 / 重启 Harness / 在 Safari 打开 / 关于。
- **受监督的服务进程**——自动选择空闲端口、HTTP 就绪探测、崩溃退避重启、回到前台时健康检查、启动页实时日志。
- **安全升级**——app 更新携带新的 guest 镜像时，会作为新 root 导入，并自动迁移 `~/.dsh`（会话、凭据、设置）和工作区。
- **模拟环境下的真实 LLM 流式输出**——Node 以 jitless 模式运行（没有 WebAssembly），DSH 自带一个返回真实流式 `Response` 的 `fetch()` polyfill；SSE 全链路有针对 mock DeepSeek 服务器的测试。
- **下载与文件**——会话日志导出保存在「文件 ▸ DSH ▸ Downloads」。
- 快捷键：⌘R 重新加载，⇧⌘T 终端。以 iPad 为主，iPhone 横竖屏也都可用。

## 快速开始

**环境要求：** Apple Silicon 的 macOS，Xcode 26/27，`brew install meson ninja lld`
（`ld.lld` 用于构建 guest 的 VDSO，缺少它 guest 无法运行），Node.js ≥ 20 + npm，
`xcodeproj` Ruby gem（`gem install xcodeproj`，或随 CocoaPods 一起），以及一个 Apple 开发者团队用于真机签名。

```bash
git clone https://github.com/everettjf/dsh-ios.git && cd dsh-ios
make emulator        # 构建 iSH-ARM64 命令行版 + fakefsify（用于构建和测试 guest 镜像）
make rootfs          # build/root.tar.gz —— Alpine + Node 22 + dsh（约 95 MB，约 6 分钟，需要联网）
open DSH.xcodeproj   # 选 DSH scheme → 你的 iPad → 设置 team → Run
```

也可以全部命令行完成：

```bash
make run TEAM=XXXXXXXXXX DEVICE=<udid>   # 构建、签名、安装、启动到 iPad
```

首次启动会导入 guest 镜像（约 30 秒，启动页有进度），之后启动只需几秒。harness 询问 DeepSeek
API key 时，粘贴即可，或点「稍后配置」；key 由 dsh 存在 guest 内（`/root/.dsh`），app 本身不保存。

## 工作原理

```
┌─ DSH.app ────────────────────────────────────────────────────────┐
│  DSHRootViewController ──► WKWebView ──► http://127.0.0.1:3080    │
│         │                                        ▲                │
│  DSHHarness  (选端口 · 就绪探测 · 重启 · 健康检查)                │
│         │  ISHShellExecutor                      │ 回环           │
│  ┌──────▼──── iSH-ARM64 模拟器 (Alpine 3.21 aarch64) ─────────┐   │
│  │  /usr/local/bin/dsh-serve                                  │   │
│  │    → node --expose-internals @deepseek-ai/dsh web          │   │
│  │        --host 127.0.0.1 --port N  ─────────────────────────┘   │
│  └────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────┘
```

- **模拟器。** iSH-ARM64 是用户态 Linux 模拟器（Asbestos threaded-code 解释器 + AArch64 guest 后端）。
  guest 的 socket 直通宿主 socket，所以 dsh 监听的回环端口在 app 的 WebView（以及 Safari）里都能访问。
- **Guest 镜像。** `scripts/build-rootfs.sh` **在 Mac 上用同一个模拟器**构建 `root.tar.gz`：Alpine
  minirootfs → `apk add nodejs npm …` → 把 `rootfs/staging` 里锁定版本的 npm 依赖树（在宿主上按
  linux/arm64/musl 安装）放进去 → 为 musl 重新编译 `node-pty` → 叠加 overlay → 用 `unfakefsify` 导出。
  `rootfs/overlay` 包含入口脚本 `dsh-serve`、guest 自检脚本，以及 `cordis.patch.yml`——dsh 的 profile
  层，用来关闭逐命令沙箱（整个 guest 本身就是沙箱）并定义 `guest-ask` 权限预设。
- **监督器。** `DSHHarness` 选一个空闲回环端口，通过 `ISHShellExecutor` 启动 `dsh-serve`，轮询直到 HTTP
  可用，崩溃时重启，并把状态发布给 UI。`DSHRootUpgrader` 每次启动都比对内置镜像的 SHA-256 与已导入的
  root，不一致时导入新镜像并迁移用户数据。

### 对模拟器的改动（`ish-arm64`，vendored 自 OpenMinis/ish-arm64）

| 改动 | 原因 |
|---|---|
| 新增 `FCVTL/FCVTL2`、`FCVTN/FCVTN2`、`FCVTXN/FCVTXN2` 及向量定点转换 `SCVTF/UCVTF/FCVTZS/FCVTZU #fbits` gadget | libvips（dsh 图片附件插件 `sharp` 用到）会在这些指令上触发非法指令 |
| 修复 `FMOV (scalar, immediate)` 解码 | imm8 的 bit 6 未取反，`2.25`、`31.0` 这类常量在 guest 里全部算错 |
| `waitpid()` 不再在 1 秒有界等待超时时误返回 `EINTR` | 曾导致 gcc/g++（`failed to get exit status`）、node-gyp 以及任何等待子进程超过 1 秒的程序失败 |
| 返回真实 `Response` 对象的流式 `fetch()` polyfill（`app/RootfsPatch.bundle`） | undici 的 LLM 流式（SSE）需要 WebAssembly，而 jitless V8 没有 |
| `ISHShellExecutor` 返回 shell 退出码并在进程退出后排空管道；`ContainerURL()` 在没有 app group 时回退；部署目标 15.0 | app 集成需要 |

vendored 副本的上游 commit 记录在 [`ish-arm64/UPSTREAM.md`](ish-arm64/UPSTREAM.md)；这些修复相互独立，欢迎回馈上游。

## 测试

```bash
make test               # 在这台 Mac 上无人值守：模拟器 + rootfs + 模拟器上的 XCTest/XCUITest
make test-device-unit   # 连接的 iPad 上跑单元测试 + guest 集成测试
make test-device        # 再加 UI 测试（需先在 iPad 设置 ▸ 开发者 中打开 UI Automation）
```

| 套件 | 覆盖内容 | 运行环境 |
|---|---|---|
| `tests/emu-test.sh` | 新增的 NEON gadget 与 FMOV 修复（在 guest 里用 gcc 编译的 C 测试）、`waitpid` 回归、fetch polyfill（宿主 node，11 项） | macOS |
| `tests/rootfs-test.sh` | 像 app 一样导入 `root.tar.gz`、guest 自检（node-pty/koffi/ripgrep/sharp）、profile patch、**通过 mock DeepSeek SSE 服务器的 headless 完整对话回路**、`dsh-serve` 本机可达 | macOS |
| `DSHTests`（XCTest，宿主在 app 内） | 端口分配、日志环、就绪探测、监督器状态机（假 launcher + 本地 HTTP 服务器）；host bridge 的认证/能力开关/限流；guest 集成：真实服务响应、`dsh-selftest`、node/dsh 版本、镜像簿记、**用 app 内 mock 模型跑完整一轮 agent 对话并通过 bridge 调用 `device_info`** | 模拟器 / 真机 |
| `DSHUITests`（XCUITest） | 启动到 DeepSeek Harness 界面、状态栏端口、服务日志页、终端页、横屏布局 | 模拟器 / 真机 |

现状：全部通过（`make test`：3 + 16 + 32 + 4 项；iPad Air 真机 32/32 单元 + guest 集成测试）。测试都在本地跑：构建需要 Apple Silicon Mac + Xcode + 模拟器工具链，真机套件还需要连着 iPhone / iPad，因此没有托管 CI。

## 目录结构

```
DSH.xcodeproj   生成的 Xcode 工程（target：DSH、DSHTests、DSHUITests；scheme：DSH）
app/            Objective-C 源码、AppDSH.xcconfig、Info.plist、素材、启动页、隐私清单
rootfs/         打进 guest 镜像的 overlay + 锁定版本的 npm 清单（staging/package.json）
scripts/        build-rootfs.sh · gen-xcode-project.rb
tests/          emu-test.sh · rootfs-test.sh · mock-deepseek.mjs · fetch-polyfill-test.mjs
                emu/（guest 内 C 测试）· DSHTests/ · DSHUITests/
docs/           截图
build/          生成物：root.tar.gz、工作目录、xcresult（已 gitignore）
ish-arm64/      模拟器（vendored，见其 UPSTREAM.md）
site/           项目主页（GitHub Pages → https://xnu.app/dsh-ios/）
```

`DSH.xcodeproj` 由 `scripts/gen-xcode-project.rb`（`make project`）生成，增删源码文件后重新运行即可。
所有构建设置在 `app/AppDSH.xcconfig`；bundle id 为 `com.xnuapp.dsh`（自己构建请改 `DSH_BUNDLE_ID_PREFIX`）。

## iOS 能力（host bridge）

app 内运行一个 loopback HTTP 服务，guest 里的 dsh 工具通过它访问 iOS 能力。已落地：

| 工具 | 读取内容 | 开关 |
|---|---|---|
| `device_info` | 型号、iOS 版本、地区、电量、温度状态 | 默认开启 |
| `calendar_query` | 日历事件 | 开关 + iOS 授权 |
| `reminders_query` | 提醒事项与到期时间 | 开关 + iOS 授权 |
| `health_query` | 步数/距离/活动能量、心率、睡眠、运动记录 | 开关 + iOS 授权 |

剪贴板、位置、照片、分享、Shortcuts 已完成设计但尚未实现——每加一个能力 = app 侧一个
路由 + guest 插件里一个 tool。

除 `device_info` 外**默认全部关闭**，在 **⋯ ▸ Capabilities** 里打开；开关对 agent 的
下一次工具调用即刻生效（回合中途也算），iOS 自己的授权仍然叠加在上面。任一道门没开时
调用会返回可恢复的 `permission_denied`，告诉模型需要用户做什么，而不是卡在系统弹窗上等。

Apple Health 有个值得注意的地方：iOS 从不告诉 app **读**权限是否被拒绝，所以"没有数据"
和"被拒绝"长得一模一样。因此 Health 的返回里会带一条说明，并要求模型如实转述，而不是
直接断定你这个月一步没走。

能力由 app 把关，而不是 guest：每次启动随机生成的 bearer token 挡住**其他 app**，
而每个能力的开关（敏感能力还要原生确认）才是约束 **agent** 的手段——agent 在 guest
里是 root，能读到我们放在那里的任何秘密。每次调用都会记录到「服务日志」。

协议、安全模型与能力/权限矩阵见 [docs/host-bridge.md](docs/host-bridge.md)；
已完成的部分和后续计划见 [docs/roadmap.md](docs/roadmap.md)。

## 常见问题

**需要越狱、TrollStore 或特殊 entitlement 吗？** 不需要。它就是一个普通的沙箱 app：模拟器纯用户态，node 以 jitless 运行。

**速度如何？** 模拟环境下的 Node 比原生慢数倍。在 M 系列 iPad 上聊天和常规工具调用没问题；guest 内大规模 `npm install` 或编译会比较慢。

**我的数据在哪？** 在 app 容器内的 guest 镜像里：`/root/.dsh`（会话、凭据、设置）和 `/root/workspace`，app 升级时会自动迁移（见「安全升级」）。下载文件在「文件 ▸ DSH」。

**能装更多工具吗？** 可以——打开终端（`>_`）然后 `apk add …`、`npm i -g …`、`pip …`，这就是一个正常的 Alpine 根文件系统。

**为什么是 GPL？** 因为 app 编译并静态链接了 GPLv3 的 iSH 模拟器，见[许可证](#许可证)。

## 参与贡献

欢迎 issue 和 PR。提 PR 前请先跑 `make test`（需要 Apple Silicon Mac + Xcode）；改动模拟器时请在
`tests/emu/neon_convert_test.c` 或 `tests/emu-test.sh` 里补上用例。升级内置的 dsh：修改
`rootfs/staging/package.json`，执行 `make rootfs`，再 `make test-rootfs`。

## 致谢

- [DeepSeek Harness](https://github.com/deepseek-ai/deepseek-harness) —— agent harness 本体（MIT）。
- [iSH](https://github.com/ish-app/ish) 与 [iSH-ARM64](https://github.com/OpenMinis/ish-arm64) —— 本 app 所依赖的模拟器（GPLv3）。
- [libarchive](https://github.com/libarchive/libarchive)、[hterm](https://chromium.googlesource.com/apps/libapps/)、[Alpine Linux](https://alpinelinux.org)。

## 许可证

**GPL-3.0。** DSH 编译并静态链接了 GPLv3 的 iSH / iSH-ARM64 模拟器，因此整个 app 以 GPLv3 发布；iSH
在 [`ish-arm64/LICENSE.IOS`](ish-arm64/LICENSE.IOS) 中关于 App Store 的附加条款同样适用。全文见
[LICENSE](LICENSE)，第三方声明（libarchive、hterm、DeepSeek Harness、Alpine 软件包）见 [LICENSE.md](LICENSE.md)。

本项目与 DeepSeek 及 iSH 项目无隶属关系。
