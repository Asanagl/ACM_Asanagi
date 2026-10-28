# 算法竞赛 C++ 模板

> 从竞赛到禁赛
>
> Asanagi_Sagiri

这份手册汇总了算法竞赛中常用的 C++ 模板，覆盖数论与组合计数、数据结构、图论、128 位整数、字符串、AC 自动机、动态规划与调试工具。示例默认使用 GNU C++17；代码采用紧凑但可调试的速敲风格：短命名、K&R 排版、关键处一行注释、保留 assert，便于赛时快速复现与排错。

## 目录

- [使用约定](#使用约定)
- [1. 数论](#1-数论)
- [2. 数据结构](#2-数据结构)
- [3. 图论](#3-图论)
- [4. 128 位整数](#4-128-位整数)
- [5. 精确整数函数](#5-精确整数函数)
- [6. 字符串](#6-字符串)
- [7. 实用工具](#7-实用工具)
- [8. 动态规划](#8-动态规划)
- [9. 基础算法补充](#9-基础算法补充)
- [10. 萌新向典题 Trick](#10-萌新向典题-trick)
- [复杂度速查](#复杂度速查)

## 使用约定

- 头文件统一 `#include <bits/stdc++.h>`，保留 `using namespace std;`。
- 索引、点编号、容器长度用 `int`；答案、距离、乘积用 `ll`。
- 不用 `#define int long long`、`#define endl`、`pb`/`all` 等宏；保留 `using ll = long long;` 和 `i128`/`u128` 别名。
- 结构体成员与局部变量用竞赛短名（`n, m, a, f, tr, lz, siz, fa, l, r, mid, ql, qr, res` 等）；对外接口保留直观名字（`find/merge/same`、`add/sum`、`power_mod`、`is_prime` 等）。
- K&R 括号，缩进 4 空格；短 if/for 可写一行；函数体内不留多余空行。
- 注释只留关键/易错处的一行（懒标记下传、128 位防溢出等），删掉解释性长注释；assert 等调试辅助保留。
- 图、树、并查集、树状数组、线段树默认 **1-based**；字符串和普通数组算法默认 **0-based**。
- 片段间依赖照旧：Dijkstra、SPFA、Prim 依赖 `Edge` 与 `Graph`，模逆元依赖 `exgcd`。

### 比赛代码骨架

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;  // 避免 64 位乘法溢出时使用
using u128 = __uint128_t;
using pii = pair<int, int>;

void Asanagi() {
    // 单组数据主逻辑
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) Asanagi();
    return 0;
}
```

## 1. 数论

### 1.1 64 位素数测试与整数分解

确定性 Miller-Rabin 判定 `uint64_t` 素性（`O(log n)` 次模乘），Pollard-Rho 分解无小因子合数（期望 `O(n^(1/4))`），结果升序返回。模乘用 `__uint128_t` 防溢出。

```cpp
using u64 = uint64_t;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u64)((u128)a * b % mod); // 128 位防溢出
}

u64 pow_mod(u64 a, u64 b, u64 mod) {
    u64 res = 1 % mod;
    while (b > 0) {
        if (b & 1) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool is_prime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    // 这组底数可确定性覆盖整个 uint64_t 范围
    constexpr u64 bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (u64 a : bases) {
        if (a % n == 0) continue;
        u64 x = pow_mod(a % n, d, n);
        if (x == 1 || x == n - 1) continue;
        bool witness = true;
        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                witness = false;
                break;
            }
        }
        if (witness) return false;
    }
    return true;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

u64 pollard_rho(u64 n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    while (true) {
        uniform_int_distribution<u64> pick(2, n - 2);
        u64 x = pick(rng), y = x, c = pick(rng), d = 1;
        auto nxt = [&](u64 v) { return (u64)(((u128)mul_mod(v, v, n) + c) % n); }; // f(v) = v^2 + c
        while (d == 1) { // Floyd 判环
            x = nxt(x);
            y = nxt(nxt(y));
            d = gcd(x > y ? x - y : y - x, n);
        }
        if (d != n) return d; // d == n 则本轮失败，重新随机
    }
}

void factor_dfs(u64 n, vector<u64>& fac) {
    if (n == 1) return;
    if (is_prime(n)) {
        fac.push_back(n);
        return;
    }
    u64 d = pollard_rho(n);
    factor_dfs(d, fac);
    factor_dfs(n / d, fac);
}

vector<u64> factorize(u64 n) {
    vector<u64> fac;
    factor_dfs(n, fac);
    sort(fac.begin(), fac.end()); // 统一升序返回
    return fac;
}
```

### 1.2 快速幂

`a^b mod mod`，要求 `b >= 0`、`mod > 0`；中间乘法用 `i128`，模数不超过有符号 64 位。

```cpp
using ll = long long;
using i128 = __int128_t;

ll power_mod(ll a, ll b, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    ll res = 1 % mod; // mod == 1 时答案为 0
    while (b > 0) {
        if (b & 1) res = (ll)((i128)res * a % mod); // i128 防溢出
        a = (ll)((i128)a * a % mod);
        b >>= 1;
    }
    return res;
}
```

### 1.3 线性筛

`O(n)` 筛出不超过 `n` 的全部素数，并记录每个数的最小质因子。

> [!WARNING]
> `mp` 每位置占 4 字节：洛谷 P3383（`n = 10^8`）实测峰值内存约 **416 MB**；只要素数表/素性标记时应换更省内存的筛法。

```cpp
struct LinearSieve {
    vector<int> mp; // mp[x]：x 的最小质因子
    vector<int> primes;

    explicit LinearSieve(int n) : mp(n + 1, 0) {
        for (int i = 2; i <= n; ++i) {
            if (mp[i] == 0) {
                mp[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > mp[i] || 1LL * i * p > n) break; // 每个合数只被最小质因子筛一次
                mp[i * p] = p;
            }
        }
    }

    bool is_prime(int x) const {
        return x >= 2 && mp[x] == x;
    }
};
```

### 1.4 扩展欧几里得

`exgcd(a, b, x, y)` 求 `a*x + b*y = gcd(a, b)`；`solve_linear_congruence` 解 `a*x = b (mod mod)`，返回 `{x0, period}`。

```cpp
using ll = long long;
using i128 = __int128_t;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x); // 交换 x、y 直接接住下一层系数
    y -= a / b * x;
    return g;
}

optional<pair<ll, ll>> solve_linear_congruence(ll a, ll b, ll mod) {
    assert(mod > 0);
    ll x, y;
    ll g = exgcd(a, mod, x, y);
    if (g < 0) {
        g = -g;
        x = -x;
        y = -y;
    }
    if (b % g != 0) return nullopt;
    ll period = mod / g; // 所有解按 period 循环
    ll x0 = (ll)((i128)x * (b / g) % period); // i128 防溢出
    if (x0 < 0) x0 += period;
    return pair{x0, period};
}
```

### 1.5 模逆元

`gcd(a, mod) = 1` 时逆元存在。exgcd 版适用任意正模数；费马小定理版仅限质数模数且 `a` 不被模数整除。依赖 1.4 的 `exgcd` 与 1.2 的 `power_mod`。

```cpp
using ll = long long;

optional<ll> inverse_mod(ll a, ll mod) {
    assert(mod > 0);
    a %= mod;
    if (a < 0) a += mod;
    ll x, y;
    if (exgcd(a, mod, x, y) != 1) return nullopt; // 仅 gcd == 1 时存在
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

ll inverse_prime_mod(ll a, ll p) {
    assert(a % p != 0);
    return power_mod(a, p - 2, p); // 费马小定理，p 必须为质数
}
```

### 1.6 卡特兰数

`C[n] = binom(2n, n) / (n + 1)`，递推 `C[n] = C[n-1] * (4n - 2) / (n + 1)` 中的除法必整除。`C[36]` 是最后一个能放进 `unsigned long long` 的值。无依赖版乘前约分防中间溢出，已过洛谷 P1044（`n <= 18`）。

```cpp
using u64 = unsigned long long;

vector<u64> catalan_u64(int n) {
    assert(0 <= n && n <= 36);
    vector<u64> c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        u64 num = 4ULL * i - 2, den = i + 1, pre = c[i - 1];
        u64 g = gcd(num, den); // 乘前约分，防中间溢出
        num /= g;
        den /= g;
        g = gcd(pre, den);
        pre /= g;
        den /= g;
        assert(den == 1);
        assert(pre <= numeric_limits<u64>::max() / num);
        c[i] = pre * num;
    }
    return c;
}
```

`n > 36` 用 Boost.Multiprecision。注意洛谷 C++17 评测环境（2026-07-25 实测）未提供该头文件，赛前确认平台支持。

```cpp
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

vector<cpp_int> catalan_exact(int n) {
    assert(n >= 0);
    vector<cpp_int> c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; ++i) c[i] = c[i - 1] * (4LL * i - 2) / (i + 1);
    return c;
}
```

### 1.7 循环引理

总和大于 0 时，从“最后一个最小前缀和”的后一位开始循环，可得所有非空前缀和严格为正的循环移位。`+1/-1` 序列总和为 `k > 0` 时恰有 `k` 个合法移位。

```cpp
using ll = long long;

int positive_rotation_start(const vector<ll>& a) {
    if (a.empty()) return 0;
    ll total = accumulate(a.begin(), a.end(), 0LL);
    if (total <= 0) return -1; // 总和不为正时不保证存在
    ll pre = 0, mi = 0;
    int st = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        pre += a[i];
        if (pre <= mi) { // <= 取最后一次最小值
            mi = pre;
            st = i + 1;
        }
    }
    return st % (int)a.size();
}
```

### 1.8 莫比乌斯反演入门

`mu(1) = 1`；含平方质因子则 `mu = 0`；否则 `k` 个不同质因子时 `mu = (-1)^k`。若 `F(n) = sum_{d|n} f(d)`，则 `f(n) = sum mu(d) * F(n / d)`。

```cpp
using ll = long long;

struct MobiusSieve {
    vector<int> mu, primes;
    vector<char> vis;

    explicit MobiusSieve(int n) : mu(n + 1, 0), vis(n + 1, false) {
        assert(n >= 1);
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                if (1LL * i * p > n) break;
                vis[i * p] = true;
                if (i % p == 0) { // i*p 含 p^2
                    mu[i * p] = 0;
                    break;
                }
                mu[i * p] = -mu[i];
            }
        }
    }
};

vector<ll> mobius_invert(const vector<ll>& F) {
    // 输入约定：F[n] = sum_{d | n} f[d]
    int n = (int)F.size() - 1;
    MobiusSieve s(n);
    vector<ll> f(n + 1, 0);
    for (int d = 1; d <= n; ++d) {
        if (s.mu[d] == 0) continue;
        for (int m = d; m <= n; m += d) f[m] += 1LL * s.mu[d] * F[m / d];
    }
    return f;
}

ll count_coprime_pairs(ll n, ll m, const vector<int>& mu) {
    // 1 <= x <= n, 1 <= y <= m 且 gcd(x, y) == 1 的有序对数
    int lim = (int)min(n, m);
    assert((int)mu.size() > lim);
    ll res = 0;
    for (int d = 1; d <= lim; ++d) res += 1LL * mu[d] * (n / d) * (m / d);
    return res;
}
```

## 2. 数据结构

### 2.1 树状数组

**1-based**。`add`/`sum` 均为 `O(log n)`；`lower_bound` 仅在增量全非负（前缀和单调）时可用。

```cpp
template <class T>
struct Fenwick {
    int n; // 有效下标 [1, n]
    vector<T> tr;

    explicit Fenwick(int n_) : n(n_), tr(n_ + 1, T{}) {}

    void add(int x, T d) {
        for (int i = x; i <= n; i += i & -i) tr[i] += d;
    }

    T sum(int x) const { // 前缀和 [1, x]
        T res{};
        for (int i = x; i > 0; i -= i & -i) res += tr[i];
        return res;
    }

    T range_sum(int l, int r) const {
        if (l > r) return T{};
        return sum(r) - sum(l - 1);
    }

    int lower_bound(T target) const { // 最小的 x 使 sum(x) >= target
        assert(target > T{});
        int x = 0;
        T cur{};
        int step = 1;
        while ((step << 1) <= n) step <<= 1; // 不超过 n 的最高二进制位
        for (; step > 0; step >>= 1) {
            int nx = x + step;
            if (nx <= n && cur + tr[nx] < target) {
                x = nx;
                cur += tr[nx];
            }
        }
        return x + 1;
    }
};
```

### 2.2 线段树

**1-based**，区间加 + 区间求和，单次 `O(log n)`。孩子用 `o<<1` / `o<<1|1`，懒标记 `lz` 存待下传的增量。

```cpp
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tr, lz; // tr：区间和；lz：待下传的区间加

    explicit SegTree(const vector<ll>& a) : n((int)a.size() - 1), tr(4 * n + 4), lz(4 * n + 4) {
        assert(n >= 1);
        build(1, 1, n, a);
    }

    void build(int o, int l, int r, const vector<ll>& a) {
        if (l == r) {
            tr[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(o << 1, l, mid, a);
        build(o << 1 | 1, mid + 1, r, a);
        pushup(o);
    }

    void pushup(int o) {
        tr[o] = tr[o << 1] + tr[o << 1 | 1];
    }

    void pushdown(int o, int l, int r) { // 懒标记下传
        if (lz[o] == 0 || l == r) return;
        int mid = (l + r) >> 1;
        tr[o << 1] += lz[o] * (mid - l + 1);
        lz[o << 1] += lz[o];
        tr[o << 1 | 1] += lz[o] * (r - mid);
        lz[o << 1 | 1] += lz[o];
        lz[o] = 0;
    }

    void modify(int ql, int qr, ll v) {
        modify(1, 1, n, ql, qr, v);
    }

    void modify(int o, int l, int r, int ql, int qr, ll v) { // 区间加
        if (ql <= l && r <= qr) {
            tr[o] += v * (r - l + 1);
            lz[o] += v;
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(o << 1, l, mid, ql, qr, v);
        if (qr > mid) modify(o << 1 | 1, mid + 1, r, ql, qr, v);
        pushup(o);
    }

    ll query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }

    ll query(int o, int l, int r, int ql, int qr) { // 区间和
        if (ql <= l && r <= qr) return tr[o];
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        ll res = 0;
        if (ql <= mid) res += query(o << 1, l, mid, ql, qr);
        if (qr > mid) res += query(o << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }
};
```

改成区间赋值版的要点（不另附代码）：
- 懒标记改为“整段赋为 v”：`tr[o] = v * (r - l + 1)`，`pushdown` 用覆盖而非累加；
- 需额外 `has_lz` 标记区分“无标记”和“整段赋 0”。

### 2.3 并查集

**1-based**，路径压缩 + 按大小合并，均摊近 `O(1)`；`merge` 返回是否真的合并。

```cpp
struct DSU {
    vector<int> fa, siz; // siz 只对根有意义
    int cnt;             // 集合数量

    explicit DSU(int n) : fa(n + 1), siz(n + 1, 1), cnt(n) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]); // 路径压缩
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y); // 小树并到大树
        fa[y] = x;
        siz[x] += siz[y];
        --cnt;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }
};
```

### 2.4 异或线性基

维护一组线性无关的二进制向量，可求最大子集异或和、判断可表示性、空间维数。处理 `uint64_t`，从高位向低位消元。

```cpp
using u64 = uint64_t;

struct XorBasis {
    static constexpr int BITS = 64;
    array<u64, BITS> b{};
    int rk = 0; // 线性无关向量数

    bool insert(u64 v) {
        for (int i = BITS - 1; i >= 0; --i) {
            if (((v >> i) & 1ULL) == 0) continue;
            if (b[i] == 0) {
                b[i] = v;
                ++rk;
                return true;
            }
            v ^= b[i]; // 消掉当前最高位
        }
        return false; // v 可由已有基异或得到
    }

    bool can_represent(u64 v) const {
        for (int i = BITS - 1; i >= 0; --i) {
            if ((v >> i) & 1ULL) v ^= b[i];
        }
        return v == 0;
    }

    u64 max_xor(u64 init = 0) const {
        u64 res = init;
        for (int i = BITS - 1; i >= 0; --i) res = max(res, res ^ b[i]);
        return res;
    }
};
```

### 2.5 分数类

分子分母始终约分、分母恒正；四则运算中间值用 `i128`，并断言结果能放入 `ll`；除法要求除数非零。

```cpp
using ll = long long;
using i128 = __int128_t;

struct Fraction {
    ll num = 0, den = 1; // den 始终为正

    Fraction() = default;

    Fraction(ll num_, ll den_ = 1) : num(num_), den(den_) {
        normalize();
    }

    static i128 gcd_i128(i128 a, i128 b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void normalize() {
        assert(den != 0);
        i128 a = num, b = den; // i128 处理 LLONG_MIN 取反等边界
        if (b < 0) {
            a = -a;
            b = -b;
        }
        i128 g = gcd_i128(a, b);
        a /= g;
        b /= g;
        assert(a >= numeric_limits<ll>::min() && a <= numeric_limits<ll>::max());
        assert(b >= 1 && b <= numeric_limits<ll>::max());
        num = (ll)a;
        den = (ll)b;
    }

    static Fraction from_i128(i128 a, i128 b) { // 四则运算统一在此约分并检查范围
        assert(b != 0);
        if (b < 0) {
            a = -a;
            b = -b;
        }
        i128 g = gcd_i128(a, b);
        a /= g;
        b /= g;
        assert(a >= numeric_limits<ll>::min() && a <= numeric_limits<ll>::max());
        assert(b >= 1 && b <= numeric_limits<ll>::max());
        Fraction res;
        res.num = (ll)a;
        res.den = (ll)b;
        return res;
    }

    friend Fraction operator+(const Fraction& x, const Fraction& y) {
        return from_i128((i128)x.num * y.den + (i128)y.num * x.den, (i128)x.den * y.den);
    }

    friend Fraction operator-(const Fraction& x, const Fraction& y) {
        return from_i128((i128)x.num * y.den - (i128)y.num * x.den, (i128)x.den * y.den);
    }

    friend Fraction operator*(const Fraction& x, const Fraction& y) {
        return from_i128((i128)x.num * y.num, (i128)x.den * y.den);
    }

    friend Fraction operator/(const Fraction& x, const Fraction& y) {
        assert(y.num != 0);
        i128 a = (i128)x.num * y.den, b = (i128)x.den * y.num;
        if (b < 0) {
            a = -a;
            b = -b;
        }
        return from_i128(a, b);
    }

    friend bool operator==(const Fraction& x, const Fraction& y) {
        return x.num == y.num && x.den == y.den;
    }

    friend bool operator<(const Fraction& x, const Fraction& y) {
        return (i128)x.num * y.den < (i128)y.num * x.den; // 分母均为正，可交叉相乘
    }

    friend ostream& operator<<(ostream& out, const Fraction& v) {
        out << v.num;
        if (v.den != 1) out << '/' << v.den;
        return out;
    }
};
```

### 2.6 取模类

面向小于 `2^32` 的质数模数；乘法用 `uint64_t` 承接，除法走费马小定理求逆（除数不能为 0）。

```cpp
template <uint32_t MOD>
class ModInt {
public:
    ModInt(long long v = 0) {
        v %= (long long)MOD;
        if (v < 0) v += MOD;
        x = (uint32_t)v;
    }

    uint32_t value() const {
        return x;
    }

    ModInt power(uint64_t b) const {
        ModInt a = *this, res = 1;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    ModInt inverse() const {
        assert(x != 0); // MOD 必须为质数
        return power(MOD - 2);
    }

    ModInt& operator+=(const ModInt& r) {
        uint64_t s = (uint64_t)x + r.x;
        x = (uint32_t)(s >= MOD ? s - MOD : s); // 最多减一次
        return *this;
    }

    ModInt& operator-=(const ModInt& r) {
        uint64_t d = x >= r.x ? x - r.x : (uint64_t)x + MOD - r.x; // 防无符号下溢
        x = (uint32_t)d;
        return *this;
    }

    ModInt& operator*=(const ModInt& r) {
        x = (uint32_t)((uint64_t)x * r.x % MOD); // MOD < 2^32，乘积可放入 u64
        return *this;
    }

    ModInt& operator/=(const ModInt& r) {
        return *this *= r.inverse();
    }

    friend ModInt operator+(ModInt l, const ModInt& r) { return l += r; }
    friend ModInt operator-(ModInt l, const ModInt& r) { return l -= r; }
    friend ModInt operator*(ModInt l, const ModInt& r) { return l *= r; }
    friend ModInt operator/(ModInt l, const ModInt& r) { return l /= r; }

    friend bool operator==(const ModInt& l, const ModInt& r) {
        return l.x == r.x;
    }

    friend ostream& operator<<(ostream& out, const ModInt& v) {
        return out << v.x;
    }

private:
    uint32_t x = 0;
};

using Z = ModInt<998244353>;
```

### 2.7 STL 自定义比较

比较器必须满足严格弱序。`sort`/`set` 是“小于”语义（返回 true 表示 `x` 排前面）；`priority_queue` 相反（返回 true 表示 `x` 排在 `y` 后面，即堆顶是“最不差”的元素）。`set` 视“互不小于”为等价：要保留同键不同字段的元素须加次关键字，允许完全重复用 `multiset`。只用一次的比较器可用 `decltype` 传 lambda（构造容器时带上它）。

```cpp
struct Person {
    string name;
    int age;
    int score;
};

// sort：lambda 直接当第三参数
void demo_sort(vector<Person>& v) {
    sort(v.begin(), v.end(), [](const Person& x, const Person& y) {
        if (x.score != y.score) return x.score > y.score; // 分数降序
        return x.age < y.age;                             // 同分年龄升序
    });
}

// tuple 同理；默认即字典序，常常无需比较器
using Item = tuple<int, string>;
void demo_tuple(vector<Item>& v) {
    sort(v.begin(), v.end(), [](const Item& x, const Item& y) {
        if (get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) < get<1>(y);
    });
}

// priority_queue：函数对象版
struct Cmp {
    bool operator()(const Person& x, const Person& y) const {
        if (x.score != y.score) return x.score < y.score; // 分数高者优先
        return x.age > y.age;
    }
};
priority_queue<Person, vector<Person>, Cmp> pq;

// set / multiset：函数对象版
struct Less {
    bool operator()(const Person& x, const Person& y) const {
        if (x.age != y.age) return x.age < y.age;
        return x.name < y.name; // 次关键字，避免同龄不同名被去重
    }
};
set<Person, Less> st;
multiset<Person, Less> mst;

// lambda 版：用 decltype 传类型，构造时传比较器
auto cmp = [](const Person& x, const Person& y) { return x.score < y.score; };
priority_queue<Person, vector<Person>, decltype(cmp)> pq2(cmp);
set<Person, decltype(cmp)> st2(cmp);
```

## 3. 图论

### 3.1 邻接矩阵

适合点数少的稠密图，空间 `O(n^2)`。**0-based**，重边保留最小边权。

```cpp
using ll = long long;

const ll INF = numeric_limits<ll>::max() / 4;

vector<vector<ll>> make_matrix(int n) {
    vector<vector<ll>> g(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) g[i][i] = 0;
    return g;
}

void add_directed_edge(vector<vector<ll>>& g, int u, int v, ll w) {
    g[u][v] = min(g[u][v], w); // 重边保留最小权值
}

void add_undirected_edge(vector<vector<ll>>& g, int u, int v, ll w) {
    add_directed_edge(g, u, v, w);
    add_directed_edge(g, v, u, w);
}
```

### 3.2 邻接表

适合大多数稀疏图。**1-based**，边记录终点与权值。

```cpp
using ll = long long;

struct Edge {
    int to;
    ll w;
};

using Graph = vector<vector<Edge>>;

void add_directed_edge(Graph& g, int u, int v, ll w = 1) {
    g[u].push_back({v, w});
}

void add_undirected_edge(Graph& g, int u, int v, ll w = 1) {
    add_directed_edge(g, u, v, w);
    add_directed_edge(g, v, u, w);
}
```

### 3.3 DFS 深度优先搜索

`O(n + m)`。深链状图递归可能爆栈，应改显式栈。

```cpp
void dfs(int u, const Graph& g, vector<char>& vis) {
    vis[u] = true;
    for (const Edge& e : g[u]) {
        if (!vis[e.to]) dfs(e.to, g, vis);
    }
}
```

### 3.4 BFS 广度优先搜索

无权图 `O(n + m)` 求最少边数；不可达点距离为 `-1`。

```cpp
vector<int> bfs(int s, const Graph& g) {
    int n = (int)g.size() - 1;
    vector<int> dis(n + 1, -1);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const Edge& e : g[u]) {
            if (dis[e.to] != -1) continue; // BFS 首次到达即最短
            dis[e.to] = dis[u] + 1;
            q.push(e.to);
        }
    }
    return dis;
}
```

### 3.5 Dijkstra 最短路

边权非负，二叉堆 `O((n + m) log n)`；弹出旧状态直接跳过，无需 `vis` 数组。依赖 3.2 的 `Edge`/`Graph`。

```cpp
using ll = long long;

vector<ll> dijkstra(int s, const Graph& g) {
    const ll INF = numeric_limits<ll>::max() / 4;
    int n = (int)g.size() - 1;
    vector<ll> dis(n + 1, INF);
    using State = pair<ll, int>; // {距离, 点}，小根堆
    priority_queue<State, vector<State>, greater<State>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]) continue; // 堆中旧状态
        for (const Edge& e : g[u]) {
            assert(e.w >= 0);
            if (dis[e.to] > d + e.w) {
                dis[e.to] = d + e.w;
                pq.push({dis[e.to], e.to});
            }
        }
    }
    return dis;
}
```

### 3.6 SPFA 与负环检测

可处理负边，检测从起点可达的负环（存在时返回 `nullopt`）。最坏 `O(nm)`，无负边优先 Dijkstra。

> [!CAUTION]
> 结果只覆盖 `s` 可达的点。洛谷 P3385 只要求 1 号点可达的负环，应调用 `spfa(1, g)`；不要加超级源，否则会把不连通分量中的负环误判进来。

```cpp
using ll = long long;

