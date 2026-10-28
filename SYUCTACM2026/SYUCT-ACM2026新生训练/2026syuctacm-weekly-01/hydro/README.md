# Hydro 导入包

本目录包含 2026 SYUCTACM 新生训练周赛 01 的 4 个 Hydro 单题包：

| 题号 | 文件 | 导入说明 |
| --- | --- | --- |
| A | `A-step-up-training.zip` | 导入为 A 题“逐级加训” |
| B | `B-calendar-page.zip` | 导入为 B 题“日历翻页” |
| C | `C-divisor-count.zip` | 导入为 C 题“约数清点” |
| D | `D-training-median.zip` | 导入为 D 题“中位训练” |

Hydro 的标准导入单位是单题，因此 4 个 zip 应分别导入，再在 Hydro 中将它们加入同一场比赛。每个 zip 只包含题面、静态测试数据和 `testlib` checker，不包含标程、题解、generator、validator 或错解。

对应的完整出题工作区位于上一级 `problems/` 目录：

- `docs/statement.md`：题面；
- `docs/tutorial.md`：题解；
- `src/solution.cpp`：C++ 主标程；
- `src/solution2.cpp`：独立 C++ 参考解；
- `src/solution.py`：Python 参考解；
- `src/generator/`、`src/validator/`、`src/checker/`、`src/wrong/`：内部验题材料。
