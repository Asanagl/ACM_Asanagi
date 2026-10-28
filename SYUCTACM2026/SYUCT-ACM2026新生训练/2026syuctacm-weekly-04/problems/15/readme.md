# 15. 最大值的位置
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练二维最值扫描与坐标的同步维护：在逐行扫描矩阵时同时维护当前最大值及其位置，并处理最大值重复出现时的行优先次序规则。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'problemsets/2026syuctacm-weekly-04/problems/15'
```

## `config.json`

Important fields:

- `slug`, `title`: human-readable identifiers for the workspace.
- `interactive`: selects checker mode or interactor mode.
- `timeLimitMs`, `memoryLimitMb`: runtime metadata used by local validation.
- `statement`, `tutorial`: documentation entry points.
- `validator`: strict input validator.
- `generator.path`, `generator.cases`: reproducible data generation plan.
- `checker`: local judging logic.
- `solutions`: main and reference implementations.
- `wrongSolutions`: deliberately incorrect solutions that must fail on generated data.

## Notes

Generated test files live under the script artifact root and do not need to be committed.

- 盲审独立性：`src/solution2.cpp` 的基础是委托给 `wb2api/deepseek-v4.1-flash` 的全新只读盲审解。盲审只看到冻结的公开题面、样例、约束与 Judge 语义，没有工作区路径、主解、生成器或其他代码。其结论（按行优先扫描、严格大于 `>` 更新、`best` 初值不能取 0）与主解一致，无分歧，无需升级对抗审查。
- 三层错解：思路层 3 个（tie 取最后一次、列优先、只输出值）、复杂度层 1 个（$O((nm)^2)$ 重扫）、实现层 4 个（初值 0、0 起始下标、行列颠倒、边界漏最后一行/列）。共 8 个 `expected=fail`，均由 checker 判 WA 或稳定 TLE（`wrong-quadratic`），不依赖意外 RE。
- 样例答案由验题脚本运行主解生成，未手工填写；3 个样例也经过 validator。
- 本地环境注意：如果 `PATH` 里 Git 自带的 `mingw64/bin` 排在编译器目录之前，其旧版 `libstdc++-6.dll` 会遮蔽 g++ 16.1 自带的版本，导致所有 iostream 程序静默丢弃输出（连 `04-01` 等既有题也会失败）。跑验题脚本前请把 `C:\Algo Bootstrap\mingw64\bin` 放到 `PATH` 最前面。

