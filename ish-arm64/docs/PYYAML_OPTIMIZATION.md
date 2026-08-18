# pip install pyyaml 端到端优化报告 (iSH-ARM64)

## ⭐ 最终端到端汇总 (真实 wall-clock, pyyaml 正确装出)

| 阶段 | real 秒数 | 累计提升 vs cold |
|---|---|---|
| iSH cold (无 pyc, 原始基线) | **72.86s** | — |
| iSH warm (+ 预编译 pyc) ← **第一层, KPI 答案** | **25.47s** | **-65%** ✅ |
| iSH warm + INCREF 融合 (第二层) | **25.2s** | **-65.4%** |
| Docker Alpine (镜像自带 pyc, 参照) | 1.0s | — |

- **核心 KPI: 端到端提升 65%,远超 ≥30% 目标 ✅**
- 公平倍率(两边都有 pyc): iSH 25.2s / Docker 1.0s = **25×**(cold 时是不公平的 72×)
- 全部改动 **bit-identical** 验证通过(见下)


## KPI
真实端到端 `pip install pyyaml` 相比 Docker Alpine 慢 ~42×,目标端到端提升 ≥30%。
**第一层(pyc 预编译)已达成 65% 提升,远超 KPI。**

---

## 1. 根因(用真实全过程 profile 定位,非臆测)

`pip install pyyaml` 会 fork 多个子进程(pip 主进程 + `setup.py egg_info`
metadata 子进程 + `setup.py bdist_wheel` 构建子进程)。跨子进程指令级 profile
(6.5B 指令 / 8 进程)显示:大量时间花在 **重复把 `.py` 源码编译成字节码**
(PEG 解析器 + `_PyEval_EvalFrameDefault` + `compile()`),因为:

- **Docker 的 python 镜像出厂预编译了 1406 个 `.pyc`**(镜像构建时 `compileall`),
  所以子进程 import stdlib/setuptools 时直接加载字节码,从不重新编译。
- **iSH 的 rootfs cold 状态没有任何 `.pyc`**,每个 fork 出的子进程都从源码
  cold-compile 整个 stdlib + setuptools。而 iSH 软件 JIT 里 `compile()` 比原生
  慢 ~31-35×,这个重复编译就是端到端耗时的最大来源。

阶段分解(cold, verbose 计时):
| 阶段 | 耗时 | 性质 |
|---|---|---|
| Processing(pip 启动+读 sdist) | 24s | 解释器启动+import(重编译) |
| Preparing metadata(fork setup.py) | ~18s | 子进程重编译 stdlib |
| Building wheel(fork setup.py) | ~17s | 子进程重编译 stdlib |
| Installing | ~4s | IO |

`sys` 时间仅 1.78s → **不是 IO 瓶颈,是纯 CPU(user 70s)**,理论上可优化。

---

## 2. 最终端到端数据表(实测,best of 多次)

| 配置 | real 秒数 | 说明 |
|---|---|---|
| **iSH cold(无 pyc)** | **72.0–72.86s** | 之前基线,每子进程重编译 |
| **iSH warm(预编译 pyc)** | **25.3–25.5s** | 落地本方案后 |
| **Docker(镜像自带 pyc)** | **1.0–1.1s** | 硬件虚拟化 + 出厂 pyc |

公平 A/B(两边都有 pyc):
- iSH warm 25.5s vs Docker 1.0s = **26×**
- 之前 cold 对 Docker(不公平,iSH 无 pyc)= **72×**
- 仅"补齐 pyc"这一项,就把不公平的 72× 拉到公平的 26×

---

## 3. 端到端提升

**iSH cold 72.0s → iSH warm 25.5s = 提升 65%(2.82×)。**

**≥30% KPI:已达成(65% ≫ 30%)。** 且是真实端到端 wall-clock,pyyaml 正确装出
(`site_target/yaml` + `_yaml`)。

---

## 4. 落地方案(可交付)

### 脚本
`tools/rootfs/precompile_pyc.sh`(已创建,已验证):
```
tools/rootfs/precompile_pyc.sh <ish-binary> <rootfs> [python-libdir]
```
- 用 **guest python**(通过 ish 二进制)跑 `compileall`,保证 `.pyc` 字节码
  magic 与 guest 解释器完全一致(不能用 host python 编译)。
- `invalidation_mode=UNCHECKED_HASH`:无 mtime 依赖,rootfs 复制/打包后仍有效。
- `workers=1`:iSH 不支持 multiprocessing 信号量(workers=0 会 FileNotFoundError)。

### 一次性成本
构建时跑一次:**57s 生成 1407 个 .pyc**(和 Docker 镜像构建时做的完全一样)。
此后每次 `pip install`(及任何 python 子进程负载)都受益。

### 挂进 rootfs 构建流程
在打包 alpine rootfs 的最后一步、python 装好之后加:
```bash
tools/rootfs/precompile_pyc.sh "$ISH_BIN" "$ROOTFS_DIR" /usr/lib/python3.12
```
产物 `.pyc` 随 rootfs 一起分发。等价于 Dockerfile 里的
`RUN python -m compileall /usr/lib/python3.12`。

---

