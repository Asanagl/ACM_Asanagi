# 05. 字符替换
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练字符串读入、逐字符比较与原地改写。数据覆盖长度 1、`x=y`、无匹配、全匹配、首尾匹配、重复与交替、满长度 $10^5$，可稳定击杀四类典型错解（2 个思路层 + 2 个实现层）。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练\2026syuctacm-weekly-04\problems\05'
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

- 数据规模：2 个 sample + 36 个 secret，共 38 个点；覆盖最小长度、`x=y`、无出现、全匹配、首/尾匹配、重复与交替、二字母表、定向混合、随机与满长度。
- 独立参考解为 `src/solution2.cpp`：来源是只读盲审模型 `wb2api/deepseek-v4.1-flash` 的独立作答（只提供冻结后的公开题面、约束、样例与 Judge 语义，不提供路径、思路或代码）。盲审结论为“题面无实质歧义与隐藏坑”，其实现被改写为“26 项映射表 + 范围 `for` + 一次性 `fwrite`”，与主解的“下标循环 + 逐字符比较 + `cout`”构成两条不同实现路径；两解在全部 38 个点输出一致。
- Validator 按字节自行判定行尾：LF、CRLF、以及末行无换行符都被接受，而空串、超长、非小写字母、多余空格/制表符、多余行会被拒绝。不用 testlib 的 `strict` 行尾检查，是因为它在 Windows 下只接受 CRLF，会误杀 LF 数据。
- 复杂度层错解不适用：最坏情形（$10^5$ 个字符全匹配）下平方级整串重建实测约 $0.7\sim 0.9\,\mathrm{s}$，仍在 1000 ms 内，无法稳定卡掉，故不保留 expected=fail 的复杂度错解，详见 `docs/tutorial.md`。
- `build.cppFlags` 带 `-static`，避免本地 MinGW 动态运行库版本不一致导致的启动崩溃（与本仓库已完成题目一致）。
- Generated test files live under `build/generated` and do not need to be committed.
