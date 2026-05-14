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


void solve()
{
    int n , m  ;
    cin >> n >> m ;
    vector <int> v (n) ;
    for (auto &it : v) cin >> it ;
    int a  ;
    cin >> a ;
    int cur = -LINF ;
    bool tri = true ;
    for (int i = 0 ; i < n ; ++i)
    {
        int x = v[i] ;
        int y = a - v[i] ;
        if (x >= cur && y >=cur)
        {
            cur = min (x ,y) ;
        } else if ( x >= cur) cur = x ;
        else if (y >= cur ) cur =y ;
        else {tri = false; break ; }
    }
    cout << (tri ? "YES" : "NO") << endl ;
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}