## 5. 第二层 offload 计划清单(pyc 之后剩余 25.5s 的构成)

warm profile(pyc 已有,4.9B 指令)剩余热点:

| 热点 | 占比 | 可 offload? |
|---|---|---|
| `_PyEval_EvalFrameDefault` | 19.2% | ✗ 解释器循环,内联片段非独立函数 |
| musl malloc 内部 | 10.4% | ✗ spec 死锁(malloc 被 iSH 核心自身调用) |
| **GC 簇**(collect_main/is_finalized/move_unreachable/traverse/freeze) | ~14% | △ 见下 |
| **tuple 生命周期**(tupledealloc 2.5% + tuple_alloc 2.0% + tupletraverse 1.5%) | ~6% | △ 调 malloc/GC |
| PyLong/type alloc/attr lookup | ~4% | ✗ 调 malloc/多态 |

### 已试 & 结论
- **GC 阈值调高**(`gc.set_threshold(7000,100,100)`):warm 25.3→24.7s = **+2%**。
  安全(不改正确性,只移回收时机)。可作为 sitecustomize 交付,但收益小。
- **`gc.disable()`**(实验上限):72.86→69.1s = **仅 5%**。说明 GC 的"多余循环回收"
  只占 5%,profile 里 GC 14% 大部分是遍历本身(对象图必须建/毁),不可省。
- **GC 遍历簇 spec 化**:翻译了 13 个(traverse+visit),但 **mutually-recursive
  多态调用图**——单个能过,组合起来 GC 结果发散(bit-identical 失败)。已回退。
  这是 spec 机制的根本限制(递归 fallback 破坏状态)。
- **339 个已有 spec 在 warm 下叠加**:offload ON vs OFF ≈ 持平(25.3 vs 25.5,噪声内)。
  说明这些 spec 命中的 hash/dict/字符串在 pip 里占比太小,warm 场景不是它们的主场。

### `_PyEval` / malloc 为何架构性难 offload
- `_PyEval_EvalFrameDefault`:19% 是编译进一个巨型函数(40KB/1万指令)的**内联
  引用计数 + opcode 派发片段**,不是独立函数。spec 只能替换整函数入口,碰不到
  内联片段。已试引擎级 DECREF 融合 gadget(gen.c peephole):微基准 1.09× 但
  pip install 无效——因为 pip 对象即用即弃,refcnt 频繁 1→0 走 dealloc 路径,
  而融合只加速 N→N-1 不归零的情况。
- malloc:被 iSH 核心自身(JIT block 编译的页表 calloc)调用,spec 走 prebuilt_call
  会在 asbestos 锁持有时重入 JIT → 死锁。只能在 iSH 引擎层 hook,非 spec 层。

### 剩余可撬动的真正杠杆(均为 iSH 引擎级,超出指令级 offload)
1. **host-compile**:把 `compile()` 整体搬宿主原生 CPython(第一层 pyc 已经消除了
   大部分重复编译;host-compile 针对首次编译,收益已被 pyc 覆盖大半)。
2. **guest 寄存器提升**:所有 guest 寄存器现在在 `cpu->regs[]` 内存,每次访问 =
   ldr/str。纯寄存器循环实测 41× 慢,大头是这个访存。提升到 host 寄存器需重写
   所有 gadget + gen.c,是最大但最难的杠杆。

---

## 结论
- **第一层 pyc 预编译:端到端 72.0s→25.5s = 65% 提升,已达成 ≥30% KPI,已落地脚本。**
- 第二层(GC 阈值 +2%、tuple/GC 簇)收益小或 spec 不友好;真正的第二层大头
  (_PyEval 19% + malloc 10%)是 iSH threaded-code 的架构性开销,需引擎级改造。

---

## 第二层进展 (追加)

### INCREF 融合 gadget (LOAD_FAST 热路径)
gen.c peephole 融合 CPython 内联 Py_INCREF 4 指令序列
(`ldr Wr,[Xobj]; adds Wr,#1; b.eq skip; str Wr,[Xobj]`)成一个 gadget_incref。
两条路径都 fall-through(immortal 情况跳过写回,非 immortal 写回),无分支出块。
静态计数:EvalFrame 里 INCREF 模式 47 处。

- **正确性: bit-identical** ✓(LOAD_FAST churn / getrefcount 稳定 / 对象生命周期 /
  GC / json 全部与 INCREF OFF 一致)。
- **真实端到端 (warm pip install pyyaml, best of 3):**
  | | 中位 real |
  |---|---|
  | INCREF OFF | 25.4s |
  | INCREF ON | 25.2s |
  - **收益 ~0.8%(25.4→25.2s),真实但极小。**

### 为什么 INCREF/DECREF 融合在 pip 上收益微小
pyc 消除了重复编译后,pip 剩余 25s 的大头是 `_PyEval_EvalFrameDefault` 的**整体
opcode 派发 + malloc + GC**,INCREF/DECREF 只是解释器里的一小片(各 ~1-2%)。
融合省掉的是"4 条 guest 指令 → 1 gadget"的派发,但即使全省,占比也太小。

