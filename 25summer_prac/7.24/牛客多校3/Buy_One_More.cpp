#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long
const int MOD = 998244353;
const int MAXN = 2000000;
int fac[MAXN + 5];
int invfac[MAXN + 5];
int invnum[MAXN + 5];

int qmi_inv(int a, int e) 
{
    int r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
signed main()
{
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
    invfac[MAXN] = qmi_inv(fac[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--)
        invfac[i - 1] = invfac[i] * i % MOD;
    invnum[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        invnum[i] = (MOD - MOD / i) * invnum[MOD % i] % MOD;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, c, a, b;
        cin >> n >> m >> c >> a >> b;
        int diff = m - n;
        if (diff < 0 || diff % c != 0)
        {
            cout << 0 << endl;
            continue;
        }
        int k = diff / c;
        if (k < 0 || k > m)
        {
            cout << 0 << endl;
            continue;
        }
        // cal
        int inv_b = qmi_inv(b, MOD - 2);
        int p = a * inv_b % MOD;
        int q = (b - a) * inv_b % MOD;
        int comb = fac[m] * invfac[k] % MOD * invfac[m - k] % MOD;
        int ans = n * invnum[m] % MOD;
        ans = ans * comb % MOD;
        ans = ans * qmi_inv(p, k) % MOD;
        ans = ans * qmi_inv(q, m - k) % MOD;
        cout << ans << endl;
    }
    return 0;
}