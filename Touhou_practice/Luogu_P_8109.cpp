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

using ll = long long ;

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (auto &it : v )cin >> it ;
    vector <int> b (n) ;
    for (auto &it : b) cin >> it ;
    int ans = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        ans += min (v[i] , b[i]) ;
    }
    cout << ans ;

}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}