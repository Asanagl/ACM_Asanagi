#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long;
const int MOD = 998244353;

int Asagi(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int ot1 = (n + 1) / 2;
    int et = n / 2, ro = 0, re = 0, q = 0;
    for (auto &it : s)
    {
        if (it == 'j')
            ro++;
        else if (it == 'o')
            re++;
        else
            q++;
    }
    if (ro > ot1 || re > et)
    {
        cout << 0 << endl;
        return;
    }
    int need = ot1 - ro;
    vector<int> fac(n + 1), inf(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inf[n] = Asagi(fac[n], MOD - 2);
    int ans = 0 ;
    for (int i = n - 1; i >= 0; i--)
        inf[i] = inf[i + 1] * (i + 1) % MOD;
    if (need < 0 || need > q)
        ans = 0 ;
    ans = fac[q] * inf[need] % MOD * inf[q - need] % MOD;
    ans = ans * fac[ot1] % MOD;
    ans = ans * fac[et] % MOD;
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}
