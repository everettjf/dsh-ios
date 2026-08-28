# SHOS（Swift Harness OS）与 Swift Harness Kit 总体规划

## 一、命名与产品关系

### 面向用户的产品：SHOS

**SHOS** 是 iPhone、iPad 及后续 Apple 平台上的原生 Agent App 品牌，名称展开为
**Swift Harness OS**。产品界面、App Store 名称和图标标题只展示 `SHOS`。
它不再被定义为 Node.js DeepSeek Harness 的移植版，也不以兼容旧 `dsh`
插件为产品目标。

SHOS 的一句话定位：

> 快速、原生、安全的 Apple 平台 AI Agent，既能使用系统能力，也能按需
> 启动完整 Linux 工作区。

DeepSeek 是默认支持和重点优化的模型提供商，但 SHOS 不绑定单一模型。
后续可以接入其他 OpenAI-compatible 服务、Apple Foundation Models 和其他
独立 Provider。

建议采用以下展示形式：

- App Store 名称：`SHOS`
- App 图标标题：`SHOS`
- Bundle display name：`SHOS`
- 副标题：`Native AI Agent for iPhone and iPad`
- 中文副标题：`iPhone 与 iPad 原生 AI Agent`

正式改名需要单独检查 App Store Connect 名称可用性、商标和域名。本规划先
确定产品架构，不把这些外部结果作为开发阻塞项。

### 底层框架：Swift Harness Kit

**Swift Harness Kit** 是 SHOS 内部孵化、并将独立发布的可复用 Swift Agent
Runtime 框架名称。它代表模型之上的完整 Harness：

- 模型传输和流式事件
- turn/step Agent 状态机
- 上下文和会话
- 工具注册、执行和结果回送
- 权限、确认、审计和安全边界
- MCP
- 原生 Apple 工具
- 可选 Linux 工作区
- UI 可观察事件和诊断

框架品牌固定为 `Swift Harness Kit`；模块仍采用职责名称，不强制使用统一品牌
前缀。对外发布前只需完成仓库、Swift Package Index、商标与许可证检查，不再
另起框架名称。

Swift module 不使用宽泛的 `HarnessKit` 名称，而采用职责明确的名称：

```swift
import AgentRuntime
import AgentProviders
import AgentTools
import AgentMCP
import AgentStorage
```

这样未来即使框架品牌调整，第三方应用的 import 和核心 API 也不必整体改名。

## 二、产品目标与非目标

### 目标

1. SHOS 冷启动不依赖 Linux，不加载旧 Web UI。
2. Swift 原生完成模型请求、SSE、Agent 循环、会话、工具治理、MCP 和 UI。
3. Health、Location、Contacts、Calendar、Files、Photos 等能力通过明确权限和
   每次写入确认安全开放给 Agent。
4. bash、代码执行和 Linux-only 工具第一次被调用时才启动 iSH64 Guest。
5. 核心 Runtime 可以脱离 SHOS、UIKit 和 iSH，被其他 Swift App 使用。
6. DeepSeek 体验优秀，同时保持 Provider 可替换。
7. 所有关键状态都可以持久化、取消、恢复、测试和审计。

### 非目标

- 不承诺兼容任意旧版 dsh/Node.js 插件。
- 不在第一阶段实现复杂多 Agent、RAG 平台或云端控制台。
- 不让 Linux Guest 成为核心 Swift Package 的强制依赖。
- 不把 App UI 放入核心 Runtime。
- 不将 API Key 明文写入源码、UserDefaults 或可导出的会话数据。
- 不为了框架抽取而长期破坏 SHOS 的可运行状态。

## 三、目标架构

```text
SHOS App
  ├─ SHOSUI                 SwiftUI 产品界面与 App 导航
  ├─ SHOSComposition        配置、依赖装配、生命周期
  │
  ├─ Swift Harness Kit
  │   ├─ AgentRuntime          turn/step、上下文、事件、取消/重试
  │   ├─ AgentProviders        DeepSeek/OpenAI-compatible、SSE
  │   ├─ AgentTools            Schema、Registry、Policy、Audit
  │   ├─ AgentMCP              官方 MCP Swift SDK 适配层
  │   ├─ AgentStorage          Session、Workspace、Attachment、Migration
  │   ├─ AgentAppleTools       Health/Location/Contacts/Calendar/…
  │   └─ AgentUI               可选的通用 SwiftUI 组件
  │
  └─ AgentLinuxGuest（可选挂载层、独立 GPL 边界）
      └─ iSH64 + Alpine + shell/staging backend
```

