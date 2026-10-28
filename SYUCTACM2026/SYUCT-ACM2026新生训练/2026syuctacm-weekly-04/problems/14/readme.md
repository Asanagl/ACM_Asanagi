# 14. 每列的和
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练二维数组的下标遍历与按列统计，覆盖非方阵（行数、列数不同）、$1\times1$、单行、单列、负数、零、重复值与 64 位列和。数据可稳定击杀“按行求和”“`int` 累加溢出”“漏掉最后一行”三类典型错解，并用上限规模卡掉二次方复杂度的错误实现。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'problemsets/2026syuctacm-weekly-04/problems/14'
```

## `config.json`

Important fields:

- `slug`, `title`: human-readable identifiers for the workspace.
- `interactive`: selects checker mode or interactor mode.
- `timeLimitMs`, `memoryLimitMb`: runtime metadata used by local validation.
- `statement`, `tutorial`: documentation entry points.
- `validator`: strict input validator.
- `generator.path`, `generator.cases`: reproducible data generation plan.
- `checker` or `interactor`: local judging logic.
- `solutions`: main and reference implementations.
- `wrongSolutions`: deliberately incorrect solutions that must fail on generated data.

## Notes

- 独立参考解为 `src/solution2.cpp`：不保存二维数组，只用长度为 $m$ 的 `long long` 数组边读边累加（$O(m)$ 空间），与主解的“保存二维数组 + 按列扫描 + $O(nm)$ 空间”构成两条不同实现路径。其基础来自显式指定模型 `wb2api/deepseek-v4.1-flash`、提示中只含冻结公开题面的只读盲审。
- `build.cppFlags` 使用 `-static`：本机非静态链接的 testlib 可执行文件在 Git Bash 下会因 DLL 解析问题崩溃，同目录的 01、11、12、20 也采用该做法。
- Generated test files live under `build/generated` and do not need to be committed.