### 第二层的诚实结论
- 第一层 pyc:**65%**(决定性,已达标)。
- 第二层指令级融合(INCREF/DECREF):合计 pip 上 ~1%,微基准才显著。
- 真正的第二层大头(_PyEval 派发 19% + malloc 10% + GC 14%)是 threaded-code
  架构性开销,指令级 peephole 撬不动——需 iSH 引擎级寄存器提升或换 JIT 引擎。
- **INCREF 融合是通用、安全、正确的纯增量**(引用计数型运行时都受益),保留;
  但对 pip install KPI 的贡献可忽略。第一层 pyc 才是 KPI 的答案。

---

## 通用方向：编译 offload (补 pyc 预编译的短板)

### (1) 问题：pyc 预编译不通用
第一层 pyc 预编译(-65%)只覆盖 **rootfs 出厂的 stdlib**。用户 `pip install` 任意
第三方源码包(sdist)后,**首次 import 仍要 cold-compile 该包的 .py 源码**,而 iSH
软件 JIT 里 `compile()` 比 host 原生慢 **~29-43×**。这个"首次编译"痛点对任意包都存在,
pyc 预编译覆盖不到。

量化(实测):
- `compile()` 本身: iSH 272ms vs Docker 8.8ms = **31×**(argparse.py 单文件)。
- 真实大包: rich 全包(77 文件 / 2.6 万行)编译, iSH 2805ms vs Docker 97ms = **29×**。
  → 用户装 django / pandas 等大包,首次 import 编译开销达几秒~几十秒。

### (2) 方案：compile offload
把 CPython 的 `compile()`(tokenize→parse→symtable→codegen→marshal)整段 offload 到
**host 原生 CPython 3.12** 执行。它是纯 CPU、确定性、无副作用的 data→data 变换
(源码字符串 in / marshal 字节流 out),边界干净,无对象地址空间问题。

- **拦截点**: `importlib._bootstrap_external.SourceFileLoader.source_to_code`
  —— `import` 和 `py_compile`/`compileall` 都走它,单一 chokepoint。
- **通用注入**: `sitecustomize.py`(每个 python 进程启动自动加载,含 pip fork 的
  metadata / wheel-build 子进程),覆盖全部子进程,无需改 pip。
- 流程: hook 把源码送 host → host CPython 编译 + marshal → 字节流回 guest →
  guest `marshal.loads` 得 code object。
- **三层无损 fallback**: host 不可用 / 版本不符 / 编译异常 → guest 自编译
  (保留精确错误语义)。已缓存 .pyc 不触发(直接 loads),hook 只在首次 compile 生效。

### (3) 性能与正确性(三级 PoC,全部实测通过 ✅)

| 层级 | 实测 |
|---|---|
| host 编译 vs guest 编译(收益上限) | rich 全包 62ms vs 2700ms = **43×** |
| 端到端·文件通道(批量直调) | 2728ms → 224ms = **12.2×** |
| 端到端·source_to_code hook(文件通道) | 2641ms → 2249ms = **1.17×**(通道受限) |
| **in-process 内嵌 libpython** | **13.6 µs/call**(比文件通道快 ~100×,比 guest 编译快 ~35×) |

**正确性 bit-identical(实测):**
- 版本/magic 完全对齐: guest(iSH) / host(macOS) / Docker(linux) python **全部
  3.12.13, marshal magic 全部 `cb0d0d0a`**。
- host 编译的 code object: **co_code(实际字节码)逐字节相同、co_names/co_consts/
  深度递归签名完全相同**;唯一差异是 marshal 的 FLAG_REF 引用压缩位(序列化表示,
  非字节码差异),`marshal.loads` 后得到语义完全一致的 code object。
- host 编译字节码 → guest exec: **MATCH: True**(多例验证,结果与 guest 自编译一致)。
- 前提: `PYTHONHASHSEED` 一致(影响 frozenset/set 字面量元素顺序)。

### (4) pip install 源码包端到端 on/off 秒数
**待测。** 已有的 rich 编译 A/B(source_to_code hook 文件通道)是 1.17× 端到端;
真正的 `pip install rich` on/off 端到端秒数、以及内嵌 libpython 版本的端到端数字
**尚未测**(内嵌方案未落地进 iSH,仅有独立 C PoC 13.6µs/call)。落地后需补测。

### (5) 落地路线：in-process 内嵌 libpython3.12
**架构**(已由独立 C PoC 验证 13.6µs/call 可行):
1. iSH 内新增 `kernel/native_offload_pycompile.c`:
   - `Py_Initialize()` **只一次**(锁保护,懒初始化,**永不 Py_Finalize**——解释器
     复用,摊平 init 成本,这是逼近 µs 级的关键)。
   - 暴露 `ish_host_compile(src, src_len, filename, filename_len, out, out_cap,
     *needed) → bytes_written`:`Py_CompileString` + `PyMarshal_WriteObjectToString`,
     写 marshal 字节流回 guest 内存(via `nsym_write`)。
2. 通道 = **symbol offload**(复用现有 `native_offload_add_symbol` + `nsym_read/
   nsym_write` value-copy guest 内存,fork-safe),零 IPC、零文件轮询。
