# 01《字符串的头和尾》验证记录

## 复用的既有结果

- 盲审：`.tmp/01/blind-final/response.md`（全新只读轻量模型，仅给冻结公开题面/约束/样例/Judge 语义，无路径无代码）。结论与本题定义一致：`cin >> s` 读入、`length`/`front`/`back` 输出，复杂度 O(|s|) 时间、O(1) 额外空间，明确指出 |s|=1 首尾相同、整串同字符、|s|=1000 上界、CRLF 风险。`src/solution2.cpp` 即依此独立写法（`length()`/`front()`/`back()`），与主解 `size()`/下标写法相互独立。
- 无新增盲审，符合“已有合法盲审结果则复用”的要求。

## 本轮实际执行的验证（2026 环境，g++ 16.1.0，MinGW）

### 1. 官方验题器

```
pwsh -NoProfile -File C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/工具链/icpc-problem-creator/scripts/run-all-tests.ps1 \
  -Workspace C:/Users/Asanagi/Documents/ACM/ACM_Asanagi/SYUCTACM2026/SYUCT-ACM2026新生训练/2026syuctacm-weekly-04/problems/01
```

- 退出码 **0**，输出 `[success] 04-01 passed 33 cases.` / `全部测试通过。`
- 主解、solution2（reference）、validator、checker 全部通过；5 个 wrong 全部被击杀。
- 注：`-Workspace` 必须传绝对路径，脚本按 skill 根目录解析相对路径。

### 2. 差分对拍（固定种子 12345）

| 脚本 | 约束 | 轮数 | 结果 |
|---|---|---|---|
| `.tmp/01/verify/small-stress.py` | `|s| ≤ 20` 严格小数据，字母表含全 alphabet / `ab` / `a` / `z` | **200** | `status=passed`，0 mismatch |
| `.tmp/01/verify/stress-final.py` | 全范围，含 1/2/3/998/999/1000 定向长度 | **150** | `status=passed`，0 mismatch |

- 两个脚本均以 `main` 与 `solution2` 分别对照独立 oracle（Python 端 `len`/`s[0]`/`s[-1]`）比对。
- 无任何反例产生，因此无“反例修复”动作；`wrong_*` 在两种对拍下首次击杀轮次记录于 `small-stress-report.json` / `stress-report.json`，全部为 checker 判 WA（exit 0 但输出错），非意外 RE。
- 踩坑记录：Windows 文本模式 stdout 为 `\r\n`，脚本比较前必须规范化，否则误报 mismatch（曾出现一次假阳性，已修正比较逻辑）。

### 3. validator 严格性（静态编译，按 config 的 `-static`）

`g++ -std=gnu++17 -O2 -pipe -static` 编译后逐一测试：

- 合法：`a`、`hello`、`ab`、`a`×1000、`z`×1000 → 全部 rc=0；无行尾换行也 rc=0。
- 非法：空输入、`a b`（含空格）、`A`（大写）、`hello!`、`h3llo`、`a`×1001、前导空格 → 全部 rc=3（FAIL）。
- 尾部多余 token（`hello\nworld`）→ rc=3。

### 4. checker 严格性

- 接受：`5 h o`、`5 h o` 无换行、`5   h     o` 多空白、`5\nh\no` token 换行分隔 → rc=0。
- 拒绝：尾字符错、首尾颠倒、长度少 1、缺第 3 个 token（rc=2）、多第 4 个 token（rc=2）、尾字符长度 2、长度非数字（rc=2）、大小写不符 → 全部非 0。

### 5. generator

- 12 组 (type, seed) 重复执行 md5 一致 → 可复现。
- 33 个 config 用例全部生成成功且 100% 通过 validator；长度分布 min=1、max=1000；`sample` 组 2 个、`secret` 组 31 个。

### 6. 环境注意

本机 MinGW 下**非静态** testlib 程序（validator/generator/checker）会段错误（rc=139），必须用 config 中配置的 `-static` 编译；官方脚本已使用 `-static`，无影响。该现象不影响题目正确性，仅提醒本地手工调试时加 `-static`。

## 遗留风险

- 题目本身极简，无算法风险；主要剩余风险仅为“数据区分度”已由 5 类错解 + 定向用例覆盖。
- 未导出 ZIP（按任务要求）。
