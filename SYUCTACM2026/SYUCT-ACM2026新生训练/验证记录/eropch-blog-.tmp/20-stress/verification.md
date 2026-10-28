# 20 验证汇总（普通验证模式）

- requested_mode: null
- effective_mode: normal（用户未指定模式，执行普通验证）

## 产物清单

| 文件 | 说明 |
| --- | --- |
| `config.json` | slug `04-20`，gnu++17，1000 ms，256 MiB，34 个 case |
| `docs/statement.md` | 中文 H1《边框元素之和》，SHA-256 `6c3d8319…82138a1` |
| `docs/tutorial.md` | 思路、证明、复杂度、边界、三层错误枚举 |
| `src/solution.cpp` | 主解：分区累加（首行 / 末行 / 中间行端点），O(nm) 时间、O(nm) 空间 |
| `src/solution2.cpp` | 独立参考解：逐格谓词流式累加，O(nm) 时间、O(1) 空间 |
| `src/validator/validator.cpp` | 严格校验 n/m 范围、元素范围、行内空格、EOLN、EOF |
| `src/generator/generator.cpp` | 由 `type + seed` 完全决定输出，可复现 |
| `src/checker/checker.cpp` | 唯一整数输出，严格 EOF |
| `src/wrong/*.cpp` | 7 个错解，全部 expected=fail |
| `include/testlib.h` | 与 weekly-01 样例一致（0.9.44） |
| `readme.md` | 本地验题命令与说明 |

## 盲审

- 模型：`wb2api/deepseek-v4.1-flash`（显式指定），全新只读会话，禁用技能目录。
- 仅提供冻结题面、约束、样例、Judge 语义；未给路径、算法、生成器或数据。
- 结论：独立给出逐格谓词 O(nm)/O(1) 算法与完整证明，无缺陷；已作为 `solution2.cpp` 基础。
- 详见 `.tmp/20-blind/review.md`。

## 对拍

- 固定种子 12345，100 轮小数据差分对拍。
- 三方比较：主解 `solution`、独立参考 `solution2`、Python 暴力 oracle。
- 结果：`rounds_requested=100 rounds_passed=100 failures=0`。
- 覆盖 1×1、1 行、1 列、2 行、2 列、方阵、随机形状；值域含小整数、正负、±10^7 端点。
- 脚本：`.tmp/20-stress/stress.py`。

## 标准验题器

命令：

```
pwsh -NoProfile -File C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1 \
  -Workspace C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/20
```

- 退出码：**0**
- 验收 case 数：**34**（sample 2 + secret 32）
- 主解、参考解、validator、checker、全部 7 个 wrong 均实际运行
- 主解与参考解在 34/34 个 case 上输出完全一致

## 错解击杀

| 错解 | 被判错 case 数 | 首个击杀 case | 判定类型 |
| --- | --- | --- | --- |
| wrong-whole | 18 | sample-1 | WA |
| wrong-corners-twice | 31 | sample-2 | WA |
| wrong-degenerate-double | 31 | sample-2 | WA |
| wrong-single-zero | 11 | sample-2 | WA |
| wrong-offbyone | 34 | sample-1 | WA |
| wrong-rows-only | 22 | sample-1 | WA |
| wrong-int | 3 | big-positive | WA |

全部通过 checker 返回 WA（退出码 2，数值不符），无一依赖崩溃或意外 RE。

## 环境说明

本机 Git Bash 的 `/mingw64/bin/libstdc++-6.dll` 会遮蔽 MinGW 编译器自带的 libstdc++，使动态链接的 testlib 程序在全局构造期 SIGSEGV。`config.json` 的 `cppFlags` 因此包含 `-static`，与同级 12 号题做法一致；该改动仅作用于本题工作区。