3. guest 侧 `sitecustomize.py` hook `source_to_code`,ctypes 直调 stub symbol。
4. 链接: vendored `_offload_poc/frameworks/Python.xcframework`(iOS slice)/
   host `libpython3.12.dylib`(macOS CLI)。GIL 每次 compile 持有一次。

**版本约束(硬性)**: 内嵌的 host CPython **必须与 guest 完全一致 3.12.13 +
magic cb0d0d0a**,否则字节码不兼容。已确认 vendored framework 与 guest rootfs 同版本。

**待解决项:**
- **exception 处理**: 文件通道 PoC 里部分文件编译"失败"(77→41),需查是 daemon
  的 exception 序列化问题还是编译真失败;正式版必须对语法错误精确 fallback 到
  guest 编译(保留正确的 SyntaxError 行号/消息)。
- **IPC 方式**: 已否决文件轮询(慢+竞态);采用 symbol-offload 的 value-copy 通道
  (in-process,无 IPC)。多 guest 线程并发 compile 需串行化 GIL 或每线程子解释器。
- **GIL/线程**: 内嵌解释器的 GIL 与 iSH 线程模型交互需正确管理。

### (6) 结论
**compile offload 是补齐 pyc 预编译"只覆盖出厂 stdlib"短板的通用优化**——对任意
第三方源码包的首次 import/编译都生效。可行性、bit-identical 正确性、性能上限
(29-43×,in-process 13.6µs/call)均已三级 PoC 实测验证。落地内嵌 libpython 后,
预期对任意源码包 `pip install` 的端到端首次编译显著加速(补上 pyc 覆盖不到的部分)。
剩余为工程落地(内嵌 daemon + exception fallback + 端到端实测)。

---

## 通用方向二：AOT 预翻译 libpython —— 已实测证伪 ❌

### 假设
把 iSH JIT 运行时"逐块翻译 libpython"的开销，用静态 AOT（离线把整个 libpython
代码段逐指令翻译成 host gadget 序列）消除掉，让 libpython 整体跑得更快。

### 决定性实测（在 fiber_block_compile 加计时探针 ISH_JIT_TIMING）
| 负载 | total real | JIT 翻译绝对时间 | 翻译块数 | 翻译占比 |
|---|---|---|---|---|
| compile argparse.py | 880ms | **12.56ms** | 59,964 | **1.4%** |
| import 8 大模块 | 830ms | **11.06ms** | 88,808 | **1.3%** |

### 结论：证伪
- iSH 的块编译器**本身极快**：59,964 块只花 12.56ms = **0.2µs/块**。翻译是一次性的。
- 即使 AOT 把运行时翻译**完全降到 0**，compile argparse 也只 880→868ms = **~1.4% 上限**。
- 慢的大头（93-98%）是**翻译后的 gadget 序列执行本身**：每个 guest 寄存器访问走
  `cpu->regs[]` 内存 ldr/str（threaded-code + 内存驻留寄存器），不是"翻译动作"。
- AOT 消除翻译动作，产出的还是**同一套走内存的 gadget**，执行速度不变 → 不值得做。
- 这与本文第 130-135 行早有的判断一致：真正的杠杆是**执行模型**（guest 寄存器提升
  / 换 JIT 引擎），不是翻译时机。间接分支（br/blr：opcode dispatch/PLT/函数指针）
  也让纯静态全翻译不可判定，必须 AOT+运行时 fallback 混合，进一步压低收益。

---

## 通用方向三：guest 寄存器提升到 host 寄存器（进行中）

### 依据
本文第 135 行：guest 寄存器全在 `cpu->regs[]` 内存，每次访问 = ldr/str，纯寄存器
循环实测 **41× 慢**，大头是这个访存。AOT 证伪后，这是剩下真正能撬动执行模型的杠杆。

### 现状（已摸清 gadget 架构）
- iSH ARM64 是 **threaded-code**：每条 guest 指令 = 一个独立 gadget，`gret` 派发到下一个。
- 当前寄存器映射（gadgets.h）：`_cpu=x1  _tlb=x2  _pc=x28`；scratch=x0/x7/x8/x9-x15。
- **host x19-x27 是 callee-saved、entry.S 已 save/restore（第 40-45 行），当前除 x28
  外未用于 guest 状态** → 有 **9 个空闲 host 寄存器**可pin guest x0-x8（最热的低寄存器）。
- gadget 是共享代码，无法感知 per-block 分配 → PoC 采用**全局固定 pin**：guest xN → host
  x(19+N)，让 load_reg/store_reg/算术 gadget 命中固定索引时直接读写 host 寄存器。
- 跨 gadget 存活：x19-x27 callee-saved，gret 不破坏 → pin 值能在 gadget 间存活。

### PoC 计划（量化真实加速比，再决定是否全面重写）
1. 选 guest x0-x8 pin 到 host x19-x27（9 个）。
2. 改 load_reg/store_reg：命中 0-8 直接 mov host 寄存器，否则走内存旧路。
3. gret/entry.S/syscall/signal 边界：guest 内存镜像与 pin 寄存器同步（进/出边界 spill/fill）。
4. 纯寄存器微基准 + compile argparse 端到端 A/B，量化真实加速；bit-identical 校验。

