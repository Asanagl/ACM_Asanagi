#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
const int MOD =  998244353 ;
using ll = long long ;
void Asanagi()
{
    string s;
    cin >> s;
    int tt = 1;      
    int abc[3] = {0, 0, 0};
    for (auto it : s) {
        int idx = it - 'a';
        int ysnb = (tt - abc[idx] + MOD) % MOD;
        abc[idx] = (abc[idx] + ysnb) % MOD;
        tt = (tt + ysnb) % MOD;
    }
    int ans = (tt - 1 + MOD) % MOD;
    cout << ans << endl;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}

