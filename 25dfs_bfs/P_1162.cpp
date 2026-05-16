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
using ll = long long ;
const int dx[4] = {1 , -1 , 0 , 0} ;
const int dy[4] = {0 , 0 , -1 , 1} ;
int ysnb[35][35] ;
int vis[35][35] ;
int n ;
void bfs (int sx  ,int sy )
{
    queue<pair<int , int>> qe ;
    qe.push(mp(sx,sy)) ;
    vis[sx][sy] = 1 ;
    while (!qe.empty())
    {
        auto t = qe.front(); qe.pop();
        for (int i = 0 ; i < 4 ; i ++)
        {
            int tx = t.first+dx[i] , ty = t.second + dy[i] ;
            if (tx < 0 || ty < 0 || tx > n+1 || ty > n+1) continue ;
            if (ysnb[tx][ty]==1||vis[tx][ty]==1) continue ;
            vis[tx][ty] = 1 ;
            qe.push(mp(tx,ty)) ;
        }
    }
}
void Asanagi()
{
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++)
    
        for (int j = 1; j <= n ; j++)
            cin >> ysnb[i][j] ;
    // * bfs
    bfs(0 , 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j] || ysnb[i][j] == 1)
                cout << ysnb[i][j] << ' ';
            else
                cout << 2 << ' ';
        }
        cout << endl;
    }
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