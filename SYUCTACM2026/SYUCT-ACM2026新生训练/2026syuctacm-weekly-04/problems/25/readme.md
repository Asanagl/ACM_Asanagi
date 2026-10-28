# 最短循环节（04-25）
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


- slug：`04-25`
- 题名：最短循环节
- 类型：传统题（唯一输出，testlib checker）
- 时限 / 内存：1000 ms / 256 MiB
- 标准：gnu++17

求仅含小写字母的字符串 $s$（$1\le |s|\le 3000$）的最短循环单元及其长度；答案唯一，输出 `L t` 一行。

工作流由 `config.json` 驱动：

```powershell
C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1 -Workspace problemsets/2026syuctacm-weekly-04/problems/25
```
