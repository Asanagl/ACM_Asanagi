# 01. 字符串的头和尾
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练 `string` 读入、`size()` 与首尾下标访问。数据中的多点覆盖长度 1、首尾相同/不同、重复形态与近上限长度，可稳定击杀五类典型错解。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'problemsets/2026syuctacm-weekly-04/problems/01'
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

- 未提供 Python 参考解：本题要求的独立参考由 `src/solution2.cpp`（`length()` / `front()` / `back()` 写法）承担，与主解的 `size()` / 下标写法相互独立。
- 复杂度层错解不适用：本题任何合理实现均为 $O(|s|)$，不存在渐进错误空间，详见 `docs/tutorial.md`。
- Generated test files live under `build/generated` and do not need to be committed.
