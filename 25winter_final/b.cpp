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
const int MAXN = 1000005;
void solve()
{
    int n ,  q ;
    cin >> n >> q ;
    vector <int> gezi (MAXN) ;
    vector <int> inchao(MAXN) ;
    for (int i = 1 ; i <= n ; ++i)
    {
        gezi[i] = 1 ;
        inchao[i] = i ;
    }
    int ans = 0 ;
    while (q--)
    {
        int t ;
        cin >> t ;
        if (t == 1)
        {
            int  x , y ;
            cin >> x >> y ;
            int tick = inchao[x] ;
            if (tick == y) continue;


            gezi[tick] -- ;
            if (gezi[tick] == 1)    ans -- ;
            

            gezi[y] ++ ;
            if (gezi[y]==2)     ans ++ ;


            inchao[x] = y ;

        }else cout << ans << endl ;
    }
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