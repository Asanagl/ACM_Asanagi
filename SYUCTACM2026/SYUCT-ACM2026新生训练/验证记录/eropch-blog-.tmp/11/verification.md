# 11 验证记录（普通验证模式）

- requested_mode: null
- effective_mode: normal（用户未指定模式，按普通验证模式执行）
- 题目：编号 11，中文题名《矩阵原样输出》
- config slug：`04-11`
- 冻结题面 SHA-256：`c676811aa779979f3f9939367115a8fe4323cacb0f418ad4d145e8f7e856865b`
- 技术栈：gnu++17 / 1000 ms / 256 MiB；与 weekly-01 样例共用同一份 `include/testlib.h`（SHA-256 `26facaf1…fb1b90`）

## 盲审

- 盲审模型（显式指定）：`wb2api/deepseek-v4.1-flash`
- 调用方式：全新非交互会话，`--skills-dir` 指向空的 `no-skills` 目录
- 提示文件：`blind/prompt-v2.md`（与最终题面逐字一致），只包含冻结公开题面全文、全部约束、三个样例、唯一输出 Judge 语义和资源限制；不含工作区路径、主解思路、生成器、数据或错解
- 原始回答：`blind/response-v2.txt`；会话日志：`blind/stderr-v2.log`
- 独立性核验：会话 `session_41bc7bc4-fb5d-4699-8c73-b5c3447c91dc` 的 wire 记录中，模型绑定为 `wb2api/deepseek-v4.1-flash`；唯一的 `llm.request` 与 `turn.prompt` 中均未出现 `eropch`、`problemsets`、`weekly-04`、`.tmp` 或 `C:\Users` 等本机信息；整轮只产生一次 LLM 请求，无工具调用记录
- 结论：盲审独立复述任务（含 1 行、1 列、1×1、负数、0、重复元素、±1000 边界）并给出「逐元素读入即输出、列号决定补空格还是换行」的算法，时间 Θ(nm)、额外空间 O(1)，证明覆盖“每元素恰输出一次、位置/数值/符号不变”。主代理逐行审查其 C++17 实现，未发现缺陷，无实质分歧；该实现已作为 `src/solution2.cpp`。

## 对拍

- 脚本：`stress.py`，固定种子 12345
- 两条通道合计 240 轮，实测 `rounds_requested=240 rounds_passed=240 failures=0`
- 通道 A（120 轮）：脚本直接生成小矩阵，比较主解、独立参考解与 Python 纯文本 oracle，并额外让 checker 复核主解输出
- 通道 B（120 轮）：调用 `generator stress <seed+i>` 生成输入，先经 `validator` 校验，再比较主解与参考解，并让 checker 复核
- 覆盖形状（通道 A）：1×1 共 16 轮、单行 39 轮、单列 34 轮、70 种不同 (n,m)
- 覆盖形状（通道 B）：1×1 共 1 轮、单行 10 轮、单列 13 轮、34 种不同 (n,m)
- 值域：随机全区间、只取 {−1000,−1,0,1,1000}、全同值常量、小范围重复
- 换行说明：Windows 文本模式输出 CRLF，比较前统一归一化为 LF

## 标准验题器

命令：

```powershell
pwsh -NoProfile -ExecutionPolicy Bypass -File 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/11'
```

- 退出码：0（`[success] 04-11 passed 39 cases.`）
- case 总数 39 = sample 3 + secret 36，全部通过 validator 与 checker
- 主解 39/39 通过；参考解 `solution2` 39/39 通过
- 错解 10 个，全部 `expected=fail`；逐个复跑全量数据确认全部以正常退出后的 WA（退出码 1）被击杀，无一例 RE：

| 错解 | 击杀 case 数 | 击杀方式 |
| --- | --- | --- |
| wrong-transpose | 35/39 | WA |
| wrong-abs | 32/39 | WA |
| wrong-last-column | 39/39 | WA |
| wrong-last-row | 39/39 | WA |
| wrong-print-dimensions | 39/39 | WA |
| wrong-trailing-space | 39/39 | WA |
| wrong-missing-final-newline | 39/39 | WA |
| wrong-single-line | 32/39 | WA |
| wrong-flat-index | 24/39 | WA |
| wrong-no-separator | 32/39 | WA |

## 本次修复（断点续做）

1. `config.json` 的 `build.cppFlags` 补 `-static`。原因：本机 PATH 中 Git 的 `mingw64/bin` 排在 g++ 16.1 工具链之前，`-O2` 动态链接时会加载旧 `libstdc++-6.dll`，导致 testlib 全局流对象静态初始化阶段 SIGSEGV，generator/validator/checker 全部无法启动。加 `-static` 后与 weekly-04 的 01/12/20 号题目构建方式一致。
2. `src/checker/checker.cpp` 重写为字符级严格解析。原实现用 `readToken()`/`readEoln()`，会接受双空格、Tab 和缺失的末尾换行，与题面“恰好一个空格、最后一行有换行”的承诺不符。新实现逐字符校验整数写法、单空格、每行且仅一次换行、EOF，并同样严格校验 jury 答案。
3. `src/solution2.cpp` 替换为盲审独立实现。
4. `docs/statement.md` 增加独立的「数据范围」小节，用中文括号列出 n、m、元素范围与元素总数。
5. 新增 6 个实现层错解（print-dimensions / trailing-space / missing-final-newline / single-line / flat-index / no-separator），并把原先四个错解从“只跑单个定向 case”改为全量 39 个 case。
6. `docs/tutorial.md` 的三层错解分析同步更新。

## 遗留风险

- validator 的 strict 模式在 Windows 下要求 CRLF。当前 generator 通过 PowerShell 捕获 stdout 后以 `UTF8Encoding` 写盘，落盘为 LF，但 validator 用 `type |` 管道喂入（文本模式会转换）所以能通过；若将来改为直接重定向文件字节给 validator，需要确认换行处理。这是工具链本地行为，不影响 Hydro 上的评测。
- checker 接受 CRLF 或 LF 行尾（与 testlib 的 `readEoln` 语义一致），因为 Windows 本地答案文件天然是 CRLF；行内空格、每行一次换行、EOF 仍严格。
- 复杂度层错解确不适用（任何正确实现都必须 Θ(nm) 读写），已在 tutorial 中说明理由，未强行凑一个 TLE 错解。
- 未做 Hydro 导出、未改其他题目/讲义/README/项目配置、未执行 git 操作。