### 收益上限实测（隔离 guest 寄存器访存）
| 微基准 | iSH | native | iSH/native |
|---|---|---|---|
| 纯 guest 寄存器 asm 循环（8 insn/iter，全走 cpu->regs[]） | 596ms | 10.3ms | **57.9×** |
| -O1 C 循环（变量在 guest 寄存器） | 0.46s | 0.08s | 5.75× |
| -O0 C 循环（变量 spill 到 guest 栈=TLB） | 2.45s | 0.20s | 12.3× |

`sample` 剖析纯寄存器循环，host 时间全在算术 gadget（gadget_madd/add_reg_64_nshift/
eor_reg_64_nshift/…），无系统调用。

### 关键发现：gen.c 已按指令形状发射“特化 gadget”
纯寄存器 add 走的是 `gadget_add_reg_64_nshift`（11 条 host 指令）：
```
ldr x8,[_pc]; add _pc,#8;              // 取码流操作数
and/ubfx ×3                            // 解码 rd/rn/rm       (5 条)
add x14,_cpu,#CPU_x0                   //
ldr x15,[x14,rn]; ldr x16,[x14,rm]     // ← cpu->regs[] 访存 (4 条, 提升要消除的)
str x17,[x14,rd]                       //
add x17,x15,x16                        // 真正的活          (1 条)
gret (ldr+br)                          // 派发             (2 条)
```
其中 **4/11 是 cpu->regs[] 访存**（提升可消除），1/11 是真正的算术。gen.c 发射位点
在 gen.c:3657（`gen(add_reg_64_nshift); gen(rd|rn<<8|rm<<16)`）。

### PoC 设计（选定）
- host x19-x27 callee-saved 且 entry.S 已 save/restore（第 40-45 行），当前仅 x28=_pc
  占用 → **9 个空闲寄存器**，pin guest x0-x8。
- gen.c 在 rd/rn/rm 全落在 pin 集时，发射 `*_pinned` 特化 gadget：直接 `add x<19+rd>,
  x<19+rn>,x<19+rm>; gret`，**零访存、零解码分支**（索引编译期定死）。
- 边界同步：entry.S 进入时把 cpu->regs[0..8] fill 进 x19-x27，退出/syscall/signal/
  prebuilt_call/nsym 边界前 spill 回 cpu->regs[]（保持 value-copy 语义与正确性）。
- 先只对 add/sub/eor/and/orr_reg_64_nshift 五个热 gadget 做 pinned 变体，量化纯寄存器
  循环从 57.9× 降到多少；bit-identical 校验后再决定是否扩展到全指令集。

### 逐指令成本分解（进一步隔离，决定 pinning 真实收益）
| 微基准 | iSH | native | ns/guest-insn (iSH) | iSH/native |
|---|---|---|---|---|
| 纯算术 8 insn/iter（add/eor/mul…） | 596ms/8e7 | — | **7.45 ns** | 57.9× |
| 纯分支 2 insn/iter（sub_imm+cbnz） | 572ms/2e7 | 2.5ms | **28.6 ns** | 229× |

**关键分解**：
- **算术 gadget ≈ 7.45 ns/insn**。`add_reg_64_nshift` 是 11 条 host 指令，其中 4 条是
  cpu->regs[] 访存（pin 可消除）、1 条真算术、~5 条解码、2 条 gret 派发。pin 消除访存
  → 约 7/11 时间 → **纯算术理论 ~1.5× 加速**。
- **cbnz/分支 gadget ≈ 28.6 ns/insn**（4× 于算术！）——含 block-chaining 检查 + poke
  检查 + 周期计数。**这才是纯寄存器循环的真正大头**，且 pin **管不到**（是派发/链路开销）。

### 重要修正：pinning 的天花板比预想低
纯寄存器循环 57.9× 里，很大一块是 **gret 派发 + 分支链路**（cbnz 28.6ns 是算术的 4×），
而非 cpu->regs[] 访存。pin 只能削掉算术 gadget 的 4/11 访存指令 → 纯算术约 1.5×，但一旦
循环里有分支（真实代码必然有），分支的 28.6ns 派发开销 pin 碰不到，端到端会被稀释到远
低于 1.5×。**这解释了为何 doc 前文 INCREF 融合（也是削 gadget 指令数）在 pip 上只有
~1%**：threaded-code 的大头是"每条 guest 指令一次 gret 派发"，不是单个 gadget 内部多几条访存。

### 诚实结论（寄存器提升方向）
- **真正的大头是 threaded-code 派发本身（每 guest 指令一次 gret + 分支链路检查），不是
  寄存器访存**。pin 寄存器只削单 gadget 内部访存，天花板 ~1.5×（纯算术）、真实混合负载
  远更低——与 INCREF 融合的 ~1% 同源。
- 要真正撬动 57.9×，需消除的是**每指令派发**（→ basic-block 级编译/寄存器分配，即真正
  的 JIT 而非 threaded-code），而非在 threaded-code 框架内 pin 寄存器。这是重写 JIT 引擎
  级的工作量。
- **pinning PoC 不再单独落地**：其收益已被上述成本分解证明上限 ~1.5×/真实更低，且与已交付
  的 INCREF 融合同类、同量级。

