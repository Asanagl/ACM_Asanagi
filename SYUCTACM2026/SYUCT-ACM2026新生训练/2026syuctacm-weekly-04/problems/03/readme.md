# 03. 元音计数
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本题训练字符串遍历、字符分类（元音/非元音）与大小写合并。数据覆盖长度 1、全辅音、`y/Y` 密集、全大写/全小写元音、重复串与近上限长度，可稳定击杀六类典型错解（3 个思路层 + 3 个实现层）。

## Run

```powershell
& 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练\2026syuctacm-weekly-04\problems\03'
```

`-Workspace` 请给绝对路径：脚本把相对路径解析到 skill 仓库根目录（`scripts/` 的父目录），而不是当前工作目录，给相对路径会报 `config.json 不存在`。

如果 `g++` 来自 `C:\Algo Bootstrap\mingw64`，运行时需要让该目录下的 `libstdc++-6.dll` 优先于 Git Bash 自带的 `C:\Program Files\Git\mingw64\bin` 版本，否则 harness 编译出的程序会静默无输出或崩溃（`0xC0000005`），表现为「所有 case 生成失败」：

```powershell
$env:PATH = 'C:\Algo Bootstrap\mingw64\bin;' + $env:PATH
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

- 题面含 3 个样例：`HeLloWorld`（基本计数）、`AEIOUaeiou`（大小写合并）、`yes`（`y` 非元音的定向反例，把 `y` 计成元音的实现会在样例上直接暴露）。
- 独立参考解为 `src/solution2.cpp`：`fread` 分块读取 + 算术大小写折叠 + `switch` 分类，与主解的 `std::string` 读入 + `tolower` + `string::find` 查表构成两条不同实现路径。其基础来自显式指定模型 `wb2api/deepseek-v4.1-flash` 的只读盲审。
- 复杂度层错解不适用：本题任何合理实现均为 $O(|s|)$，不存在渐进错误空间，详见 `docs/tutorial.md`。
- 验证证据保存在 `.tmp/03-verify/`（不入库）：`diff-rounds.log` 是种子 12345 的 120 轮差分对拍 + 20 个定向边界用例，`killmap.log` 是逐个错解的首个击杀点，`final4.log` 是验题器完整输出。
- Generated test files live under `build/generated` and do not need to be committed.
