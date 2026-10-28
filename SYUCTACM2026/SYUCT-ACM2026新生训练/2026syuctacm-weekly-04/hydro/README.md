# Hydro 导入包（2026syuctacm-weekly-04 新增 25 题）
> **归档说明（2026-10-26 迁移）**
> 本套材料已整体迁移到 `C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练`，并**按题目来源**归档：
> 题集目录（`2026syuctacm-weekly-04/`、`2026syuctacm-weekly-01/`）下保留了完整的单题工作区
> `problems/<编号>/`，`config.json` 的相对路径与迁移前完全一致，本地验题器可以直接运行；
> Hydro 导入包在同级 `hydro/`。文中绝对路径已从 `eropch-blog/problemsets` 改写为新归档根目录。


本目录是同目录上一级 `problems/01`～`problems/25` 导出的 Hydro 导入包，共 26 个 ZIP、两种用法。

## 〇、两种导入方式

| 文件 | 用途 | 说明 |
| --- | --- | --- |
| **`2026syuctacm-weekly-04-hydro-all25.zip`**（81.7 MiB） | **一次导入 25 题** | 根目录下是 25 个题目文件夹 `04-01`～`04-25`，每个都是完整单题包。Hydro 的导入逻辑是「根目录没有 `problem.yaml` 时，遍历一级子目录、逐个导入」，所以这个包会被识别成 25 道题。**推荐用这个。** |
| `01.zip`～`25.zip` | 逐题导入 / 单题重导 | 每个包对应一道题，互相独立。题库里已有部分题时，用这个补导更稳。 |

> 之前那个 `2026syuctacm-weekly-04-all25-backup.zip` 只是「把 25 个 ZIP 再压一层」，Hydro 会把它当成一个没有 `problem.yaml` 的包而**导入失败**（或只导 0 题），已移出本目录（详见第七节）。

## 一、文件清单

| 编号 | 中文题名 | 包内 pid | sample | secret | 包大小 |
| --- | --- | --- | --- | --- | --- |
| 01 | 字符串的头和尾 | `T193` | 2 | 31 | 17 KiB |
| 02 | 空格计数 | `T819` | 3 | 45 | 0.4 MiB |
| 03 | 元音计数 | `T118` | 3 | 36 | 5.5 MiB |
| 04 | 大小写互换 | `T719` | 2 | 42 | 29 KiB |
| 05 | 字符替换 | `T346` | 2 | 36 | 0.6 MiB |
| 06 | 反转字符串 | `T714` | 2 | 36 | 6.7 MiB |
| 07 | 回文判断 | `T554` | 5 | 43 | 0.6 MiB |
| 08 | 子串在哪里 | `T175` | 3 | 46 | 58 KiB |
| 09 | 截取一段 | `T257` | 2 | 30 | 22 KiB |
| 10 | 数字串求和 | `T124` | 2 | 30 | 0.2 MiB |
| 11 | 矩阵原样输出 | `T151` | 3 | 36 | 0.2 MiB |
| 12 | 矩阵加法 | `T790` | 1 | 39 | 6.1 MiB |
| 13 | 每行的和 | `T900` | 1 | 34 | 26.0 MiB |
| 14 | 每列的和 | `T250` | 3 | 36 | 21.7 MiB |
| 15 | 最大值的位置 | `T273` | 3 | 56 | 1.2 MiB |
| 16 | 两条对角线 | `T643` | 3 | 45 | 1.1 MiB |
| 17 | 每行逆序 | `T131` | 3 | 40 | 0.3 MiB |
| 18 | 矩阵转置 | `T359` | 2 | 38 | 0.6 MiB |
| 19 | 顺时针旋转 | `T857` | 2 | 36 | 5.7 MiB |
| 20 | 边框元素之和 | `T126` | 2 | 32 | 2.3 MiB |
| 21 | 四邻格统计 | `T463` | 2 | 38 | 0.6 MiB |
| 22 | 子矩阵求和 | `T712` | 1 | 39 | 0.4 MiB |
| 23 | 回文修补 | `T841` | 2 | 34 | 0.9 MiB |
| 24 | 棋盘染色 | `T602` | 1 | 43 | 47 KiB |
| 25 | 最短循环节 | `T413` | 2 | 32 | 35 KiB |