---

## 通用方向四：basic-block JIT —— PoC 实测成功 ✅（7.1× → 原生速度）

### threaded-code vs basic-block JIT（架构差别）
- **threaded-code（iSH 现状）**：每条 guest 指令 = 一个共享 gadget + `gret` 派发。
  `add x10,x10,x11` → `gadget_add_reg_64_nshift` 共 **12 条 host 指令**（取码流1 + 解码3 +
  算 cpu->regs 基址1 + load 两操作数2 + 真加法1 + store 结果1 + gret 派发2）。只有 1/12 是真活。
- **basic-block JIT**：整个基本块编译成**一段连续 host 码**，块内寄存器分配（guest 寄存器
  提升到 host 寄存器，块内不碰内存），无每指令 gret。`add x10,x10,x11` → **1 条 host 指令**。

### PoC 实现（最小、gated、可 A/B）
- 复用现有 prebuilt-gadget 通道（`gadget_prebuilt_entry` 调 native spec_fn，resume 于 LR）。
- `kernel/offload_tests/prebuilt/spec_bbjit_poc.c`：把热基本块（8 条 guest 指令的纯寄存器
  循环）整块跑成一个 native C 函数——guest 寄存器读进 C 局部（= host 寄存器），整循环在
  host 寄存器里跑，写回 cpu->regs，并把 LR 改写成 fall-through PC 让 prebuilt_entry 正确 resume。
  这就是 basic-block JIT 的上限形态（host C 编译器做寄存器分配 + 消除派发）。
- gated：仅 `-Doffload_test_prebuilt=true` 编译，且需 `ISH_BBJIT_BASE=0x…`（PIE 载入基址）才注册。

### 实测（同一热循环 /tmp/al2 main+0x50，8 insn/iter，N=3e7）
| 引擎 | net loop | vs native |
|---|---|---|
| **threaded-code**（iSH 现状） | 219.4ms | **7.1× 慢** |
| **basic-block JIT**（本 PoC） | **31.0ms** | **1.0×（原生速度）** |
| native（host arm64） | 31.1ms | 1× |

- **basic-block JIT 比 threaded-code 快 7.1×，直接拉到原生速度。**
- **bit-identical 已验证**：非平凡 64-bit 校验和 `r=17293497113660882944` 两引擎完全一致。
- 首次命中日志确认 offload 生效：`[offload:prebuilt] first hit: al2:bbjit_loop @ effdd7b0`。

### 意义与代价
- 证明了：threaded-code 的 57.9× 慢度大头（每指令派发 + cpu->regs[] 访存 + 解码）确实靠
  basic-block 级编译 + 寄存器分配能消除干净。**这是唯一被数据证明能真正撬动瓶颈的方向。**
- 本 PoC 是**手写单块**的上限证明；要落地成通用引擎需：
  1. **RWX 代码缓冲**：iSH 现在的“JIT”块是 gadget 指针数组（数据），不发射 host 机器码。
     真 JIT 需 `MAP_JIT` + `pthread_jit_write_protect_np`（Apple Silicon）+ icache flush。
  2. **指令选择 + 块内寄存器分配器**（guest→host 寄存器映射，spill/fill 在块边界）。
  3. **边界一致性**：syscall/signal/fork-CoW/TLB-flush/self-modifying-code 时寄存器与 cpu->regs
     同步（与前述寄存器提升同类问题，但因收益 7× 而非 1.5×，值得投入）。
  这是 QEMU TCG / V8 baseline 级别的工作量，但收益（纯计算 7×、混合负载显著）远超前三条路。

### ⚠️ 关键约束更正：iOS 上架 app 禁 MAP_JIT → 运行时 JIT 不可行
- App Store 普通 app **不允许 MAP_JIT / RWX 内存**（仅 `com.apple.security.cs.allow-jit`
  特权 entitlement，给浏览器，普通 app 拿不到）。这正是 **iSH 本身选 threaded-code 而非
  真 JIT 的根本原因**——块是 gadget 指针数组（纯数据），不发射 host 机器码，才能合规上架。
- **所以上面 basic-block JIT 的“通用引擎形态”（运行时发射 host 码 + RWX 缓冲）在 iOS
  上架 app 里不可行。** 之前列的落地路线 (1) RWX 代码缓冲这一步是违规的，作废。
- **但 PoC 的 7× 收益并不依赖运行时 RWX**：PoC 用的是 **AOT 编译进 iSH 二进制的 native
  spec_fn**（`spec_bbjit_poc.c` 编译期即 host 机器码，在合法 `__TEXT` 段）。host 机器码是
  **编译时**产生的，运行时零 RWX、纯查表跳转 → **完全合规**。
- **正确的落地路线 = AOT**：离线用 host 编译器把 libpython 的热函数/热基本块编译成
  basic-block-JIT 风格 spec_fn（寄存器提升 + 无 per-insn 派发），静态链进 iSH。这正是现有
  `translate.py` + prebuilt-gadget 机制的目标。之前“AOT 只省 1.4%”的证伪只否定了“消除翻译
  动作”，PoC 证明真正收益来源是“整块编译到 host 寄存器”的 7×——这条路 iOS 合规且收益成立。

