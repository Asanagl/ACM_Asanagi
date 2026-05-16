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
const int dx[8] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1} ;
const int dy[8] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2} ;
int n , m , sx , sy ;
vector <vector<int>> ans (405 , vector <int> (405 , -1)) ; 
vector <vector<int>> vis (405 , vector <int> (405 , 0)) ; 
void Asanagi()
{
    cin >> n >> m >> sx >> sy ;
    queue<pair<int ,int>> qe ;
    qe.push(mp(sx , sy)) ;
    ans[sx][sy] = 0 ;
    vis[sx][sy] = 1 ;
    // * bfs
    while (!qe.empty())
    {
        for (int i = 0 ; i < 8 ; i ++)
        {
            int x = qe.front().first + dx[i];
            int y = qe.front().second + dy[i];
            if (x > 0 && x <= n && y > 0 && y <= m && vis[x][y] == 0)
            {
                vis[x][y] = 1 ;
                ans[x][y] = ans[qe.front().first][qe.front().second] + 1 ;
                qe.push(mp(x , y)) ;
            }
        }
        qe.pop() ;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << ' ';
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