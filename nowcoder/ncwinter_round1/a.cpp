#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const ll MOD = 998244353;
//simulation

int valid[10][7] = {
    {1,0,1,1,1,1,1},
    {0,0,0,1,0,0,1},
    {1,1,1,1,1,0,0},
    {1,1,1,1,0,0,1},
    {0,1,0,1,0,1,1},
    {1,1,1,0,0,1,1},
    {1,1,1,0,1,1,1},
    {0,0,1,1,0,0,1},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
        ll denom = 1;
    for (int i = 0; i < 56; i++) {
        denom = denom * 100 % MOD;
    }
    ll inv_denom = mod_exp(denom, MOD - 2, MOD);
    int T;
    cin >> T;
    while (T--) {
        int C;
        cin >> C;
        vector<int> p(7);
        for (int i = 0; i < 7; i++) {
            cin >> p[i];
        }
        vector<ll> F(10, 1);
        for (int d = 0; d < 10; d++) {
            for (int i = 0; i < 7; i++) {
                if (valid[d][i]) {
                    F[d] = F[d] * p[i] % MOD;
                } else {
                    F[d] = F[d] * (100 - p[i]) % MOD;
                }
            }
        }
        ll total = 0;
        for (int A = 0; A <= C; A++) {
            int B = C - A;
            int d0 = A / 1000;
            int d1 = (A % 1000) / 100;
            int d2 = (A % 100) / 10;
            int d3 = A % 10;
            int e0 = B / 1000;
            int e1 = (B % 1000) / 100;
            int e2 = (B % 100) / 10;
            int e3 = B % 10;
            ll prod = F[d0] * F[d1] % MOD;
            prod = prod * F[d2] % MOD;
            prod = prod * F[d3] % MOD;
            prod = prod * F[e0] % MOD;
            prod = prod * F[e1] % MOD;
            prod = prod * F[e2] % MOD;
            prod = prod * F[e3] % MOD;
            total = (total + prod) % MOD;
        }
        total = total * inv_denom % MOD;
        cout << total << endl;
    }
    }
    return 0;
}

