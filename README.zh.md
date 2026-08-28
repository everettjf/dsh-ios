# DSHIOS — iPhone / iPad 上的 Swift 原生 DeepSeek Agent

DSHIOS 是一个快速、原生的 iOS DeepSeek agent。主界面、模型流式请求、turn/step
状态机、会话、附件、权限确认、iOS 原生工具、MCP 和隐私诊断都由 Swift 接管。

应用仍保留 Alpine Linux guest，用于 shell、附件暂存和 Linux 专属工具；但只有
工具真正需要它时才会延迟启动。启动应用、查看会话、修改设置、调用原生工具或
MCP 都不会启动 Linux。这是从旧版 `dsh web` 向前迁移，不考虑回滚，也不承诺
兼容所有 dsh 插件。

> **当前开发主线：** `main` 是正在使用和持续开发的 Swift 重写版本。大改造前最后
> 一版官方 Node.js DeepSeek Harness 已保留在
> [`nodejs-harness-v1.0.10`](https://github.com/everettjf/dsh-ios/tree/nodejs-harness-v1.0.10)
> Tag。需要原来的 `dsh web` / Node.js 架构时请使用该 Tag；后续产品开发在 Swift
> 原生的 `main` 分支继续。

## 产品架构

```text
SwiftUI App
  ├─ DeepSeek / OpenAI 兼容 SSE 客户端
  ├─ turn/step 状态机与有界上下文
  ├─ 原生会话和附件存储
  ├─ 有权限治理的 iOS 工具与逐次确认
  ├─ 动态 MCP 客户端
  └─ 可选 Linux guest ── shell / 暂存 / Linux 工具
```

- 原生 agent 立即可用，Linux 不参与应用启动。
- 模型和 MCP 密钥存入 Keychain；会话与附件存入 Application Support。
- Activity 不记录提示词、模型输出、工具返回、URL 或密钥；导出再次脱敏。
- 写操作逐次显示具体确认；读取仍受能力开关和 iOS 系统权限控制。
- 远程 MCP 必须使用 HTTPS；本地开发允许 loopback HTTP。

完整约定见 [Swift 原生架构](docs/swift-native-agent.md) 和
[发布验收清单](docs/release-acceptance.md)。

## 升级与兼容性

升级只向前迁移，不提供回滚数据迁移：

- 已有 Linux guest 文件、`~/.dsh` 和 workspace 会保留，可通过 Linux 工具访问。
- 旧 `dsh web` 会话不会转换为新的原生会话。
- 新原生会话会在支持的存储 schema 之间自动迁移。
- 任意 dsh 插件不是兼容合同。新扩展优先使用原生工具或 MCP；依赖旧 Web
  运行时的插件最多只能留在可选 guest 内，由受支持的 Linux 工具触发。

## 构建与运行

需要 Apple Silicon Mac、Xcode 27、iOS/iPadOS 26 或更高版本、Node.js 20+、
Meson、Ninja、`lld` 和 Ruby `xcodeproj` gem。

```bash
git clone https://github.com/everettjf/dsh-ios.git
cd dsh-ios
make emulator
make rootfs
open DSH.xcodeproj
```

选择 DSH scheme，设置开发团队并运行；然后在 Agent Settings 中填写 endpoint、
API key 和 model。Linux 会保持停止，直到真正需要。

## 测试

```bash
make test               # emulator + rootfs + app + UI 全套测试
make test-emu           # emulator 与发布脚本回归
make test-rootfs        # guest 镜像及 mock model 集成测试
make test-sim           # 模拟器 XCTest + XCUITest
make test-device-unit   # 真机 app 与 guest 集成测试
make test-device        # 真机 app 与 UI 测试
```

App 测试覆盖 SSE 分片、多 step 工具、取消与重试、存储迁移、附件隔离、权限、
动态 MCP、guest 延迟启动、诊断隐私、10,000 个流式增量、100 turn 有界上下文，
以及真实 guest 集成。UI 测试验证原生启动、无主 WebView、设置、会话、Activity、
附件、横屏和前向 Linux 兼容说明。

## 目录

```text
app/            Swift 原生 agent，以及 iOS/guest 权限治理集成
tests/          XCTest、XCUITest、emulator 和 rootfs 集成测试
rootfs/         可选 Alpine guest 镜像 overlay
ish-arm64/      vendored 用户态模拟器
scripts/        工程、rootfs、测试和发布自动化
docs/           架构、安全、迁移与发布验收文档
```

DSH 的目标是 iOS 原生 DeepSeek agent，而不是把原 harness 逐字节翻译为 Swift。
受支持的扩展面是原生工具注册表和 MCP，Linux 是可选工作区能力。

项目因包含 iSH 衍生模拟器而采用 GPL-3.0，详见 [LICENSE](LICENSE)。
