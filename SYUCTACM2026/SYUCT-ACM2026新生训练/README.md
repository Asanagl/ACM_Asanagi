# SYUCT-ACM2026 新生训练 · 出题材料归档

本目录按**题目来源**归档 2026 年 SYUCT-ACM 新生训练的四次训练出题材料：同一道题的题面、题解、标程、错解、checker、validator、generator、正式数据和 Hydro 包都放在同一个工作区里，不再按文件类型拆散。

## 目录结构

```
SYUCT-ACM2026新生训练/
├── 2026syuctacm-weekly-04/            # 第四次训练新增 25 题（来源：eropch-blog/problemsets）
│   ├── README.md                      # 25 题的题单/验证结论/风险说明
│   ├── hydro/                         # 27 项：01.zip~25.zip + 汇总备份包 + README
│   └── problems/01 … 25/              # 每题一个完整工作区（2445 个文件）
│       ├── config.json
│       ├── docs/statement.md, docs/tutorial.md
│       ├── include/testlib.h
│       ├── src/solution.cpp, solution2.cpp, wrong/, checker/, validator/, generator/
│       └── exported-tests/
├── 2026syuctacm-weekly-01/            # 第一次训练 4 题（来源同上）
│   ├── README.md
│   ├── hydro/                         # 5 个包 + README
│   └── problems/a-step-up-training, b-calendar-page, c-divisor-count, d-training-median
├── 工具链/                            # 出题工具链（来源：.codex/skills/icpc-problem-creator）
│   └── icpc-problem-creator/          # scripts/templates/lib/examples + .codex-test-artifacts
├── 验证记录/                          # 验证副产物，按来源分三个子目录
│   ├── eropch-blog-.tmp/              # 历轮盲审、压测、验证笔记（5065 个文件）
│   ├── problemsets-.tmp/              # 题集目录内的零星验证残留（26 个文件）
│   └── workbuddy-2026-10-25-21-04-28/ # 本轮 25 题验证工作区（430 个文件）
├── 零散命题文件-Downloads/            # 12 个零散命题/题解/讲义文件
├── 2026SYUCT-ACM信息初步征集.xlsx      # ↓ 5 个原有行政表格，未改动
├── 2026SYUCT-ACM新生线下训练签到表.xlsx
├── 2026SYUCT-ACM线下训练名单.xlsx
├── 2026SYUCT_确认入选名单_1820最终版.xlsx
├── SYUCTACM2026线下训练权重计算表.xlsx
├── README.md                          # 本文件
├── _迁移清单.json / .txt               # 第一次迁移（按类型）的 源→目标 记录
└── _重新归类清单.json / .txt           # 按来源重新归类的 源→目标 记录
```

## 归档原则

1. **按来源/题集分组**：`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/` 各自独立，互不交叉。
2. **每题一个完整工作区**：`problems/<编号>/` 内保留 `config.json` 及其引用的相对路径（`docs/statement.md`、`src/solution.cpp`、`src/checker/checker.cpp`、`src/generator/generator.cpp` 等），因此**本地验题器可以直接运行**：

   ```powershell
   $env:PATH = "C:\Algo Bootstrap\mingw64\bin;" + $env:PATH
   & pwsh -NoProfile -File "C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1" `
     -Workspace "C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/09"
   ```

   验题脚本随工具链一起搬到了 `工具链/icpc-problem-creator/scripts/`，**必须用新路径调用**；脚本靠自身位置定位 `lib/`、`templates/` 和 `.codex-test-artifacts/`，不依赖题集位置。

   > **已修补的编码问题**：验题器原先用 ASCII 写 `validator-*.cmd` 包装脚本，遇到含中文的路径会把 `新生训练` 写成 `????`，导致 `type` 找不到输入、validator 全部 exit=255。已改为用系统 ANSI 代码页写入（`run-all-tests.ps1` 与 `lib/icpc-common.ps1` 各一处），纯 ASCII 路径下行为不变。修补后已实测：09 题 32 个用例、24 题 44 个用例、week-01 的 a-step-up-training 7 个用例，退出码均为 0。
3. **Hydro 包按题集集中**：放在各题集下的 `hydro/`，与工作区平级。
4. **非题目类材料按来源单独成目录**：出题工具链在 `工具链/`，验证副产物在 `验证记录/`（再按来源分三个子目录），零散文件在 `零散命题文件-Downloads/`。

## 来源对照

| 现位置 | 原位置 |
| --- | --- |
| `2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/` | `C:\Users\Asanagi\eropch-blog\problemsets\` |
| `验证记录/eropch-blog-.tmp/` | `C:\Users\Asanagi\eropch-blog\.tmp\` |
| `验证记录/problemsets-.tmp/` | `C:\Users\Asanagi\eropch-blog\problemsets\.tmp\` |
| `工具链/icpc-problem-creator/` | `C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\` |
| `验证记录/workbuddy-2026-10-25-21-04-28/` | `C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\` |
| `零散命题文件-Downloads/` | `C:\Users\Asanagi\Downloads\`（12 个文件） |

## 来源审计

- `来源审计报告.md`：逐题列出源文件的来源判定、可核验依据与置信度，并单列存疑项（11 个 `solution2.cpp`、2 个旧题面哈希、29 份 manifest 路径残留）。
- `来源清单.csv`：2572 行，覆盖两个题集下**每一个**文件（含 2080 个导出数据），列含 `文件路径 / 类别 / 字节 / SHA256前16 / 修改时间 / 来源判定 / 可核验依据 / 置信度`。

结论摘要：`problemsets/` 从未提交到 git（`.gitignore` 第 22 行忽略），因此**没有 commit 可引用**；唯一第三方来源是 testlib 0.9.44（Mike Mirzayanov, MIT）；导出数据可由 `generator(type,seed)` 确定性复现（抽查 87/87 一致）。

## 清单

- `_迁移清单.json` / `_迁移清单.txt`：第一次迁移（按文件类型分类）的逐条 源→目标 记录。
- `_重新归类清单.json` / `_重新归类清单.txt`：按题目来源重新归类的逐条 源→目标 记录。
- 两份清单可联合还原任意文件的最终位置。

## 说明

- 迁移共 **14445** 个文件，实际到位 **14444** 个；缺失的一个是 `eropch-blog/.tmp/deepseek-harness-diagnosis.png`，它在扫描后被其它进程删除，源处也已不存在，属瞬时诊断截图，不是命题材料。
- 原 4 个位置已清空，各留 `README-已迁移.txt` 指路文件。
- 迁移过程中产生的空目录已移出到 `C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\_迁移残留-空目录\`（不含任何文件，可直接删除）。
- 本目录原有的 5 个行政表格（名单、签到表、权重表等）未做任何改动。
- 博客仓库 `eropch-blog` 根 `README.md` 与 `tools/cf-hydro-converter/` 下两处文档仍写着 `problemsets/` 是本地题目工作区，这些引用随迁移失效，未改动。
