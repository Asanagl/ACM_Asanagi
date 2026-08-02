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
    int maxn = 0 ; 
    int minn = LINF ; 
    int temp = -LINF ;
    int cur = 0 ,  pst = 0 , ps = 0 , ftr = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> g[i][j] ;
            int cur = g[i][j] ;
            maxn = max (cur , maxn) ;
            minn = min (cur , minn) ;
        }
    }
    int st = g[1][1] ;
    int ed = g[n][m] ;
    if (st != ed || st != minn)
    {
        cout << -1 << endl ;
        return ;
    }
    if (n == 1)
    {
        bool flag = false ;
        for (int i = 1 ; i < m ; i++)
        {
            if (g[1][i] != g[1][i+1])
            {
                flag = true ;
            }
        }
        if (flag) cout << -1 << endl ;
        else cout << 0 << endl ;
        return ;
    }
    if (m == 1)
    {
        bool flag = false ;
        for (int i = 1 ; i < n ; i++)
        {
            if (g[i][1] != g[i+1][1])
            {
                flag = true ;
            }
        }
        if (flag) cout << -1 << endl ;
        else cout << 0 << endl ;
        return ;
    }
    for (int j = 1; j < m; j++)
        if (g[1][j] > g[1][j+1]) { cout << -1 << endl; return; }
    for (int i = 1; i < n; i++)
        if (g[i][1] > g[i+1][1]) { cout << -1 << endl; return; }
    for (int j = 1; j < m; j++)
        if (g[n][j] < g[n][j+1]) { cout << -1 << endl; return; }
    for (int i = 1; i < n; i++)
        if (g[i][m] < g[i+1][m]) { cout << -1 << endl; return; }
    int X = maxn;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            X = max(X, g[i-1][j] + g[i][j-1] - g[i][j]);

    int ans = X - g[1][1];
    cout << ans << endl;
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