### 依赖方向

- `AgentRuntime` 只依赖 Foundation 和纯 Swift 数据结构。
- Provider、Tools、MCP、Storage 依赖 Runtime 的协议，不反向依赖 App。
- `AgentAppleTools` 可以依赖 Apple frameworks，但 Core 不允许导入 UIKit、
  SwiftUI、HealthKit、EventKit、Photos 或 iSH 符号。
- `AgentLinuxGuest` 只实现 `ExecutionBackend`，iSH 类型不能泄漏到公共 Runtime API。
- SHOS 只通过公开 API 使用这些模块，不能依赖模块内部实现。

权威依赖方向如下，禁止反向依赖：

```text
SHOS → Swift Harness Kit
SHOS → AgentLinuxGuest → iSH64
Swift Harness Kit Core ✕→ AgentLinuxGuest / iSH64
```

因此第三方 App 可以只使用 Swift Harness Kit；iSH64 是 SHOS 或其他宿主显式选择的
执行后端，不是框架核心的安装、编译或启动前提。

## 四、核心公共接口

第一版稳定 API 保持小而明确：

```swift
public actor AgentRuntime {
    public init(
        model: any ModelProvider,
        tools: any ToolProviding,
        storage: any SessionStoring,
        policy: any ToolAuthorizationPolicy,
        telemetry: any AgentTelemetry
    )

    public func run(_ input: AgentInput)
        -> AsyncThrowingStream<AgentEvent, Error>

    public func cancel()
}

public protocol ModelProvider: Sendable {}
public protocol AgentTool: Sendable {}
public protocol SessionStoring: Sendable {}
public protocol ExecutionBackend: Sendable {}
```

`AgentEvent` 是 Runtime 与 UI、诊断、测试之间唯一的流式状态契约，至少覆盖：

- text/reasoning delta
- turn/step started 与 completed
- tool requested/confirmed/started/finished/failed
- token usage
- retry、recoverable failure 和 terminal failure
- cancelled 与 completed

## 五、数据、安全与权限

### 数据归属

- API/MCP 凭据：Keychain。
- 会话、消息、附件元数据：Application Support。
- 附件内容：每会话隔离的 Workspace。
- Linux 文件：Guest root/workspace，不自动混入原生会话数据库。
- 日志：有界生命周期数据，不记录完整 prompt、response、tool result、URL 或
  Secret。

### 工具治理

- 读取工具必须经过功能开关和 iOS 系统权限。
- 写入、分享、通知、shell 和代码执行必须经过显式 Policy。
- 默认写操作逐次确认，不能以含糊的会话级授权代替。
- Tool 参数在弹出确认框之前完成 schema、长度、路径和范围校验。
- shell 需要超时、输出上限、工作目录边界和明确的取消能力。
- 所有工具产生结构化的审计生命周期，但不默认保存敏感载荷。

## 六、许可证与发布边界

纯 Swift Runtime 的目标是采用 MIT 或 Apache-2.0 等宽松许可证，方便商业 App
使用。最终选择前必须完成代码来源和依赖许可证检查。

iSH-derived Guest 使用 GPL，并带来较大的二进制和 rootfs。它不能成为核心包
的无条件依赖。规划中的发行形态为：

1. `Swift Harness Kit Core`：无 iSH、宽松许可证、体积小。
2. `AgentLinuxGuest`：开发者主动选择的独立 GPL 产品或仓库。
3. `SHOS Lite` 构建配置：Native Tools + MCP，无 Linux Payload。
4. `SHOS Full`：明确包含 GPL Guest，并提供源码、许可证和必要声明。

应用也可以自行实现 `ExecutionBackend`，连接远程容器或自己的执行沙箱。

## 七、实施阶段

### Phase 0：冻结边界与基线