optional<vector<ll>> spfa(int s, const Graph& g) {
    const ll INF = numeric_limits<ll>::max() / 4;
    int n = (int)g.size() - 1;
    vector<ll> dis(n + 1, INF);
    vector<int> cnt(n + 1, 0); // 更新 dis[v] 的路径边数
    vector<char> inq(n + 1, false);
    queue<int> q;
    dis[s] = 0;
    inq[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (const Edge& e : g[u]) {
            int v = e.to;
            if (dis[v] <= dis[u] + e.w) continue;
            dis[v] = dis[u] + e.w;
            cnt[v] = cnt[u] + 1;
            if (cnt[v] >= n) return nullopt; // 含 n 条边的变短路径必过负环
            if (!inq[v]) {
                inq[v] = true;
                q.push(v);
            }
        }
    }
    return dis;
}
```

### 3.7 最小生成树（Prim）

无向图，`O((n + m) log n)`；图不连通返回 `nullopt`。

```cpp
using ll = long long;

optional<ll> prim(int s, const Graph& g) {
    int n = (int)g.size() - 1;
    vector<char> vis(n + 1, false);
    using State = pair<ll, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, s}); // 起点以权 0 的虚拟边入堆
    ll tot = 0;
    int used = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        tot += w;
        ++used;
        for (const Edge& e : g[u]) {
            if (!vis[e.to]) pq.push({e.w, e.to});
        }
    }
    if (used != n) return nullopt; // 图不连通
    return tot;
}
```

### 3.8 Floyd 全源最短路

`O(n^3)` 时间、`O(n^2)` 空间，适合点数少的稠密图。矩阵 **0-based**。

```cpp
using ll = long long;

