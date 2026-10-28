# 回文判断题解

## 思路

长度为 $n$ 的字符串 $s$（下标从 $0$ 开始）是回文串，当且仅当对每个 $0\le i<n$ 都有

$$
s[i]=s[n-1-i].
$$

这个条件里每个位置都出现两次（$i$ 与 $n-1-i$ 互换后是同一个条件），因此只需检查前一半：对所有 $0\le i<\lfloor n/2\rfloor$ 比较 $s[i]$ 与 $s[n-1-i]$。奇数长度时正中间那个位置 $i=n/2$ 满足 $n-1-i=i$，是「自己和自己相等」，恒成立，不参与比较。

主解用**左右双指针**实现：`l = 0`、`r = n - 1`，只要 `l < r` 就比较 `s[l]` 与 `s[r]`，不同立刻判 `NO`；相同则 `++l`、`--r`，两个下标同时向中间收缩。这正是题面「提示」里描述的过程。

独立参考解 `src/solution2.cpp` **不维护可变的右下标**，而是直接由左下标推出镜像下标：`for (i = 0; i < n/2; ++i) if (s[i] != s[n-1-i])`。两条实现的错误面不同：主解可能写错 `--r` 或循环条件，参考解可能写错 `n-1-i` 的偏移。

## 正确性证明

记 $n=|s|$。以下对主解证明；参考解与它语义等价（见文末「两条实现的等价性」）。

**引理 1（下标不变式）**：第 $t$ 次进入循环体时（$t$ 从 $0$ 计），必有 $l=t$ 且 $r=n-1-t$。
*证明*：$t=0$ 时 $l=0$、$r=n-1$，成立。若第 $t$ 次迭代没有 `return`，则执行了 `++l; --r`，于是下一次进入时 $l=t+1$、$r=(n-1-t)-1=n-1-(t+1)$，归纳成立。$\square$

**引理 2（未提前退出则前 $t$ 对全等）**：若循环连续执行了 $t$ 次且一次都没有执行 `return`，则对所有 $0\le k<t$ 有 $s[k]=s[n-1-k]$。
*证明*：对 $t$ 归纳。$t=0$ 时命题空真。第 $t$ 次迭代比较的是 $s[t]$ 与 $s[n-1-t]$（引理 1），未退出意味着二者相等，与归纳假设合并即覆盖 $0\le k\le t$。$\square$

**引理 3（终止）**：循环必然终止，至多执行 $\lceil n/2\rceil$ 次。
*证明*：每轮 $r-l$ 严格减少 $2$，初值为 $n-1$，故有限轮后 $l\ge r$。$\square$

**定理**：算法输出 `NO` 当且仅当 $s$ 不是回文串。

*（$\Rightarrow$，输出 `NO` 必非回文）* 设算法在第 $t$ 次迭代输出 `NO`，此时 $s[t]\ne s[n-1-t]$，且由循环条件 $t=l<r=n-1-t$ 知 $0\le t\le n-1$ 且 $t\ne n-1-t$。取 $i=t$ 即违反回文的定义，故 $s$ 不是回文串。$\square$

*（$\Leftarrow$，输出 `YES` 必为回文）* 设循环正常结束而未输出 `NO`，共执行 $t$ 次迭代，此时 $l\ge r$，即 $t\ge n-1-t$。任取 $0\le i<n$，分三种情况：

1. $i<t$：由引理 2 直接得 $s[i]=s[n-1-i]$。
2. $n-1-i<t$：对下标 $n-1-i$ 用引理 2，得 $s[n-1-i]=s[n-1-(n-1-i)]=s[i]$。
3. 否则 $i\ge t$ 且 $n-1-i\ge t$。由 $n-1-i\ge t$ 得 $i\le n-1-t$；又 $t\ge n-1-t$，故 $t\le i\le n-1-t\le t$，即 $i=t=n-1-t$。此时等式两边是同一个位置，平凡成立（这正对应奇数长度的中心字符）。

三种情况穷尽全部下标，故 $s$ 满足回文定义。$\square$

两个方向合起来：输出 `NO` 与「非回文」等价，输出 `YES` 与「回文」等价；由于 `YES`/`NO` 互斥且穷尽，输出就是唯一正确答案。

**两条实现的等价性**：主解在第 $t$ 次迭代比较 $s[t]$ 与 $s[n-1-t]$（引理 1），参考解在第 $i$ 次迭代比较 $s[i]$ 与 $s[n-1-i]$，逐次对应相同；主解在 $l\ge r$ 时停止，参考解在 $i\ge\lfloor n/2\rfloor$ 时停止，而 $l\ge r\iff t\ge n-1-t\iff 2t\ge n-1\iff t\ge\lceil(n-1)/2\rceil=\lfloor n/2\rfloor$，停止条件也一致。因此两者对任意输入输出相同。

