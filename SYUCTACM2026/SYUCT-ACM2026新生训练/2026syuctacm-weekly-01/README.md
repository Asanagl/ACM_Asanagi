# 2026 SYUCTACM 新生训练周赛 01

本题包对应前三次入门训练：

- 第 1 章（2026-09-23）：变量、基本类型、输入输出、溢出与类型选择；
- 第 2 章（2026-10-07）：表达式、判断、循环、枚举、多组数据与复杂度直觉；
- 第 3 章（2026-10-14）：数组和排序，在 D 题中少量使用。

## 题目列表

| 题号 | 题目 | 核心知识点 | 难度定位 |
| --- | --- | --- | --- |
| A | 逐级加训 | 等差和、long long、溢出 | 入门 |
| B | 日历翻页 | 闰年判断、条件分支、循环模拟 | 入门至简单 |
| C | 约数清点 | 取模、枚举、平方根边界、复杂度 | 简单 |
| D | 中位训练 | 一维数组、排序、中位数、长整型累加 | 简单至中等 |

## 本地验证

每道题都是一个独立的标准题工作区，config.json 是该题的本地验题入口。使用 ICPC Problem Creator 的 run-all-tests.ps1 可以编译 validator、checker、generator、主解、参考解和错解，并检查生成数据是否满足预期。

~~~powershell
$runner = 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\run-all-tests.ps1'
& $runner -Workspace 'problemsets/2026syuctacm-weekly-01/problems/a-step-up-training'
& $runner -Workspace 'problemsets/2026syuctacm-weekly-01/problems/b-calendar-page'
& $runner -Workspace 'problemsets/2026syuctacm-weekly-01/problems/c-divisor-count'
& $runner -Workspace 'problemsets/2026syuctacm-weekly-01/problems/d-training-median'
~~~

## Hydro 导出

Hydro 的题目导入格式是单题 zip，因此本目录会生成 4 个可分别导入的单题包；另外再保留一个包含四个单题包和内部源码的周赛归档包，便于传递和备份。导出脚本依赖 PowerShell 模块 powershell-yaml：

~~~powershell
Install-Module powershell-yaml -Scope CurrentUser
$exporter = 'C:\Users\Asanagi\Documents\ACM\ACM_Asanagi\SYUCTACM2026\SYUCT-ACM2026新生训练\工具链\icpc-problem-creator\scripts\export-hydrozip.ps1'
& $exporter -Workspace 'problemsets/2026syuctacm-weekly-01/problems/a-step-up-training' -Output 'problemsets/2026syuctacm-weekly-01/hydro/A-逐级加训.zip'
~~~

对 B、C、D 题重复执行即可。单题 Hydro 包只包含题面、静态测试数据和 testlib checker，不包含标程、题解和错解；导入 Hydro 后按 A、B、C、D 创建题目，再在平台上组建比赛。

本次已生成的包位于 `hydro/`：

- `A-step-up-training.zip`
- `B-calendar-page.zip`
- `C-divisor-count.zip`
- `D-training-median.zip`

四个 zip 都已经通过包结构检查；每个包均包含 `problem.yaml`、`problem_zh.md`、`testdata/config.yaml`、`testdata/checker.cpp` 以及对应的 `.in/.ans` 测试数据。

## 设计取舍与风险

本地维护采用“每题独立工作区”的方案，备选是四题共用一个 generator/checker 工程。独立工作区更适合 Hydro 单题导入和后续单题修改，代价是少量模板重复，因此用总 README 统一说明。

交付前重点检查三类边界：日历的世纪闰年、约数统计对完全平方数的重复计数、D 题绝对差之和的 long long 溢出。另一个环境风险是导出脚本依赖 powershell-yaml；缺少该模块时可以完成本地验题，但不能宣称 Hydro zip 已成功导出。