vector<vector<ll>> floyd_warshall(vector<vector<ll>> dis) {
    const ll INF = numeric_limits<ll>::max() / 4;
    int n = (int)dis.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dis[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    return dis;
}
```

### 3.9 二分图最大匹配（匈牙利算法）

左右部均 **1-based**，`O(VE)`。逐个左部点找增广路，右部点已匹配则递归让原搭档改配。

```cpp
struct KuhnMatcher {
    int nl, nr;
    vector<vector<int>> g;
    vector<int> mt;  // 右部点当前匹配的左部点
    vector<int> vis; // 时间戳代替每轮清空
    int stamp = 0;

    KuhnMatcher(int nl_, int nr_) : nl(nl_), nr(nr_), g(nl_ + 1), mt(nr_ + 1, 0), vis(nr_ + 1, 0) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    bool augment(int u) {
        for (int v : g[u]) {
            if (vis[v] == stamp) continue;
            vis[v] = stamp;
            if (mt[v] == 0 || augment(mt[v])) { // v 空出，或其原搭档改配成功
                mt[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching() {
        int res = 0;
        for (int u = 1; u <= nl; ++u) {
            ++stamp;
            if (augment(u)) ++res;
        }
        return res;
    }
};
```

## 4. 128 位整数

GNU C++ 提供 `__int128_t`/`__uint128_t`，但标准流无原生 I/O 重载。以下转换函数支持符号并检查十进制越界。

### 4.1 字符串转换与输出

```cpp
using i128 = __int128_t;
using u128 = __uint128_t;

i128 parse_i128(string_view s) {
    assert(!s.empty());
    int pos = 0;
    bool neg = false;
    if (s[pos] == '+' || s[pos] == '-') {
        neg = s[pos] == '-';
        ++pos;
    }
    assert(pos < (int)s.size());
    const u128 neg_lim = (u128)1 << 127; // 负数绝对值上限比正数多 1
    const u128 lim = neg ? neg_lim : neg_lim - 1;
    u128 v = 0;
    for (; pos < (int)s.size(); ++pos) {
        assert(isdigit((unsigned char)s[pos]));
        int d = s[pos] - '0';
        assert(v <= (lim - d) / 10); // 乘 10 前检查越界
        v = v * 10 + d;
    }
    if (!neg) return (i128)v;
    if (v == neg_lim) return -(i128)(v - 1) - 1; // 最小 i128 不能直接取负
    return -(i128)v;
}

string to_string_i128(i128 v) {
    if (v == 0) return "0";
    bool neg = v < 0;
    u128 x = neg ? (u128)(-(v + 1)) + 1 : (u128)v; // 安全取得最小负数的绝对值
    string s;
    while (x > 0) {
        s.push_back((char)('0' + x % 10));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}
```

### 4.2 整数平方根

返回最大的 `x` 使 `x*x <= n`；用 `x <= n / x` 比较，避免接近 128 位上界时乘法溢出。

```cpp
using u128 = __uint128_t;

u128 sqrt_u128(u128 n) {
    u128 l = 0, r = ((u128)1 << 64) - 1; // 答案不超过 2^64 - 1
    while (l < r) {
        u128 mid = l + (r - l + 1) / 2; // 上中位数
        if (mid <= n / mid) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

### 4.3 最大公约数

```cpp
using u128 = __uint128_t;

u128 gcd_u128(u128 a, u128 b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
```

## 5. 精确整数函数

### 5.1 精确平方根

`sqrtl` 给初值，`i128` 双向校正，返回 `floor(sqrt(n))`，要求 `n >= 0`。

```cpp
using ll = long long;
using i128 = __int128_t;

ll integer_sqrt(ll n) {
    assert(n >= 0);
    ll x = (ll)sqrtl((long double)n); // 浮点只给初值
    while ((i128)(x + 1) * (x + 1) <= n) ++x; // 双向校正浮点误差
    while ((i128)x * x > n) --x;
    return x;
}
```

### 5.2 精确对数上取整

返回最小的非负整数 `k` 使 `base^k >= target`，要求 `base >= 2`、`target >= 1`。

```cpp
using ll = long long;
using i128 = __int128_t;

int ceil_log(ll base, ll target) {
    assert(base >= 2 && target >= 1);
    i128 v = 1;
    int k = 0;
    while (v < target) {
        v *= base;
        ++k;
    }
    return k;
}
```

## 6. 字符串

### 6.1 前缀函数（KMP）

`pi[i]` 为 `s[0..i]` 最长相等真前后缀长度；构造与匹配均 `O(n)`，**0-based**。

```cpp
vector<int> prefix_function(string_view s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1]; // 失配跳到次长 border
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> find_occurrences(string_view t, string_view p) {
    if (p.empty()) return {};
    vector<int> pi = prefix_function(p);
    vector<int> pos;
    int m = 0; // 已匹配的模式前缀长度
    for (int i = 0; i < (int)t.size(); ++i) {
        while (m > 0 && t[i] != p[m]) m = pi[m - 1];
        if (t[i] == p[m]) ++m;
        if (m == (int)p.size()) {
            pos.push_back(i - m + 1);
            m = pi[m - 1]; // 保留可重叠匹配
        }
    }
    return pos;
}
```

### 6.2 字典树（Trie）

小写字母，根编号 0，插入/查询 `O(|s|)`；`cnt` 区分重复插入。

```cpp
struct Trie {
    struct Node {
        array<int, 26> nxt{};
        int cnt = 0; // 在此结束的完整单词数
    };

    vector<Node> tr; // tr[0] 为根，0 同时表示空孩子

    Trie() : tr(1) {}

    static int idx(char c) {
        assert('a' <= c && c <= 'z');
        return c - 'a';
    }

    void insert(string_view s) {
        int u = 0;
        for (char c : s) {
            int i = idx(c);
            if (tr[u].nxt[i] == 0) {
                tr[u].nxt[i] = (int)tr.size();
                tr.push_back({});
            }
            u = tr[u].nxt[i];
        }
        ++tr[u].cnt;
    }

    int count(string_view s) const {
        int u = 0;
        for (char c : s) {
            int i = idx(c);
            if (tr[u].nxt[i] == 0) return 0;
            u = tr[u].nxt[i];
        }
        return tr[u].cnt;
    }

    bool starts_with(string_view s) const {
        int u = 0;
        for (char c : s) {
            int i = idx(c);
            if (tr[u].nxt[i] == 0) return false;
            u = tr[u].nxt[i];
        }
        return true;
    }
};
```

### 6.3 AC 自动机

多模式串匹配：扫描文本 `O(|text|)` 时只给当前状态计数，结束后按 BFS 逆序把次数回传给 fail 父节点（拓扑回传思路），即得每个模式串出现次数。

```cpp
using ll = long long;

struct AhoCorasick {
    struct Node {
        array<int, 26> nxt{};
        int fail = 0;
        ll cnt = 0;
    };

    vector<Node> tr;
    vector<int> ord; // BFS 序

    AhoCorasick() : tr(1) {}

    static int idx(char c) {
        assert('a' <= c && c <= 'z');
        return c - 'a';
    }

    int insert(string_view p) {
        int u = 0;
        for (char c : p) {
            int i = idx(c);
            if (tr[u].nxt[i] == 0) {
                tr[u].nxt[i] = (int)tr.size();
                tr.push_back({});
            }
            u = tr[u].nxt[i];
        }
        return u; // 返回终止节点，之后直接读出现次数
    }

    void build() {
        queue<int> q;
        ord.clear();
        for (int i = 0; i < 26; ++i) {
            int v = tr[0].nxt[i];
            if (v != 0) {
                tr[v].fail = 0;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ord.push_back(u);
            for (int i = 0; i < 26; ++i) {
                int v = tr[u].nxt[i];
                if (v != 0) {
                    tr[v].fail = tr[tr[u].fail].nxt[i];
                    q.push(v);
                } else {
                    tr[u].nxt[i] = tr[tr[u].fail].nxt[i]; // 补全 Trie 图，扫描时一次转移
                }
            }
        }
    }

    void scan(string_view t) {
        int u = 0;
        for (char c : t) {
            u = tr[u].nxt[idx(c)];
            ++tr[u].cnt;
        }
    }

    void propagate() {
        for (int i = (int)ord.size() - 1; i >= 0; --i) { // BFS 逆序回传给 fail
            int u = ord[i];
            tr[tr[u].fail].cnt += tr[u].cnt;
        }
    }

    ll occurrences(int u) const {
        return tr[u].cnt;
    }

    void clear_counts() { // 复用自动机前清空统计
        for (Node& nd : tr) nd.cnt = 0;
    }
};

vector<ll> count_patterns(const vector<string>& ps, string_view t) {
    AhoCorasick ac;
    vector<int> ter;
    ter.reserve(ps.size());
    for (const string& p : ps) ter.push_back(ac.insert(p));
    ac.build();
    ac.scan(t);
    ac.propagate();
    vector<ll> res;
    res.reserve(ps.size());
    for (int u : ter) res.push_back(ac.occurrences(u));
    return res;
}
```

## 7. 实用工具

### 7.1 作用域计时器

RAII：离开作用域自动把耗时写入 `cerr`，不污染正常输出。

```cpp
class ScopedTimer {
public:
    explicit ScopedTimer(string lab = "elapsed") : lab(move(lab)), st(chrono::steady_clock::now()) {}

    ~ScopedTimer() {
        auto ed = chrono::steady_clock::now();
        double ms = chrono::duration<double, milli>(ed - st).count();
        cerr << lab << ": " << fixed << setprecision(3) << ms << " ms\n";
    }

private:
    string lab;
    chrono::steady_clock::time_point st;
};
```

### 7.2 随机数据生成器

`uniform_int_distribution` 两端均包含；固定种子复现错误，时间种子用于压力测试。

```cpp
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class Int>
vector<Int> random_integers(Int l, Int r, int cnt) {
    static_assert(is_integral_v<Int>);
    assert(l <= r && cnt >= 0);
    uniform_int_distribution<Int> dis(l, r);
    vector<Int> a;
    a.reserve(cnt);
    for (int i = 0; i < cnt; ++i) a.push_back(dis(rng));
    return a;
}
```

### 7.3 组合类型哈希

SplitMix64 扰动 + 随机盐，降低哈希碰撞攻击风险。不要向 `namespace std` 加 `tuple` 偏特化，把自定义哈希作为容器第三个模板参数传入。

```cpp
uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

void hash_combine(size_t& seed, size_t v) {
    static const uint64_t salt = chrono::steady_clock::now().time_since_epoch().count(); // 每次启动换盐
    seed ^= splitmix64((uint64_t)v + salt + seed);
}

struct PairHash {
    template <class A, class B>
    size_t operator()(const pair<A, B>& p) const {
        size_t seed = 0;
        hash_combine(seed, hash<A>{}(p.first));
        hash_combine(seed, hash<B>{}(p.second));
        return seed;
    }
};

struct TupleHash {
    template <class... Ts>
    size_t operator()(const tuple<Ts...>& t) const {
        size_t seed = 0;
        apply([&](const auto&... x) { (hash_combine(seed, hash<decay_t<decltype(x)>>{}(x)), ...); }, t);
        return seed;
    }
};

unordered_set<pair<int, int>, PairHash> points;
unordered_set<tuple<int, string, double>, TupleHash> records;
```

### 7.4 字符串流

`istringstream` 解析、`ostringstream` 拼接；解析失败后流进入失败状态，可直接作循环条件。

```cpp
string normalize_integer_list(string_view s) {
    istringstream in{string(s)}; // 自动跳过空白
    vector<int> a;
    for (int x; in >> x;) a.push_back(x);
    ostringstream out;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (i > 0) out << ' ';
        out << a[i];
    }
    return out.str();
}
```

## 8. 动态规划

按顺序回答四个问题：`dp` 状态含义、转移来源、初始/不可达状态、枚举顺序是否保证来源已算好。

### 8.1 线性 DP：青蛙跳跃

`dp[i]` = 到达位置 `i` 的最小代价，只依赖前至多 `k` 个状态。

```cpp
using ll = long long;

ll minimum_frog_cost(const vector<ll>& h, int k) {
    int n = (int)h.size();
    if (n == 0) return 0;
    const ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k && j <= i; ++j) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
    return dp[n - 1];
}
```

### 8.2 0/1 背包与完全背包

`dp[c]` = 容量不超过 `c` 的最大价值。0/1 背包倒序枚举容量（每件一次），完全背包正序（可重复）。

```cpp
using ll = long long;

ll knapsack_01(const vector<int>& w, const vector<ll>& v, int C) {
    assert(w.size() == v.size());
    vector<ll> dp(C + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i) {
        assert(w[i] > 0);
        for (int c = C; c >= w[i]; --c) dp[c] = max(dp[c], dp[c - w[i]] + v[i]); // 倒序：每件只用一次
    }
    return dp[C];
}

ll complete_knapsack(const vector<int>& w, const vector<ll>& v, int C) {
    assert(w.size() == v.size());
    vector<ll> dp(C + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i) {
        assert(w[i] > 0);
        for (int c = w[i]; c <= C; ++c) dp[c] = max(dp[c], dp[c - w[i]] + v[i]); // 正序：可重复选
    }
    return dp[C];
}
```

### 8.3 按价值定义的 0/1 背包

容量大、总价值小时改用 `dp[v] = 取得价值 v 的最小重量`（AtCoder DP Contest E 套路）。

```cpp
using ll = long long;

int knapsack_by_value(const vector<ll>& w, const vector<int>& v, ll C) {
    assert(w.size() == v.size());
    int V = accumulate(v.begin(), v.end(), 0);
    const ll INF = numeric_limits<ll>::max() / 4;
    vector<ll> dp(V + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < (int)w.size(); ++i) {
        for (int c = V; c >= v[i]; --c) { // 仍是 0/1 背包，倒序
            if (dp[c - v[i]] == INF) continue;
            dp[c] = min(dp[c], dp[c - v[i]] + w[i]);
        }
    }
    for (int res = V; res >= 0; --res) {
        if (dp[res] <= C) return res;
    }
    return 0;
}
```

### 8.4 最长上升子序列（LIS）

`t[i]` = 长度 `i + 1` 的严格上升子序列的最小末尾；`t` 不是实际 LIS，但其长度即答案。

```cpp
template <class T>
int lis_length(const vector<T>& a) {
    vector<T> t;
    for (const T& x : a) {
        auto it = lower_bound(t.begin(), t.end(), x); // 严格上升；非严格改用 upper_bound
        if (it == t.end()) t.push_back(x);
        else *it = x; // 更小末尾为后续留空间
    }
    return (int)t.size();
}
```

### 8.5 最长公共子序列（LCS）与方案恢复

`dp[i][j]` = `a` 前 `i` 字符与 `b` 前 `j` 字符的 LCS 长度；沿来源倒推恢复方案。

```cpp
string longest_common_subsequence(string_view a, string_view b) {
    int n = (int)a.size(), m = (int)b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) --i;
        else --j;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

### 8.6 区间 DP

`f[l][r]` 表示区间 `[l, r]` 上的最优解。按长度从小到大枚举，保证转移用到的子区间已算好；长度→起点→分割点三重循环，`O(n^3)` 时间、`O(n^2)` 空间。

```cpp
for (int len = 2; len <= n; ++len) {     // 枚举区间长度
    for (int l = 0; l + len <= n; ++l) { // 枚举起点
        int r = l + len - 1;
        for (int m = l; m < r; ++m)      // 枚举分割点
            f[l][r] = min(f[l][r], f[l][m] + f[m + 1][r] + cost(l, r));
    }
}
```

**合并石子（直线版，洛谷 P1880 的一半）**：`dp[l][r]` = 合并 `[l, r]` 成一堆的最小代价；最后一次合并必在某个 `m` 处分成两段，区间和用前缀和 `O(1)` 取得。

```cpp
using ll = long long;

ll minimum_merge_cost(const vector<ll>& a) {
    int n = (int)a.size();
    if (n == 0) return 0;
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + a[i];
    const ll INF = numeric_limits<ll>::max() / 4;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int len = 2; len <= n; ++len) { // 短区间先算
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            ll sum = pre[r + 1] - pre[l];
            dp[l][r] = INF;
            for (int m = l; m < r; ++m) dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + sum);
        }
    }
    return dp[0][n - 1];
}
```

**环形石子合并（洛谷 P1880）**：破环成链——数组复制一倍，只枚举长度 `<= n` 的区间，最后对所有长度为 `n` 的区间取最优。求最大值把 `min` 换 `max`、初值 `INF` 换 `0` 即可。

```cpp
using ll = long long;

ll min_ring_merge_cost(const vector<ll>& a) {
    int n = (int)a.size();
    if (n == 0) return 0;
    vector<ll> b(2 * n); // 破环成链
    for (int i = 0; i < 2 * n; ++i) b[i] = a[i % n];
    vector<ll> pre(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) pre[i + 1] = pre[i] + b[i];
    const ll INF = numeric_limits<ll>::max() / 4;
    vector<vector<ll>> f(2 * n, vector<ll>(2 * n, 0));
    for (int len = 2; len <= n; ++len) { // 长度不超过 n
        for (int l = 0; l + len <= 2 * n; ++l) {
            int r = l + len - 1;
            ll sum = pre[r + 1] - pre[l];
            f[l][r] = INF;
            for (int m = l; m < r; ++m) f[l][r] = min(f[l][r], f[l][m] + f[m + 1][r] + sum);
        }
    }
    ll res = INF;
    for (int l = 0; l < n; ++l) res = min(res, f[l][l + n - 1]); // 枚举环的起点
    return res;
}
```

**回文类：最长回文子序列**：`f[l][r]` = `s[l..r]` 内最长回文子序列长度。两端相等则同时入选，否则丢掉较差的一端。`O(n^2)`。

```cpp
int longest_palindrome_subseq(string_view s) {
    int n = (int)s.size();
    if (n == 0) return 0;
    vector<vector<int>> f(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1] + 2; // len == 2 时取到全 0 的非法区间，不影响正确性
            else f[l][r] = max(f[l + 1][r], f[l][r - 1]);
        }
    }
    return f[0][n - 1];
}
```

**四边形不等式优化**：当代价满足四边形不等式且最优分割点单调（`opt[l][r-1] <= opt[l][r] <= opt[l+1][r]`）时，分割点只需在 `[opt[l][r-1], opt[l+1][r]]` 内枚举，可把 `O(n^3)` 降到 `O(n^2)`。适用面窄，用前需验证条件，不附代码。

### 8.7 树形 DP：最大权独立集

`dp[u][0/1]` = 不选/选 `u` 时其子树的最大答案。

```cpp
using ll = long long;

void tree_dp_dfs(int u, int fa, const vector<vector<int>>& tr, const vector<ll>& w, vector<array<ll, 2>>& dp) {
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (int v : tr[u]) {
        if (v == fa) continue;
        tree_dp_dfs(v, u, tr, w, dp);
        dp[u][0] += max(dp[v][0], dp[v][1]); // 不选 u，孩子任选
        dp[u][1] += dp[v][0];                // 选 u，孩子不能选
    }
}

ll maximum_weight_independent_set(const vector<vector<int>>& tr, const vector<ll>& w, int root = 1) {
    vector<array<ll, 2>> dp(tr.size());
    tree_dp_dfs(root, 0, tr, w, dp);
    return max(dp[root][0], dp[root][1]);
}
```

### 8.8 状态压缩 DP：最短哈密顿路径

从 0 号点出发恰好访问每点一次、在 `n - 1` 号点结束。`dp[mask][u]` = 已访问集合为 `mask`、当前在 `u` 的最短距离。

```cpp
using ll = long long;

ll shortest_hamilton_path(const vector<vector<ll>>& w) {
    int n = (int)w.size();
    if (n == 0) return 0;
    assert(n <= 20); // 状态数 2^n
    const ll INF = numeric_limits<ll>::max() / 4;
    int S = 1 << n;
    vector<vector<ll>> dp(S, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (int mask = 0; mask < S; ++mask) {
        for (int u = 0; u < n; ++u) {
            if (((mask >> u) & 1) == 0 || dp[mask][u] == INF) continue;
            for (int v = 0; v < n; ++v) {
                if ((mask >> v) & 1) continue;
                if (w[u][v] == INF) continue; // 无边
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    return dp[S - 1][n - 1];
}
```

### 8.9 数位 DP：统计指定数位和

统计 `[0, up]` 中数位和等于 `ts` 的整数个数。只有 `tight == false` 的状态可以记忆化。

```cpp
using ll = long long;

ll count_with_digit_sum(ll up, int ts) {
    if (up < 0 || ts < 0) return 0;
    string dig = to_string(up);
    int len = (int)dig.size();
    vector<vector<ll>> memo(len, vector<ll>(ts + 1, -1));
    // pos：当前位；s：已选数位和；tight：是否贴住上界
    function<ll(int, int, bool)> dfs = [&](int pos, int s, bool tight) {
        if (s > ts) return 0LL;
        if (pos == len) return s == ts ? 1LL : 0LL;
        if (!tight && memo[pos][s] != -1) return memo[pos][s];
        int lim = tight ? dig[pos] - '0' : 9;
        ll res = 0;
        for (int d = 0; d <= lim; ++d) res += dfs(pos + 1, s + d, tight && d == lim);
        if (!tight) memo[pos][s] = res; // 只有不贴上界的状态可记忆化
        return res;
    };
    return dfs(0, 0, true);
}

ll count_with_digit_sum(ll l, ll r, int ts) {
    return count_with_digit_sum(r, ts) - count_with_digit_sum(l - 1, ts);
}
```

### 8.10 DAG 上的 DP：最长路径

拓扑序保证处理 `u` 时前驱已完成转移；返回到每个点的最长边数，有环返回 `nullopt`。

```cpp
optional<vector<int>> longest_path_in_dag(const vector<vector<int>>& g) {
    int n = (int)g.size() - 1;
    vector<int> ind(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) ++ind[v];
    }
    queue<int> q;
    vector<int> dp(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        if (ind[u] == 0) q.push(u);
    }
    int cnt = 0;
    while (!q.empty()) { // Kahn 拓扑
        int u = q.front();
        q.pop();
        ++cnt;
        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--ind[v] == 0) q.push(v);
        }
    }
    if (cnt != n) return nullopt; // 有环
    return dp;
}
```

## 9. 基础算法补充

前文未覆盖的基础模板；排序直接用 `std::sort`。

### 9.1 整数二分答案

`first_true` 找第一个满足单调谓词的位置（要求右端点满足）；`last_true` 对称。

```cpp
using ll = long long;

template <class F>
ll first_true(ll l, ll r, F check) {
    assert(l <= r && check(r));
    while (l < r) {
        ll mid = l + (r - l) / 2; // 下中位数，check(mid) 为真时保留 mid
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

template <class F>
ll last_true(ll l, ll r, F check) {
    assert(l <= r && check(l));
    while (l < r) {
        ll mid = l + (r - l + 1) / 2; // 上中位数
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

### 9.2 双指针与滑动窗口

元素非负时左右端点均单调右移。求和不超过 `lim` 的最长连续子数组。

```cpp
using ll = long long;

int longest_window_sum_at_most(const vector<ll>& a, ll lim) {
    assert(lim >= 0);
    int l = 0, res = 0;
    ll sum = 0;
    for (int r = 0; r < (int)a.size(); ++r) {
        assert(a[r] >= 0);
        sum += a[r];
        while (l <= r && sum > lim) sum -= a[l++];
        res = max(res, r - l + 1);
    }
    return res;
}
```

### 9.3 归并排序统计逆序对

合并时右侧元素小于左侧当前元素，则左侧剩余元素全与它构成逆序对。

```cpp
using ll = long long;

template <class T>
ll inv_impl(vector<T>& a, vector<T>& buf, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    ll res = inv_impl(a, buf, l, m) + inv_impl(a, buf, m, r);
    int i = l, j = m, k = l;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j])) buf[k++] = a[i++];
        else {
            buf[k++] = a[j++];
            res += m - i; // a[i..m) 都与它构成逆序对
        }
    }
    copy(buf.begin() + l, buf.begin() + r, a.begin() + l);
    return res;
}

template <class T>
ll inversion_count(vector<T> a) { // 按值传参，不改原数组
    vector<T> buf(a.size());
    return inv_impl(a, buf, 0, (int)a.size());
}
```

### 9.4 回溯枚举排列

`path` 存当前排列，`used[x]` 标记已选。总复杂度 `O(n * n!)`。

```cpp
template <class F>
void enumerate_permutations(int n, F process) {
    vector<int> path;
    vector<char> used(n + 1, false);
    function<void()> dfs = [&]() {
        if ((int)path.size() == n) {
            process(path);
            return;
        }
        for (int x = 1; x <= n; ++x) {
            if (used[x]) continue;
            used[x] = true;
            path.push_back(x);
            dfs();
            path.pop_back(); // 回溯撤销
            used[x] = false;
        }
    };
    dfs();
}
```

### 9.5 回溯寻找子集和

返回一组下标使所选元素和等于 `target`。元素可为负，因此不做“和超过目标就剪枝”。

```cpp
using ll = long long;

optional<vector<int>> find_subset_sum(const vector<ll>& a, ll target) {
    vector<int> sel;
    function<bool(int, ll)> dfs = [&](int i, ll rem) {
        if (rem == 0) return true;
        if (i == (int)a.size()) return false;
        sel.push_back(i); // 选 a[i]
        if (dfs(i + 1, rem - a[i])) return true;
        sel.pop_back();
        return dfs(i + 1, rem); // 不选
    };
    if (!dfs(0, target)) return nullopt;
    return sel;
}
```

### 9.6 区间调度贪心

半开区间 `[l, r)` 按右端点排序，每次选最早结束且不重叠的区间，得最多区间数。

```cpp
using ll = long long;

struct Interval {
    ll l, r;
};

int maximum_non_overlapping_intervals(vector<Interval> a) {
    sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
        if (x.r != y.r) return x.r < y.r; // 最早结束优先
        return x.l < y.l;
    });
    ll ed = numeric_limits<ll>::min();
    int res = 0;
    for (const Interval& v : a) {
        assert(v.l <= v.r);
        if (v.l >= ed) { // 半开区间，端点相接不冲突
            ++res;
            ed = v.r;
        }
    }
    return res;
}
```

## 10. 萌新向典题 Trick

赛时高频小套路，每条配最简代码。

### 10.1 快速读入

关了 `sync_with_stdio` 还不够快（整数读取量 10^6 级以上）时用手写快读。

```cpp
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') { // 跳过符号与前缀空白
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
```

### 10.2 前缀和与差分

前缀和把区间和变成 `O(1)` 查询；差分把区间加变成 `O(1)` 修改，最后统一求前缀和还原。一维差分典题洛谷 P2367，二维差分典题 P3397。

```cpp
// 一维前缀和：s[i] = a[1..i]，区间和 [l, r] = s[r] - s[l - 1]
vector<ll> s(n + 1, 0);
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

// 一维差分：区间 [l, r] 加 v
vector<ll> d(n + 2, 0);
d[l] += v;
d[r + 1] -= v;
// 全部修改完后还原：for (int i = 1; i <= n; ++i) d[i] += d[i - 1];
```

```cpp
// 二维前缀和：s[i][j] = (1,1)~(i,j) 的和
for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
// 子矩阵和 (x1,y1)~(x2,y2)
ll sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];

// 二维差分：子矩阵 (x1,y1)~(x2,y2) 加 v
d[x1][y1] += v;
d[x2 + 1][y1] -= v;
d[x1][y2 + 1] -= v;
d[x2 + 1][y2 + 1] += v;
// 最后对整个 d 求二维前缀和还原
```

### 10.3 离散化

值域大但元素少时，把原值映射为排名（1-based）。

```cpp
vector<int> v(a); // 复制一份
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end()); // 去重
// x 的离散化值：
int id = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
```

### 10.4 整数取整与常见公式

向上取整 `(a + b - 1) / b`（要求 `b > 0`）；口诀：乘除前先转 `ll`（`1LL * a * b`），防止 int 乘法中途溢出。

```cpp
using ll = long long;

int ceil_div(int a, int b) { // a / b 向上取整，b > 0
    assert(b > 0);
    if (a >= 0) return (a + b - 1) / b;
    return a / b; // 负数时 C++ 整除本身向零取整，恰好是向上取整
}

ll safe_mul(int a, int b) { // 先转 ll 再乘，防溢出
    return 1LL * a * b;
}
```

### 10.5 常用 STL 速查

```cpp
sort(v.begin(), v.end());                                 // 升序
sort(v.begin(), v.end(), greater<int>());                 // 降序
v.erase(unique(v.begin(), v.end()), v.end());             // 去重（先排序）
int rk = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()); // 第一个 >= x 的下标
int cnt = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)); // x 出现次数
__builtin_popcount(x);     // 二进制中 1 的个数（ll 用 __builtin_popcountll）
__builtin_ctz(x);          // 最低位 1 的位置，x != 0（ll 用 __builtin_ctzll）
nth_element(v.begin(), v.begin() + k, v.end()); // O(n) 让 v[k] 成为第 k 小
```

### 10.6 中位数贪心

货仓选址类：数轴上选一点使到所有点的距离和最小，答案取中位数（偶数个取中间两点之一均可）。

```cpp
using ll = long long;

ll min_total_distance(vector<ll> a) {
    sort(a.begin(), a.end());
    ll mid = a[a.size() / 2]; // 中位数
    ll res = 0;
    for (ll x : a) res += abs(x - mid);
    return res;
}
```

## 复杂度速查

| 模板 | 时间复杂度 | 空间复杂度 | 关键前置条件 |
| --- | --- | --- | --- |
| Miller-Rabin | `O(k log n)` 次模乘 | `O(1)` | 使用 64 位确定性底数集 |
| Pollard-Rho | 期望约 `O(n^(1/4))` | 与递归深度相关 | 随机算法，输入 `n >= 1` |
| 线性筛 | `O(n)` | `O(n)` | 预处理上界已知 |
| 卡特兰数递推 | `O(n)` | `O(n)` | 精确值增长很快 |
| 循环引理找合法起点 | `O(n)` | `O(1)` | 序列总和大于 0 |
| 莫比乌斯线性筛 | `O(n)` | `O(n)` | 预处理上界已知 |
| 莫比乌斯反演 | `O(n log n)` | `O(n)` | 已知所有因数和 `F(n)` |
| 树状数组 | 单次 `O(log n)` | `O(n)` | 1-based |
| 懒标记线段树 | 单次 `O(log n)` | `O(n)` | 1-based，区间加/求和 |
| 并查集 | 均摊 `O(alpha(n))` | `O(n)` | 1-based |
| 异或线性基 | 单次 `O(64)` | `O(64)` | `uint64_t` |
| DFS / BFS | `O(n + m)` | `O(n)` | 邻接表 |
| Dijkstra | `O((n + m) log n)` | `O(n + m)` | 边权非负 |
| SPFA | 最坏 `O(nm)` | `O(n + m)` | 可处理负边 |
| Prim | `O((n + m) log n)` | `O(n + m)` | 无向图 |
| Floyd | `O(n^3)` | `O(n^2)` | 点数较少 |
| 二分图匈牙利算法 | `O(VE)` | `O(V + E)` | 已知左右部点集 |
| KMP | `O(n + m)` | `O(m)` | 0-based |
| Trie | 单次 `O(|s|)` | 与节点数成正比 | 当前版本仅含 `a-z` |
| AC 自动机 | 构建 `O(26S)`，查询 `O(T + S)` | `O(26S)` | 当前版本仅含 `a-z` |
| 0/1 / 完全背包 | `O(nV)` | `O(V)` | 容量 `V` 可承受 |
| LIS | `O(n log n)` | `O(n)` | 严格上升用 `lower_bound` |
| LCS | `O(nm)` | `O(nm)` | 当前版本需要恢复方案 |
| 区间 DP | `O(n^3)` | `O(n^2)` | 合并石子模型 |
| 树形 DP | `O(n)` | `O(n)` | 输入为树 |
| 状态压缩 DP | `O(2^n n^2)` | `O(2^n n)` | 通常 `n <= 20` |
| 数位 DP | 状态数乘每位 10 种转移 | 与状态数成正比 | 按数位从高到低搜索 |
| DAG DP | `O(n + m)` | `O(n + m)` | 图必须无环 |
| 整数二分答案 | `O(log R)` 次检查 | `O(1)` | `check` 具有单调性 |
| 双指针滑动窗口 | `O(n)` | `O(1)` | 当前模板要求元素非负 |
| 归并统计逆序对 | `O(n log n)` | `O(n)` | 元素支持比较 |
| 排列回溯 | `O(n * n!)` | `O(n)` | 仅适合较小 `n` |
| 子集和回溯 | `O(2^n)` | `O(n)` | 仅适合较小 `n` |
| 区间调度 | `O(n log n)` | `O(n)` | 半开区间，按右端点贪心 |