## 复杂度

设 $n=|s|$。

- 时间复杂度：读入 $O(n)$，至多比较 $\lfloor n/2\rfloor$ 对字符，合计 $O(n)$。$n\le 100000$ 时主解实测约 $20\,\text{ms}$（含进程启动），远低于 $1000\,\text{ms}$。
- 空间复杂度：`std::string` 存输入需 $O(n)$（不超过 $100\,\text{KB}$）；除输入串外只用两个 `int` 下标，额外辅助空间 $O(1)$，远低于 $256\,\text{MiB}$。

$n\le 100000$ 时下标最大 $99999$，`int` 足够；不使用 `size_t` 可以避免 `--r` 越过 $0$ 时发生无符号回绕。

## 边界情况

| 情形 | 期望 | 数据点 |
|---|---|---|
| $n=1$（最小值），字符为 `a` / `z` | `YES` | `min-a`、`min-z` |
| $n=2$ 两字符相同 / 不同 | `YES` / `NO` | `len2-yes-*`、`len2-no-*` |
| 奇数回文（含中心为 `z`） | `YES` | `odd-pal-*`、`odd-pal-center-z` |
| 偶数回文 | `YES` | `even-pal-*` |
| 只有最内层一对不同 | `NO` | `odd-inner-no-*`、`even-inner-no-*`、`mid-no-*` |
| 最外层一对就不同 | `NO` | `odd-outer-no-1`、`even-outer-no-1`、`border-no-*`、`max-outer-no` |
| 整串同一字符（含上限长度） | `YES` | `same-1`、`same-2`、`same-max` |
| 两字符交替（含上限长度） | 偶数长度 `YES`、奇数长度 `NO` | `alt-1`、`alt-2`、`alt-max` |
| 长度上限偶数/奇数回文 | `YES` | `max-even-pal`、`max-odd-pal`、`near-max-pal` |
| 长度上限，仅最内层一对不同 | `NO` | `max-even-inner-no`、`max-odd-inner-no` |
| 近上限随机串 | `NO` | `near-max-rand` |
| 随机小/中/大 | 混合 | `rand-small-*`、`rand-*`、`rand-pal-*` |

上限数据的长度分别为 $100000$（偶数）与 $99999$（奇数），既覆盖 $|s|=100000$ 的极值，也覆盖「最大合法奇数长度」这一相邻极值。

输入侧另有两条约定：数据以换行结束，且行内不含空白。validator 用 `inf.readLine()` 读整行、逐字符检查落在 `a`–`z`、检查长度 $\le 100000$，最后 `inf.readEof()`。实测（Windows 构建、严格模式）：接受 `\r\n` 结尾与 `\r\n` 后紧跟 EOF，拒绝空行、空文件、长度 $100001$、含大写、含空格、含数字、两行数据、多余空行以及无行尾换行的输入。

## 三层错解与定向数据

按「思路 / 复杂度 / 实现」三层枚举本题特有的错误，并给出实际击杀证据（checker 返回 WA 或进程超时）：

| 层次 | 错解 | 错误表现 | 实际击杀数据（首个） |
|---|---|---|---|
| 思路 | `wrong-inner-pair` | 循环条件写成 `l + 1 < r`，漏掉长度 2 与偶数长度最中心那一对 | `sample-5` 起共 7 点，含 `len2-no-1`、`even-inner-no-*`、`max-even-inner-no` |
| 思路 | `wrong-odd-is-no` | 把「回文」误解成「偶数长度才可能」，奇数长度一律输出 `NO` | `sample-1` 起共 13 点，含 `min-*`、`odd-pal-*`、`max-odd-pal` |
| 思路 | `wrong-ends-only` | 只比较首尾一对字符，内部错配全部漏判 | `sample-5` 起共 10 点，含 `odd-inner-no-*`、`mid-no-*`、`max-*-inner-no` |
| 复杂度 | `wrong-quadratic` | 判定逻辑正确，但每检查一个位置都重新构造一次完整反转串，$O(n^2)$ | 共 7 点超时：`max-even-pal` $8.1$ s、`max-odd-pal` $7.8$ s、`near-max-pal` $9.4$ s、`same-max` $8.2$ s、`rand-pal-odd` $4.9$ s、`max-odd-inner-no` $4.6$ s、`max-even-inner-no` $3.9$ s，均超过 $3000\,\text{ms}$ 的评测超时上限 |
| 实现 | `wrong-off-by-one` | 镜像下标写成 `n - i` 而不是 `n - 1 - i`，长度 $\ge 2$ 的回文几乎全被判 `NO` | `sample-2` 起共 20 点，含 `len2-yes-*`、`even-pal-*`、`same-max` |
| 实现 | `wrong-lowercase` | 判定完全正确，但输出小写 `yes` / `no`，违反输出格式 | 全部 49 点（`sample-1` 起） |

