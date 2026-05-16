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
    string s ;
    cin >> s ;
    int ans = 0 ;
    int n = s.size() ;
    int len = 1 ;
    for (int i = 1 ;i < n ; i++)
    {
        if (s[i] != s[i-1]) ++len ;
        else {
            ans = (ans + len * (len + 1 ) / 2) % MOD ;
            len = 1 ;
        }
    }
    ans = (ans + len * (len + 1) / 2) % MOD;
    cout << ans << endl ;

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