- 盘点所有当前 `DSH*` Swift 类型并划分模块归属。
- 确定 SHOS、Swift Harness Kit、旧 Node 版本三者的文档边界。
- 固定现有 Swift 分支的功能、性能、测试和包体基线。
- 加入核心依赖规则，防止 UI、AppleTools、Guest 反向污染 Runtime。

验收：模块图获得确认；现有 SHOS 构建和测试全部通过。

### Phase 1：建立本地 Swift Package

- 在当前仓库加入 `Package.swift`，暂不立即拆新仓库。
- 首先抽取 JSON/message/tool models、SSE decoder、ModelProvider 和 Agent loop。
- 将对应 XCTest 迁移到 Package tests，可直接执行 `swift test`。
- SHOS 改用本地 Package，保持 UI 和行为不变。

验收：Core 在不构建 iSH/Xcode App 的情况下完成测试；SHOS 回归通过。

### Phase 2：稳定 Runtime 与 Provider

- 清除 Core 中的 DSH 单例、Objective-C 日志和 App defaults 依赖。
- 固化多 step、tool-call fragments、并行调用、context budget、取消、重试和恢复。
- 将 DeepSeek/OpenAI-compatible 实现放入 `AgentProviders`。
- 建立 Provider conformance suite，覆盖碎片 SSE、错误 JSON、限流和断线。

验收：任意 Provider 可以通过同一套确定性测试接入 Runtime。

### Phase 3：抽取 Tools、Policy 与 Storage

- 抽取 Tool Registry、governed wrapper、confirmation 和 audit events。
- 抽取 Session、Workspace、Attachment 和 migration。
- 让存储、权限确认和遥测都可由第三方注入。
- 将原生 iOS route 包装到 `AgentAppleTools`。

验收：第二个最小示例 App 可以更换 Storage/Policy 而无需 fork Runtime。

### Phase 4：标准化 MCP

- 引入官方 MCP Swift SDK。
- 保留自己的适配层，避免 MCP 版本细节扩散到所有 public API。
- 覆盖发现、重连、取消、认证、重复工具名和 schema error。
- 至少与两个独立 MCP Server 做互操作测试。

验收：MCP Client 稳定，不影响无 MCP 的最小 Core 用户。

### Phase 5：隔离 Linux Guest

- 定义与 iSH 无关的 `ExecutionBackend`。
- 把 lazy boot、shell、staging、timeout、quota 和 lifecycle 放入 Guest backend。
- 增加 `NO_LINUX_GUEST` 配置并持续测试。
- 明确 Guest 源码、rootfs、许可证和分发流程。

验收：SHOS Lite 完全不包含 Guest；SHOS Full 只在工具调用时启动 Guest。

### Phase 6：完善 SHOS 产品

- 将 App 重构为薄的 composition root 和官方参考客户端。
- 完成聊天输入、键盘、滚动、工具状态、权限引导和错误恢复体验。
- 完成会话管理、附件、MCP 设置、活动记录与 Linux Workspace UI。
- 增加中文/英文、本地化、VoiceOver、Dynamic Type 和 iPad 布局。
- 建立冷启动、首 token、内存、能耗、包体和 Guest 启动性能门槛。

验收：TestFlight 用户无需理解 Harness/iSH 即可完成核心任务。

### Phase 7：独立框架发布

- 以 `Swift Harness Kit` 完成 GitHub、Swift Package Index、域名和商标冲突检查。
- 完成 permissive Core 与 GPL Guest 的代码来源审计。
- 将成熟 Package 移入独立仓库，并保留清晰提交历史。
- 提供 DocC、最小聊天、原生工具、MCP 和 Linux Workspace 示例。
- SHOS 改用带 Tag 的 Package release。
- 在至少第二个 App 验证后发布框架 `1.0.0`。

验收：框架与 SHOS 可以独立升级和发布。

## 八、测试与质量门槛

每个阶段必须保持以下检查：

- `swift test`：Core、Provider、Tools、Storage。
- Simulator XCTest：AppleTools 权限和 App integration。
- XCUITest：启动、聊天、键盘、会话、设置、工具确认、错误恢复。
- 真机：Health、Location、Contacts、Calendar、Photos、分享、通知。
- Guest integration：第一次调用 lazy boot、bash、文件 staging、超时和取消。
- MCP interoperability：真实 Server 与错误 fixtures。
- 安全测试：路径穿越、Host/token、超大参数、Secret redaction、能力关闭。
- 性能测试：10,000 delta、100 turn context、首 token、内存和能耗。