其中 `wrong-inner-pair`、`wrong-ends-only` 与强样例 5（`abxbba`：外层两对相同、只有最内层 `x`/`b` 不同）一一对应；`wrong-off-by-one` 被最简单的 `ababa`（`sample-2`）立即击杀。所有 WA 类错解都能正常读入、正常结束进程，**不依赖运行时异常或崩溃**来击杀；`wrong-quadratic` 是纯性能错误，在短数据上答案正确，只在上限回文上超时。

## 输出格式与 checker 语义

正确答案唯一。`src/checker/checker.cpp` 的判定规则是：从选手输出中读第一个空白分隔的 token，它必须恰好是 `YES` 或 `NO`，且之后不得再有非空白内容；行末空白（含 `\r\n`）忽略。因此以下输出判错：`yes`、`YES.`、`YES 1`、`YES\nNO`、空输出、只有空白。以下判对：`YES\n`、`YES\r\n`、`YES`（无换行）、`YES   \n`。评测器自身读取标准答案时也做同样校验，答案文件格式损坏会以 `_fail` 报出，而不会被当成选手错误。

## 独立盲审

公开题面冻结（SHA-256 `86c61a266c3da4bd56d30bcff4b616a474728fad4c5aea89bfa83730ecf72b70`，与当前 `docs/statement.md` 一致）后，另起一个**全新只读**会话做盲审，模型显式指定为 `wb2api/deepseek-v4.1-flash`，`--skills-dir` 指向空目录，提示词只含冻结题面、全部约束、五个样例、唯一答案的 Judge 语义与资源限制，不含工作区路径、算法、生成器、测试数据或任何代码，并明文禁止工具调用、文件读写与联网。

盲审结论：独立复述的任务、输入、输出与约束与题面完全一致；给出双指针算法；用「下标不变式 + 未提前退出则前 $t$ 对全等 + 终止性」证明了两个方向，并正确指出奇数中心是「自己与自己相等」的平凡情形；复杂度 $O(n)$ 时间、$O(1)$ 额外空间；边界清单覆盖长度 1、长度 2、奇偶回文与非回文、仅最内层一对不同、整串同字符、长度上限与 YES/NO 两类。它给出的 C++17 程序是 `src/solution2.cpp` 的依据；本仓库版本把双指针改写成由左下标直接推导镜像下标的写法，使参考解与主解的实现路径相互独立。盲审还独立指出了几个真实陷阱：`getline` 会把 `\r` 计入串长、输出大小写敏感、token 级判定的宽容边界，这些都已由题面措辞与实现方式覆盖。审查未发现其证明有跳步或循环论证，因此直接采纳，不需要重做盲审。

## 对拍

固定种子 `12345`，用**独立暴力**（构造反转串后整体比较，不做双指针或镜像下标推导）与主解、参考解三方对拍，共 **200 轮**小数据，覆盖随机串、回文、仅最内层错配、首尾错配、全同字符、二字符字母表、交替串与长度 1。结果 `OK 200 rounds (seed=12345)`，无反例，无需修复。同一对拍框架对错解 `wrong-ends-only` 在第 35 轮以输入 `aamaaaa` 稳定复现错误（该错解输出 `YES`，参考解与暴力均输出 `NO`），确认框架本身具备检出能力。

此外，全部 49 个静态数据点上，主解与参考解输出逐字节一致，且都被 checker 接受；validator 接受全部 49 个数据点，并对空串、超长、大写、含空格、含数字、多行、多余空行等非法输入全部拒绝。

## 参考实现（C++17）

主解 `src/solution.cpp`（左右双指针）：

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int l = 0;
    int r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            cout << "NO\n";
            return 0;
        }
        ++l;
        --r;
    }
    cout << "YES\n";
    return 0;
}
```

独立参考解 `src/solution2.cpp`（镜像下标）：

```cpp
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    const int n = static_cast<int>(s.size());

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}
```
