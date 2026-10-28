# 09. 截取一段
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练 `std::string::substr` 的两个参数语义：起点用 $0$ 起始下标 `l - 1`，长度用闭区间元素个数 `r - l + 1`。数据覆盖长度 1、单字符区间、整串、贴左/贴右、重复字符、随机与近上限长度，可稳定击杀 5 个典型错解。

## Run

```powershell
$env:PATH = 'C:\Algo Bootstrap\mingw64\bin;' + $env:PATH
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/09'
```

## `config.json`

Important fields:

- `slug`, `title`: human-readable identifiers for the workspace.
- `interactive`: selects checker mode or interactor mode.
- `timeLimitMs`, `memoryLimitMb`: runtime metadata used by local validation.
- `statement`, `tutorial`: documentation entry points.
- `validator`: strict input validator.
- `generator.path`, `generator.cases`: reproducible data generation plan.
- `checker`: unique-output comparison logic.
- `solutions`: main and reference implementations.
- `wrongSolutions`: deliberately incorrect solutions that must fail on generated data.

## Notes

- 未提供 Python 参考解：独立参考由 `src/solution2.cpp` 承担（`for` 循环逐字符 `push_back`），与主解的 `substr` 写法在实现路径上相互独立。
- 复杂度层错解不适用：本题任何合理实现都是 $O(n)$，不存在渐进错误空间，详见 `docs/tutorial.md`。
- 生成与验证使用固定 seed（11–40），31 个 case 全部在 `config.json` 中显式声明 `name`/`type`/`seed`/`group`；sample 也经过 validator。
- 本地运行需要让 PATH 中的编译器 `bin` 目录优先于其它 `libstdc++-6.dll`，否则 iostream 缓冲输出可能被错误 DLL 丢弃（与本题目内容无关的环境问题）。
- validator 是严格的：`registerValidation` 下 `inf.strict = true`，`readToken` 不会自动跳过空白，因此必须显式 `readEoln()` / `readSpace()`，且行尾按 CRLF 处理（与 generator 输出一致）。漏写 `readEoln()` 会让所有 case 以 `Unexpected white-space` 被拒。
- Generated test files live under `build/generated` and do not need to be committed.