任何 public API 变更都必须带测试和迁移说明。任何修改都必须提交并 push，保持
当前 Swift 分支随时可以被其他开发者 checkout 和验证。

## 九、版本与发布路线

### SHOS

- 继续使用独立 App 版本号和 TestFlight build number。
- 品牌改名、Bundle display name、图标和商店元数据作为单独发行完成。
- 每个 TestFlight build 记录使用的 Swift Harness Kit commit/tag。

### Swift Harness Kit

- `0.1.x`：本仓库内部 Package，API 可快速调整。
- `0.2–0.5`：模块稳定、Provider/Tools/Storage/MCP 拆分。
- `0.6–0.9`：第二 App 验证、DocC、兼容检查、独立仓库候选。
- `1.0.0`：稳定 public API、SemVer、许可证与发布边界完成。

### AgentLinuxGuest

- 版本必须记录 iSH commit、rootfs 版本、校验值和兼容的 Core 版本范围。
- Guest 更新与 Core 更新分离，避免每次 Runtime 修改都重新发布大体积 Payload。

## 十、当前执行顺序

截至 2026-08-28，Phase 0 已完成；`AgentRuntime`、`AgentProviders`、
`AgentTools`、`AgentStorage`、`AgentMCP` 和 `AgentLinuxGuest` 已成为独立 Package products，SHOS
已通过本地 Swift Package 链接这些模块，不再直接编译 Package 源码。`AgentMCP`
的生产路径已采用官方 MCP Swift SDK 0.12.1，并保留内部适配层与确定性 wire
fixtures；官方 SDK 的内存 Client/Server 端到端互操作测试也已建立。
生产 HTTP initializer 还通过两个独立进程实现（Node 与 Python）的 MCP server
完成互操作，覆盖自定义/Bearer Header、初始化、工具发现、工具调用、disconnect
后重连和慢调用取消；适配层会立即传播取消并丢弃 SDK 的迟到结果。
`AgentLinuxGuest` 已提供与 iSH 无关的 lazy host、bash、附件 staging 和审批协议；
SHOS 中只保留 iSH runtime 与原生确认 UI 的适配器。Package 已覆盖并发启动合并、
拒绝不启动、超时钳制与跨会话附件隔离。

接下来按以下顺序继续：

1. **SHOS 品牌收口**：统一 App、Lite target、文档、测试与发布元数据；保留现有
   Bundle ID 和 `DSH*` 技术前缀，避免品牌改名破坏持久化和公共 API。
2. **Apple Tools 模块化**：把无 UI 的参数、结果和执行协议抽到
   `AgentAppleTools`；HealthKit、EventKit、Photos、权限弹窗仍由宿主适配。
3. **Swift Harness Kit 0.1**：整理 public API、DocC、最小聊天/MCP/自定义工具
   示例、SemVer 与兼容性检查，使第二个 App 可直接接入。
4. **iSH64 挂载完善**：固定 `ExecutionBackend` 契约，补齐流式 stdout/stderr、
   取消、配额、镜像版本/校验值、工作区迁移与 GPL 分发材料。
5. **SHOS 产品完善**：Markdown、工具时间线、会话搜索、附件体验、中英文、
   VoiceOver、Dynamic Type、iPad 分栏与性能门槛。
6. **发布验证**：持续执行 Package、iPhone/iPad simulator、MCP、Guest、Rootfs、
   安全与 Archive 验收；真机权限验证按当前决定延后，不阻塞本阶段开发。

整个过程在当前 `rewrite-deepseek-harness-with-swift` 分支持续开发，采用前进式
迁移，不为旧 Node.js Web Harness 增加新的兼容层。该分支不得合并到 `main`；
`main` 继续保留官方 Node.js DeepSeek Harness 基线。所有修改必须在当前分支
提交并 push。

Phase 0 的权威逐文件清单见 [Swift Harness Kit module
inventory](swift-harness-kit-module-inventory.md)。
