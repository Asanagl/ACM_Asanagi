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
const int inf = 30;
const int pinf = 3e4+10 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

void Asanagi()
{
    int n  , m ;
    cin >> n >> m ;
    vector <int> v (inf) ;
    vector <int> p (inf) ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> v[i] >> p[i]
         ;
        p[i] *= v[i] ;
    }
    vector <vector <int> > dp (inf , vector <int> (pinf , 0));
    for (int i = 1 ; i <= m ; i ++)
    {
        for (int j = 0 ; j <= n ; j++)
        {
            dp[i][j] = dp[i-1][j] ;
            if (j >= v[i])
            dp[i][j] = max (dp[i][j] , dp[i-1][j-v[i]]+p[i]) ;
        }
    }
    cout << dp[m][n] ;
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