### 下一步：AOT basic-block 翻译可行性边界评估（进行中）
量化真实 libpython 热点函数里，能整块 AOT 到 host 寄存器（纯计算/无 bl-blr/无 GC）拿到 7×
的覆盖率，vs 卡在间接调用/malloc/GC 的比例。用覆盖率数据决定投入。

---

## 独立 guest C PoC：真实 libpython 叶子 _PyToken_TwoChars 的 AOT offload ✅

### 目标
澄清后的 PoC：一个在 **iSH guest 里运行**的独立 C 程序（aarch64-musl，链 guest
libpython），调用真实 lib 方法 `_PyToken_TwoChars(int,int)`，A/B 对比：
- **A** = threaded-code（iSH 正常翻译该 libpython 函数）
- **B** = translate.py 生成的 native spec_fn（prebuilt-gadget offload）
验证加速比 + bit-identical。

### 选函数：_PyToken_TwoChars（file offset 0x108780，105 条指令）
纯计算叶子、**零外部 bl/blr**，唯一控制流是一个**函数内跳转表**（tokenizer 的
operator switch：`!= %= &= ** += -> // := << == >> ^= |=` 等）。

### 关键工程产出：translate.py 三个真实缺陷修复
1. **adrp/adr 目标解析**：objdump 打印裸 hex（`2b4000`）无 `0x` 前缀，正则漏匹配 → UNSUPPORTED。
2. **`//` 注释污染操作数**：`csel …, ne  // ne = any` 把条件码带上注释 → COND 查表失败。
3. **函数内跳转表（核心）**：`adrp+add(表基)→ldrb→adr(基label)→add sxtb#2→br x2` 惯用法。
   translate.py 原把 `br xN` 当**尾调用**译成 `regs[30]=target; return` —— 对**函数内**
   跳转表这是**错的**：它 clobber LR，随后分支体的 `ret` 返回到跳转目标而非调用者 → **死循环**。
   修复：新增 JUMPTABLE_TARGETS/MAP/SUPPRESS，解析 .rodata 表字节（guest `od` 读出），
   在各目标发射 label，把 `br` 译成真正的 **C `switch`**，并抑制跳转表构建前缀指令（保住索引
   寄存器）。这样整个函数留在 host 代码里（真正的 basic-block AOT），而非半途 return。

### 实测（iSH guest 内，链 guest libpython，bit-identical 全部通过）
| workload | A threaded-code | B spec_fn(AOT) | 加速 | 校验和一致 |
|---|---|---|---|---|
| 全 128×128 输入对 ×200k | 47375ms | （命中生效） | — | ✓ 588239677739455296 |
| 热路径（14 operator 首字符 ×3M） | **929ms** | **556.5ms** | **1.67×** | ✓ 11815502761498149824 |
| 短循环校验 | 474ms | 461.6ms | 1.03× | ✓ 17853955447640872272 |

首次命中：`[offload:prebuilt] first hit: libpython3.12.so.1.0:_PyToken_TwoChars @ efa6c780`。

### 结论：AOT offload 对真实 lib 叶子有效，但加速幅度取决于函数形状
- **正确性 bit-identical、机制打通**：translate.py 现能整块 AOT 一个含跳转表的真实
  libpython 叶子成 host `switch`，iSH guest 里命中生效、结果逐位一致。
- **加速 1.67×（热路径），不是 7×**。原因：`_PyToken_TwoChars` 每次调用只几条指令，开销
  被 **调用边界**（bl/ret + prebuilt 跳板 save_c/restore_c）而非内部循环主导。**7× 只在
  函数含内部热循环时出现**（al2 PoC 那种）。→ AOT offload 的收益 = f(函数内计算量 / 调用
  次数)：循环密集函数收益大，小叶子被调用开销摊薄。
- **对 iOS 合规**：spec_fn 是 AOT 编译进 iSH `__TEXT` 的 host 码，运行时零 RWX/MAP_JIT。
- **落地判据**：要对 pip/compile 端到端有感，需 offload 的是**含内循环的热函数**（codegen/
  parser 的大循环、siphash 核），而非 _PyToken_TwoChars 这类每调用几条指令的小叶子。

---

## 全翻译 libpython 实验:阶段一(翻译+编译）✅ 82% 函数、100% 编译

用户提出"整个 libpython 翻译掉"。先澄清一个此前的错误表述：`bl`/`blr` **不影响运行
逻辑**——AOT 后调用边界仍由 `prebuilt_call`/`PB_CALL` 完整保持 guest 语义（目标译了就
host 调 host，没译就掉回 threaded-code 跑，结果一致）。所以正确性可**逐函数独立保证**，
不存在"组合爆炸"来自调用——组合误差只可能来自单函数内某条指令译错。

### 批量翻译全部 1897 个 libpython 函数
| 阶段 | 翻译成功 | 编译成功 | 覆盖指令 |
|---|---|---|---|
| 起点 | 68.4% (1297) | ~90% | 25% |
| **修 6 个 translate.py 缺陷后** | **82.3% (1562)** | **100% (1562/1562)** | **43.9%** |

