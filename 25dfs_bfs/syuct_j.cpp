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
const int dx[4] = {0 , 0 , 1 , -1} ;
const int dy[4] = {1 , -1 , 0 , 0} ;
int n , m ;
void solve()
{
    // * 哒哒哒哒哒 好想玩原神
    while (cin >> n >> m)
    {
        int yx, yy, mx, my;
        int ysnb[n + 2][m + 2];
        int mcnb[n + 2][m + 2];
        memset(ysnb, -1, sizeof ysnb);
        memset(mcnb, -1, sizeof mcnb);
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char it;
                cin >> it;
                if (it == 'Y')
                {
                    yx = i, yy = j;
                }
                if (it == 'M')
                {
                    mx = i, my = j;
                }
                if (it == '#')
                {
                    ysnb[i][j] = -2, mcnb[i][j] = -2;
                }
                if (it == '@')
                {
                    ans.pb({i, j});
                }
            }
        }
        ysnb[yx][yy] = 0;
        mcnb[mx][my] = 0;
        // * bfs 对于ysnb
        queue<pair<int, int>> qe;
        qe.push({yx, yy});
        while (!qe.empty())
        {

            auto t = qe.front();
            qe.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = t.first + dx[i], ty = t.second + dy[i];
                if (tx <= 0 || ty <= 0 || tx > n || ty > m || ysnb[tx][ty] == -2 || ysnb[tx][ty] >= 0)
                    continue;
                ysnb[tx][ty] = ysnb[t.first][t.second] + 11;
                qe.push({tx, ty});
            }
        }
        // * 比起ys，我还是觉得mc更nb
        queue<pair<int, int>> q;
        q.push({mx, my});
        while (!q.empty())
        {

            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = t.first + dx[i], ty = t.second + dy[i];
                if (tx <= 0 || ty <= 0 || tx > n || ty > m || mcnb[tx][ty] == -2 || mcnb[tx][ty] >= 0)
                    continue;
                mcnb[tx][ty] = mcnb[t.first][t.second] + 11;
                q.push({tx, ty});
            }
        }
        int res = INF;
        for (auto it : ans)
        {
            int y_time = ysnb[it.first][it.second];
            int m_time = mcnb[it.first][it.second];
            if (y_time >= 0 && m_time >= 0)
            {
                res = min(res, y_time + m_time);
            }
        }
        cout << res << endl;
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

