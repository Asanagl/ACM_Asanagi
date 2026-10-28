# 20. 边框元素之和
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练矩阵的下标边界判断与"每个格子只累加一次"。数据覆盖 1×1、1 行、1 列、2 行、2 列、负数、边框和为 0 与超过 32 位的答案，可稳定击杀七类典型错解。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练\2026syuctacm-weekly-04\problems\20'
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

- `build.cppFlags` 含 `-static`：本机 Git Bash 的 `libstdc++-6.dll` 会遮蔽 MinGW 自带版本，导致动态链接的 testlib 程序在启动构造期崩溃；静态链接与同级 12 号题的做法一致。
- 未提供 Python 参考解：本题的独立参考由 `src/solution2.cpp`（逐格谓词流式累加，来自独立盲审）承担，与主解的分区累加相互独立。
- 复杂度层错解不适用：任何正确实现都必须读入 $nm$ 个元素，$O(nm)$ 已是输入下界，详见 `docs/tutorial.md`。
- Generated test files live under `build/generated` and do not need to be committed.
