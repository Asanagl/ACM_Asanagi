#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
#define pb push_back
#define PII pair<int,int>
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void solve()
{
    int n , m ;
    cin >> n >> m ;
    vector <int> du(n+1) ;
    int x , y ;
    for (int i = 0 ; i < m ; i++)
    {
        cin >> x >> y ;
        du[x]++, du[y]++ ;
    }
    vector <PII> ans ;
    x = 0 ;
    for (int i = 1 ; i <= n ; i ++)
    {
        if (du[i] % 2 ==1 && x == 0) 
        {
            x = i ;
        }
        else if (du[i] % 2 == 1)
        {
            ans.pb({x,i}) ;
            x = 0 ;
        }
    }
    cout << ans.size()  << endl ;
    for (auto &it : ans)
    {
        cout << it.first << " " << it.second << endl  ;
    }
}
signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}