25 个单题包合计约 81 MiB；汇总导入包 `2026syuctacm-weekly-04-hydro-all25.zip` 另计约 82 MiB（内容与 25 个单题包相同，只是结构不同）。
13、14 两题偏大，因为上限用例是 1000×1000 的整数矩阵（单个 `.in` 约 10 MiB）。

`pid` 是导出器按 `slug` 哈希出来的稳定内部编号（`T` + 3 位数字），25 个互不相同，导入后不会互相覆盖。
它只是 Hydro 内部编号，与训练题号 01～25 无关；题号顺序以文件名和 `title` 为准。

## 二、包内结构

```
NN.zip
└── <pid>/
    ├── problem.yaml          # pid / owner / title（中文题名）/ tag / 提交统计
    ├── problem_zh.md         # 中文题面（已去掉 Markdown 一级标题，标题在 problem.yaml 里）
    └── testdata/
        ├── config.yaml       # type: default；checker_type: testlib；单 subtask、100 分；cases 清单
        ├── checker.cc        # testlib checker（唯一答案判定；扩展名必须是 .cc，见第七节）
        └── *.in / *.ans      # 全部测试点，.ans 由主解运行生成
```

包内**没有**主解、参考解、题解、generator、validator、错解、`readme.md` 等内部材料；已逐包核对。

`testdata/config.yaml` 里的 `cases` 条目与 `problems/NN/exported-tests/manifest.json` 一一对应（数量、文件名、内容均逐字节一致）。

## 三、导入顺序

按 `01.zip` → `25.zip` 依次上传即可，题号就是训练梯度：

- 01～06：字符串基础（读入、计数、映射、反转）
- 07～10：字符串进阶（双指针、子串查找、截取、数位求和）
- 11～17：二维数组基础（读入输出、逐行/逐列聚合、最值、对角线、行内逆序）
- 18～22：矩阵变换与统计（转置、旋转、边框、邻格、子矩阵）
- 23～25：综合（回文修补、棋盘染色、最短循环节）

## 四、导入后必须人工确认的几点

本地验证不能替代线上复核，以下四项请在 Hydro 后台逐题确认：

1. **时限**：导出器生成的 `testdata/config.yaml`（default 类型）**不带 `time` 字段**，时限没有被写进 ZIP。本套统一设计为 **1000 ms / 256 MiB**，导入后需要确认 Hydro 侧实际生效的时限是 1000 ms，必要时手动设置。
2. **checker 生效**：确认 `checker_type: testlib` 被正确识别、`checker.cc` 编译成功（导入日志里应能看到 checker 编译）。
3. **测试点数量**：确认每题导入后的测试点数与上表 `sample + secret` 一致（合计 1010 个）。
4. **判题语义**：用一个错误提交确认 PE（格式错误）在 Hydro 上计为 Wrong Answer 还是单独的格式错误判定。本套 checker 对格式问题会给出 PE 类消息（例如 18、25 的行结构/长度校验）。

## 五、本地已验证到什么程度

- 标准验题器 `run-all-tests.ps1`：25/25 退出码 0（主解、独立参考解、validator、checker、全部错解）。
- 固定种子 `12345` 的三方差分对拍：每题 105 轮，共 2625 轮，主解 / `solution2` / 盲审独立实现**逐字节一致**。
- 错解击杀：134/134（WA 119、PE 6、TLE 9、RE 0）。
- 逐包结构核对：`problem.yaml`、`problem_zh.md`、`testdata/config.yaml`、`testdata/checker.cc`、全部 `.in/.ans` 齐备；中文题名与题单一致；pid 无碰撞；无内部材料泄漏；无重复 secret 输入。
- 汇总包结构核对：根目录**无** `problem.yaml`、25 个一级目录、无内嵌 ZIP、pid 全部唯一且符合 Hydro 的 `^(?:[a-z0-9]{1,10}-)?[a-z][0-9a-z]*$`、每题用例数与 `exported-tests/manifest.json` 完全一致。

