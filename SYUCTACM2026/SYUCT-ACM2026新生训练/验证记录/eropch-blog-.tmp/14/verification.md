# 14. 每列的和 — 验证记录

## 公开语义（冻结）

- 编号 14，slug `04-14`，中文题名《每列的和》。
- 输入：`n m`（1≤n,m≤1000，可不相等），随后 n 行每行 m 个整数 a_ij ∈ [-1e9, 1e9]。
- 输出：一行 m 个整数，第 j 个为第 j 列元素和；列和绝对值 ≤ 1e12。
- Judge：答案唯一，逐 token 比较 m 个整数，数量/顺序/数值错误均判错。
- 资源：gnu++17，1000 ms，256 MiB。
- 冻结题面 SHA-256：`818d0d18104b01059a8f0c8b3b711db924d33afd2d9c85df0129b18cb7f1a851`

## 盲审

- 模型（显式指定）：`wb2api/deepseek-v4.1-flash`
- 命令：`kimi -p <prompt> -m wb2api/deepseek-v4.1-flash --skills-dir .tmp/14/blind2/no-skills`
- 隔离：全新非交互会话；`--skills-dir` 指向空目录；提示明文禁止工具、文件读写、目录浏览、联网；提示只含冻结题面、约束、3 个样例、Judge 语义与资源限制，不含工作区路径、算法、生成器或数据。
- 原始回答：`blind2/response.txt`；stderr：`blind2/stderr.log`。
- 结论：独立复述任务与约束一致；算法为“读入时按当前列下标累加到长度 m 的 long long 数组”，时间 Θ(nm)、额外空间 O(m)；证明含输入位置对应引理、逐行归纳不变量、每列恰累加 n 次、列不混淆、输出顺序与个数；边界覆盖 1×1、单行、单列、非方阵两方向、全负、全零、重复、越 int、±1e12、抵消、最大规模。无分歧，无未证事项。
- 采纳：该实现作为 `src/solution2.cpp` 的基础（与主解“存整个数组 + 按列扫描 + O(nm) 空间”结构不同）。

## 对拍（固定种子 12345）

- `python .tmp/14/stress.py`：100 轮（奇数轮 generator `stress` 类型随机 seed；偶数轮手写 n,m ≤ 7，三种取值域含 ±1e9），主解 vs solution2 vs Python 大整数 oracle 三方比较。
- 结果：**100/100 通过，0 处不一致**，退出码 0。无反例产生。

## 错解击杀（39 个 case：3 sample + 36 secret）

| 错解 | 层级 | 被击杀 case 数 | 击杀方式 |
|---|---|---|---|
| wrong-rows | 思路（按行求和） | 32 / 39 | WA |
| wrong-int | 实现（32 位累加） | 17 / 39 | WA |
| wrong-loop | 实现（`i+1<n` 漏最后一行） | 37 / 39 | WA |
| wrong-quadratic-search | 复杂度（扁平后线性查找定位，O(n²m²)） | 9 / 39 | TLE（非 RE） |

三处非击杀为合法情形：wrong-rows 在 n=m 全同值/单行单列时与列和相等；wrong-int 在列和未越 int 的 case 上正确；wrong-loop 仅在 `min-zero`、`all-zero`（加 0 不影响）上通过。均由其他定向 case 稳定击杀。

## 标准验题

- 命令：`pwsh -NoProfile -File C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1 -Workspace <题目录>`
- 退出码 **0**，`[success] 04-14 passed 39 cases.`
- 覆盖主解、solution2、validator、checker、4 个 wrong 的实际运行结果。

## 环境适配

- `build.cppFlags` 增加 `-static`：本机 Git Bash 下非静态链接的 testlib 可执行文件因 DLL 解析崩溃（sibling 01/11/12/20 同样处理）。这不是题面变化。
