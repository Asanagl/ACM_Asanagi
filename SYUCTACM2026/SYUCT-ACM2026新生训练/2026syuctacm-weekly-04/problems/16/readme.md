# 16. 两条对角线
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练方阵两条对角线的下标定位：主对角线取 $a_{i,i}$，副对角线取 $a_{i,n+1-i}$，并强调奇数阶时中心元素在两条对角线上各计一次。数据覆盖 $n=1$、$n=2$、奇数阶非零中心、偶数阶、全负数、全零、单侧对角线非零、中心为零、定向错解与满规模极值，并稳定击杀 7 类典型错解。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练\2026syuctacm-weekly-04\problems\16'
```

注意 Powershell 5.1 会按本地代码页读取该脚本中的中文注释而解析失败，请用 `pwsh`（PowerShell 7）执行；`-Workspace` 需传绝对路径。

## `config.json`

重要字段：

- `slug`、`title`：工作区标识与题目名。
- `interactive`：为 `false`，使用 checker 模式。
- `timeLimitMs`、`memoryLimitMb`：本地验证使用的时限与内存。
- `statement`、`tutorial`：题面与题解入口。
- `validator`：严格输入校验器（逐行校验空格与行尾）。
- `generator.path`、`generator.cases`：可复现的数据生成计划（类型 + 种子）。
- `checker`：本题输出唯一，checker 依次比较两个整数并拒绝多余 token。
- `solutions`：主解与独立参考解。
- `wrongSolutions`：必须在生成数据上被判错的错解。

## 说明

- `src/solution2.cpp` 由一次全新只读盲审（仅提供公开题面、样例、约束与 Judge 语义，未提供工作区路径或算法）产出的独立实现改编，采用 0 基下标；主解采用 1 基下标，二者相互独立。
- 复杂度层错解不适用：任何正确读入 $n^2$ 个元素的实现都是 $O(n^2)$，$n\le200$ 时仅约 $4\times10^4$ 次操作，不存在能骗过 1000ms 的渐进错误实现，详见 `docs/tutorial.md`。
- 本机 `PATH` 中 Git 自带的 `libstdc++-6.dll` 会被优先加载，导致所有 testlib 程序启动即崩溃；运行验题器前需把 MinGW 的 bin 目录放到 `PATH` 最前（例如 `export PATH="/c/Algo Bootstrap/mingw64/bin:$PATH"`）。
- 生成数据位于 `.codex-test-artifacts/build/04-16/generated`，不需要提交。
