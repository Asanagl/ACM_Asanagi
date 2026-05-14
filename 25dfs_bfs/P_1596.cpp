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
const int dx[8] = {1,0,-1,0,1,-1,1,-1} ;
const int dy[8] = {0,1,0,-1,1,-1,-1,1} ;
int n , m ;
int vis[110][110] ;
int ysnb[110][110] ;
void bfs(pair<int , int> s , int c)
{
    queue <pair<int,int>> qe ;
    qe.push(s) ;
    vis[s.first][s.second] = 1;
    while (!qe.empty())
    {
        s = qe.front();
        qe.pop() ;
        int x = s.first , y = s.second ;
    }
}
void solve()
{
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i ++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                char x ;
                cin >> x ;
                if (x=='W') ysnb[i][j] = 1 ;
            }
        }
    int mcnb = 0 ;
    for (int i = 1  ; i<= n ; i++)
    {
        for (int j = 1 ;j <= m ; j++)
        {
            if (ysnb[i][j]==1 && !vis[i][j])
            {mcnb++ ;
            pair<int , int> s = mp(i,j) ;
            bfs(s , mcnb) ;}
        }
    }
    cout << mcnb ;
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