# 02. 空格计数
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练整行读入与逐字符计数。核心坑点有三类：把整行读成单词、把连续空格合并成一段、漏掉行首或行尾的空格。数据覆盖空串、单空格、全空格、首尾空格、连续空格、无空格、最大长度与 100000 近上限形态。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'problemsets/2026syuctacm-weekly-04/problems/02'
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

- 独立参考解为 `src/solution2.cpp`：`std::cin.get()` 逐字符读到 `'\n'`/EOF，额外空间 $O(1)$；与主解的 `std::getline` + `std::string` 遍历构成两条不同实现路径（缓冲方式与空间复杂度均不同）。其基础来自显式指定模型 `wb2api/deepseek-v4.1-flash` 的只读盲审。
- `build.cppFlags` 含 `-static`：本机 Git Bash 的旧版 `libstdc++-6.dll` 会遮蔽 MinGW 16.1 自带版本，使动态链接的 testlib 程序在启动构造期崩溃。该改动仅作用于本题工作区，与同级 01、12、20 号题做法一致；`standard` 仍为 `gnu++17`，时限仍为 1000 ms、内存 256 MiB。
- 空间层错解不适用：本题输入上限约 0.1 MB，任何合理实现都远低于 256 MiB，详见 `docs/tutorial.md`。
- `wrong-quadratic` 刻意保留前缀串的构造，避免 `-O2` 把“重扫前缀”强度削减成线性扫描；实测 $|s|=100\,000$ 时约 4 秒，可稳定触发 TLE。
- Generated test files live under `build/generated` and do not need to be committed.