以上全部是**本机**结果。Hydro 的实际判题行为（testlib 版本、内存统计、PE 处理、时限默认值）仍需导入后复核。

## 六、重新导出

改了 `problems/NN` 下的题面、validator、checker 或 `config.json` 的 `generator.cases` 之后，必须**整包重导**，不要手工改 ZIP。

注意导出器的行为：只有当 `problems/NN/exported-tests/manifest.json` **不存在**时才会重新跑 generator 生成数据；否则直接复用旧 manifest。
因此**改过 `generator.cases` 的题，要先删掉该题的 `exported-tests/` 再导出**，否则新用例不会进包。

```powershell
$env:PATH = "C:\Algo Bootstrap\mingw64\bin;" + $env:PATH
& pwsh -NoProfile -File "C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/export-hydrozip.ps1" `
  -Workspace "C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/13" `
  -Output    "C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/hydro/13.zip"
```

汇总导入包需要在这之后重建（它按 `04-NN/` 目录结构重新组装，见第七节脚本）。

## 七、两处需要说明的改动（2026-10-27）

### 7.1 checker 扩展名从 `.cpp` 改为 `.cc`

**原因**：Hydro 默认语言表 `packages/hydrojudge/langs.yaml` 里，C++ 只注册了 `cc`（编译命令是 `g++ ... foo.cc`），**没有 `cpp`**。而 `testdata/config.yaml` 写的是 `checker: {file: checker.cpp, lang: auto}`，`lang: auto` 会按扩展名去语言表里找 `cpp`，找不到就编译失败——导入看似成功，第一次判题才会炸。

官方《测试数据格式》文档的示例也是 `checker: chk.cc`，并明确写了「在默认配置下，C++ 扩展名应为 `.cc` 而非 `.cpp`」。

**改动**：
- 25 个单题包内 `testdata/checker.cpp` → `testdata/checker.cc`，`config.yaml` 的 `file:` 同步改为 `checker.cc`；
- 导出器 `工具链/icpc-problem-creator/scripts/export-hydrozip.ps1` 已在源头改为输出 `checker.cc`（第 285 行的 `file =` 与第 427 行的 `Copy-Item` 目标），以后重新导出不会再退回 `.cpp`；
- 端到端验证：用改完的导出器重导 25 题，与现有包逐条目比对，**72 个条目 0 差异**，`testdata/checker.cc` 就位。

**注意**：`problems/NN/src/checker/checker.cpp` 这个**工作区里的源文件没有改名**，`config.json` 仍指向它。改名只发生在打包环节——Hydro 只认包里的文件名，本地验题器仍用 `.cpp`。

### 7.2 旧「备份汇总包」已移出

`2026syuctacm-weekly-04-all25-backup.zip`（79 MiB）是把 25 个 ZIP 再压一层。Hydro 的导入逻辑是：

```js
const files = await fs.readdir(tmpdir, { withFileTypes: true });
if (files.find((f) => f.name === 'problem.yaml')) problems = ['.'];
else problems = files.filter((f) => f.isDirectory()).map((i) => i.name);
// 之后逐个检查 <dir>/problem.yaml，没有就 continue 跳过
```

这个包里全是 `.zip` 文件、没有目录、根目录也没有 `problem.yaml`，所以**一道题都导不进去**，容易被误当成汇总包。已把它移到
`C:/Users/Asanagi/WorkBuddy/2026-10-25-21-04-28/_归档备份/`，改用真正可导入的 `2026syuctacm-weekly-04-hydro-all25.zip`。

### 7.3 重建汇总导入包

```python
# 逻辑：读取 25 个单题包 → 按 04-NN/ 前缀平铺到一个 ZIP
# 校验：根目录无 problem.yaml、25 个一级目录、无内嵌 ZIP、pid 唯一、用例数与 manifest 一致
```
结构要点：**一级目录名随意**（Hydro 不解析），本包用 `04-01`～`04-25`；每个目录里就是单题包内的原样内容（`problem.yaml`、`problem_zh.md`、`testdata/`）。
