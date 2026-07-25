#include <bits/stdc++.h>
using namespace std;

// 快速幂：计算 (base^power) % mod
long long fastpow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = fastpow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, M = 2e6 + 5, mod = 998244353;
    cin >> t;

    // 预处理阶乘 f[i] = i! % mod
    vector<int> f(M), g(M);
    f[0] = 1;
    for (int i = 1; i < M; i++) {
        f[i] = 1ll * f[i - 1] * i % mod;
    }

    // 预处理阶乘的逆元 g[i] = (i!)^(-1) % mod
    g[M - 1] = fastpow(f[M - 1], mod - 2, mod);       // 费马小定理求最大阶乘的逆元
    for (int i = M - 1; i >= 1; i--) {
        g[i - 1] = 1ll * g[i] * i % mod;               // 倒推得到所有逆元
    }

    // 组合数函数 C(x, y) = x! / (y! (x-y)!) % mod
    auto comb = [&](int x, int y) -> int {
        assert(x >= 0 && y >= 0 && y <= x);
        return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
    };

    while (t--) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;   // 输入题面中的 N, M 以及概率参数 p, q

        // ans 初始化为从 (2N,2M) 到 (1,1) 的最短路径步数（无等待的理想时间）
        int ans = 2 * (n + m) - 2;

        // 将概率 p/q 转化为模意义下的值 p1，p2 = 1 - p1
        int p1 = 1ll * p * fastpow(q, mod - 2, mod) % mod;
        int p2 = (mod + 1 - p1) % mod;

        // 把 N, M 各减 1，后续 n, m 表示除起点外还需经过的“十字路口”行数和列数
        n--; m--;

        // 根据剩余十字路口的行数和列数分类计算额外等待时间的期望
        if (n == 0) {
            // 情形1：只有一行十字路口（即 N=1），额外期望为 m * p1
            ans = (ans + 1ll * m * p1) % mod;
        }
        else if (m == 0) {
            // 情形2：只有一列十字路口（即 M=1），额外期望为 n * p2
            ans = (ans + 1ll * n * p2) % mod;
        }
        else if (n > m) {
            // 情形3：行数多于列数 (N > M)
            int x = m;               // 较小的维度
            int y = n - m;           // 差值
            int cur = 1, res = 0;
            // 计算求和：Σ_{i=0}^{y} (y-i) * p1^i * C(x-1+i, i)
            for (int i = 0; i <= y; i++) {
                res = (res + 1ll * (y - i) * cur % mod * comb(x - 1 + i, i)) % mod;
                cur = 1ll * cur * p1 % mod;   // cur = p1^i
            }
            // 最后乘上 p2^{x+1} 并累加到答案
            ans = (ans + 1ll * res * fastpow(p2, x + 1, mod)) % mod;
        }
        else {
            // 情形4：列数不少于行数 (N <= M)，与情形3对称，交换 p1 与 p2 的角色
            int x = n;               // 较小的维度
            int y = m - n;           // 差值
            int cur = 1, res = 0;
            // 计算求和：Σ_{i=0}^{y} (y-i) * p2^i * C(x-1+i, i)
            for (int i = 0; i <= y; i++) {
                res = (res + 1ll * (y - i) * cur % mod * comb(x - 1 + i, i)) % mod;
                cur = 1ll * cur * p2 % mod;   // cur = p2^i
            }
            // 乘上 p1^{x+1} 并累加
            ans = (ans + 1ll * res * fastpow(p1, x + 1, mod)) % mod;
        }

        cout << ans << endl;   // 输出模 998244353 下的期望时间
    }

    return 0;
}