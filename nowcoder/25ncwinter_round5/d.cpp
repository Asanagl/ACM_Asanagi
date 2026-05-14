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
const int MOD = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        int c, w;
        cin >> c >> w;
        if (c > 0)
        {
            mp[w] += c;
            total += c;
        }
    }
    int ans = 0;
    while (total > 1)
    {
        auto it = mp.begin();
        int w = it->first;
        int f = it->second;
        if (f >= 2)
        {
            int k = f / 2;
            int cost = (2 * w) % MOD;
            ans = (ans + cost * (k % MOD)) % MOD;
            f -= 2 * k;
            if (f == 0)
            {
                mp.erase(it);
            }
            else
            {
                it->second = f;
            }
            int new_w = w * 2;
            mp[new_w] += k;
            total -= k;
        }
        else
        {
            auto it2 = next(it);
            int w2 = it2->first;
            int f2 = it2->second;
            int cost = (w + w2) % MOD;
            ans = (ans + cost) % MOD;
            mp.erase(it);
            if (f2 == 1)
            {
                mp.erase(it2);
            }
            else
            {
                it2->second = f2 - 1;
            }
            int nw = w + w2;
            mp[nw] += 1;
            total -= 1;
        }
    }
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