### 修复的 translate.py 真实缺陷（都是通用修复，非一次性）
1. adrp/adr 目标裸 hex 无 `0x` 前缀 → 正则漏匹配。
2. `//` 注释污染操作数（csel 条件码等）。
3. 函数内跳转表 `br xN` → 解析 .rodata 表、发射 C `switch`（原误当尾调用 clobber LR）。
4. `mrs/msr tpidr_el0` objdump 小写，原代码查大写 → 411 处栈保护读全失败（最大单一阻塞）。
5. 补标量指令 `ccmn / clz / rev / rev16 / ldpsw`。
6. 向量寄存器 `ldr/str/ldp/stp q…` 原静默生成 `regs[None]`（编译期才炸）→ 改为正确 bail
   到 UNSUPPORTED。这把"假成功"剔除，成功率数字变诚实。

### 结论（阶段一）
- **82% 的 libpython 函数能自动整块 AOT 成合法、可编译的 host C**（1562 个 spec_fn 翻译+
  编译 100% 通过）。"全翻译"在翻译+编译层面**可行**。
- 剩 18%（335 函数、56% 指令）几乎全卡在 **SIMD/NEON**（memcpy/memset/unicode 向量化 +
  _PyEval 零散向量）。能补，但需建向量寄存器文件 + 逐条 NEON 语义，工作量大。
- **未验证**：正确性（逐函数 bit-identical 对拍）+ 端到端加速。翻译能编译 ≠ 语义正确 ≠
  更快。下一阶段：批量注册 + 逐函数对拍 + 真实负载 A/B。

---

## 全翻译 libpython 实验：阶段二（端到端注册运行）——决定性负面结果 ❌

把 1192 个可翻译+可编译的 spec_fn 全部注册进 iSH（PREBUILT_MAX 32→4096），跑真实
compile argparse 的 A/B。结果暴露三个决定性问题：

### (1) 一大类函数根本不能 offload（架构性，非译错）
全注册后 **python 启动即死锁**。bisect 定位到 `PyMem_RawMalloc`（第 495 个）——doc
前文早有的警告成真：**allocator 族被 iSH 核心自身在持 asbestos 锁时调用，offload
→ 重入 JIT → 死锁**。加黑名单（PyMem_Raw*/PyMem_*/PyObject_*alloc 共 16 个）后继续。

### (2) 间接 br 尾调用被误译（translate.py 真 bug，已修）
下一个死锁是 `PyObject_Hash`。根因：`br x16`（间接尾调用到 tp_hash）被译成
`regs[30]=x16; return`——**clobber 了刚从栈恢复的真实 LR**，callee 的 ret 回到自己 →
死循环。**1192 个里有 118 个（10%）中招**。修复：`br xN` 尾调用改译
`prebuilt_call(cpu,tlb,regs[N]); return;`（跑完 callee 再 return 到真 LR）。

### (3) 修完仍发散 + 几乎不命中——这才是致命的
修完上面两类后继续 bisect，`_Py_hashtable_set`（第 502）等**核心运行时函数一个接一个**
出问题（死锁或结果错）。取 bisect 已知稳定的前 494 个函数注册，跑 compile：
| | compile argparse ×3 | 结果校验和 |
|---|---|---|
| A threaded-code | 758ms | `4317705937395975924` |
| B fulltrans(494) | **765ms（+1% 更慢）** | `-4166955842942227591`（**不一致！**） |

- **正确性发散**：494 个"能启动"的函数里仍有译错的，compile 输出已与 threaded-code 不同。
- **几乎不命中**：494 个注册函数，compile 时只命中 **2 个**——热点（_PyEval/malloc/GC）全在
  黑名单或崩溃批里。所以注册再多，对这个负载也没有加速，反因 prebuilt 跳板开销 +1% 更慢。

### 结论：全翻译在真实运行层面不可行（三重壁垒）
1. **核心运行时（malloc/GC/refcount/hashtable 族）不能 offload**——被 emulator 自身持锁调用，
   重入死锁。而它们恰是执行热点。offload 它们=死锁,不 offload 它们=没加速。
2. **组合 bit-identical 发散**：单函数即使能编译，成百上千个组合起来，任一指令语义边角
   译错就破坏全局结果。逐函数对拍能抓，但工作量随函数数线性爆炸，且核心函数最易错。
3. **收益/命中错配**：能安全 offload 的（纯计算叶子）恰是执行占比最小的；执行热点恰是
   最不能/最难 offload 的（间接派发 + malloc + GC）。这与本文全篇一致：iSH 的瓶颈是
   threaded-code 派发 + 核心运行时开销，不是"某些函数没译成 host 码"。

**最终判断**：AOT 全翻译 libpython 技术上能生成 82% 函数的可编译 host C，但运行层面被
"核心运行时不可 offload + 组合发散 + 收益错配"三重壁垒挡死。**正确的落地仍是精准 offload
含内循环、无 malloc/GC/间接派发的纯计算热函数**（siphash 核、unicode/bytes 批处理循环），
而非全译。第一层 pyc 预编译（-65%）仍是唯一已交付的决定性优化。
