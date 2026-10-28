# 19 验证记录

## 环境

- 编译器：`g++ (MinGW-Builds) 16.1.0`，实际路径 `C:/Algo Bootstrap/mingw64/bin/g++`
- 验题脚本：`C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1`，用 `pwsh -NoProfile -ExecutionPolicy Bypass -File` 调用

## 环境故障与处理（非题目缺陷）

Git Bash 的 `PATH` 把 `/mingw64/bin`（Git 自带旧运行库）排在编译器目录之前，testlib 程序会加载到版本不匹配的
`libstdc++-6.dll` 并段错误（连只含 `registerGen` 的最小程序也崩）。该问题同样影响本仓库其它已通过题目（如 03），
与本题代码无关。把编译器目录前置即可修复：

```bash
PATH="/c/Algo Bootstrap/mingw64/bin:$PATH" pwsh -NoProfile -ExecutionPolicy Bypass \
  -File run-all-tests.ps1 -Workspace <题目录>
```

另外发现 testlib 在 Windows 上以 strict 模式校验行尾，直接喂 LF 输入会给 `Expected EOLN`；
验题脚本用 `cmd /d /c "type in | validator.exe"` 管道调用，此时输入为 CRLF，正常通过。

## 题目自身修复

- `src/validator/validator.cpp` 编译失败：缺少 `<string>` 且未限定 `to_string`，已补 `#include <string>` 并改为 `std::to_string`。
- `docs/statement.md` 的 H1 由 `# 19. 顺时针旋转` 改为 `# 顺时针旋转`（中文题名，与本批次其它题一致）。
- `src/solution2.cpp` 按 `.tmp/19-blind` 的指定模型盲审实现重写为独立路径（一维行优先数组 + 直达取数 + `fread`/`fwrite`），
  与主解（构造 `B` + `iostream`）在数据布局、下标方向、I/O 上均不同。

## 差分对拍

- 固定种子 `SEED=12345`，oracle 为 `zip(*A)` 转置后逐行反转（独立于两份实现）。
- 轮次 1：150 轮，覆盖 102 种不同 `(n,m)`，含 1×m、n×1、小方阵、非方阵（k×1..60）。
- 轮次 2：120 轮，含 1×500、500×1、200..500×1..5、1..5×200..500、随机 1..500、500×k、k×500。
- 合计 **270 轮，0 失败**；每轮同时校验主解与 `solution2` 的整数序列，并校验主解输出的行数/每行个数形状。
- 首次运行时脚本因 bytes/str 比较写错产生假失败，已修正脚本后重跑，非题目缺陷。

## 标准验题器

- `run-all-tests.ps1`：`EXIT=0`，`[success] 04-19 passed 38 cases.`
- case 数：38（sample 2 + secret 36）。
- 主解 38/38 通过 checker；`solution2` 参考解 38/38 通过 checker。

## 错解击杀（全部 38 个 case 逐一跑）

| 错解 | WA | TLE | RE | AC | 击杀（secret 内） | 首杀 case |
|---|---|---|---|---|---|---|
| wrong-transpose | 31 | 0 | 0 | 7 | 29 | sample-1 |
| wrong-counterclockwise | 32 | 0 | 0 | 6 | 30 | sample-1 |
| wrong-loop-bound | 18 | 0 | 0 | 20 | 17 | sample-1 |
| wrong-quadratic | 0 | 4 | 0 | 34 | 4（TLE） | max-square |

- 所有 `expected=fail` 的错解都被稳定击杀，且都不是靠意外 RE。
- `wrong-quadratic` 只在 4 个近上限 case 上超时（`max-square`、`max-values`、`near-max-wide`、`near-max-tall`），
  单独测 `near-max-wide`：>20 s 未完成，而主解 0.056 s、`solution2` 0.023 s，TLE 由真实复杂度差距造成。
- 其余 3 个错解在若干 case 上正确（如全相同元素、单行），但都在 secret 内被 17~30 个 case 判 WA，未出现全 AC。

## validator / checker 负向测试

- validator（按验题脚本的 cmd 管道路径）：合法 1×1、1×1 极值、500×500 全部接受；
  `n=0`、`m=0`、`n=501`、`m=501`、缺元素、多元素、`10^9+1`、`-10^9-1`、多一行 全部拒绝（exit 3）。
- checker：精确输出、无末尾换行、多余空白均接受；错值、过少整数、多余整数、非整数、尾随文本、空输出、
  行序颠倒 均拒绝。注意本题 judge 语义把空白只当分隔符，故“全部整数写在一行”也会被接受，这与题面声明一致。

## 结论

公开题面、约束、样例、唯一输出语义在盲审前冻结（SHA-256 `55596a44daeff44a5301ceb5e751f91e06d88a70bea306283ba4b61a53d98906`）；
盲审后仅调整了 tutorial 的参考解描述与 H1，未改变题目语义、约束或数据。
