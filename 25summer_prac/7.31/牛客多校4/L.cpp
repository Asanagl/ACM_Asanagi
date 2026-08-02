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
const int INF = 1e9+900;
const int LINF = LLONG_MAX;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int dx[4] = {1 , -1 , 0 , 0} ;
const int dy[4] = {0 , 0 , 1 , -1} ;
int g[5010][5010] =  {0};
void Asanagi()
{
    int n , m ;
    cin >> n >> m ;
    int minn = LINF ;
    int maxn = -LINF ;
    for (int i = 1 ; i <= n ; i ++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> g[i][j] ;
            minn = min (minn , g[i][j]) ;
            maxn = max (maxn , g[i][j]) ;
        }
    }
    if (g[1][1] != g[n][m] || g[1][1] != minn)
    {
        cout << -1 << endl ;
        return ;
    }
    if (n == 1) for (int j = 1 ; j < m ; j++) if (g[1][j] != g[1][j+1]) {cout << -1 << endl ; return ;}
    if (m == 1) for (int i = 1 ; i < n ; i++) if (g[i][1] != g[i+1][1]) {cout << -1 << endl ; return ;}
    for (int i = 1 ; i < n ; i++)
}

signed main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        Asanagi();
    }
    return 0;
}
