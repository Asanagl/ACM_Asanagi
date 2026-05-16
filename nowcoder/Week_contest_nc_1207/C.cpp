#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define int long long
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int MOD = 998244353;

void Asanagi()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {cnt[c - 'a']++;}
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (j == i) continue;
            for (int k = 0; k < 26; ++k) {
                if (k == i || k == j) continue;
                ans = (ans + cnt[i] * cnt[j] % MOD * cnt[k]) % MOD;
            }
        }
    }
    cout << ans << endl;
}



signed main()
{
    IOS;
    int t =1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}