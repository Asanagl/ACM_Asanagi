#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
const int INF = 1e7+10;

struct node 
{
    int x;
    int y;
    int fc;  // 方向: 0东, 1南, 2西, 3北
};

const int dx[4] = {0, 1, 0, -1}; // 东, 南, 西, 北
const int dy[4] = {1, 0, -1, 0};

// 点阵图转换数组
const int prx[4] = {0, 0, 1, 1};
const int pry[4] = {0, 1, 0, 1};

int m, n;                   
vector <vector<int>> ysnb (60 , vector<int>(60 , INF)) ;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        ysnb[i][1] = ysnb[i][m+1] = -2;

    for (int j = 0; j <= m+1; j++)
        ysnb[1][j] = ysnb[n+1][j] = -2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int it;
            cin >> it;
            if (it == 0) continue;
            for (int z = 0; z < 4; z++)
            {
                int nr = i + prx[z];
                int nc = j + pry[z];
                ysnb[nr][nc] = -2;
            }
        }
    }
    int sx, sy, tx, ty;
    char ch;
    cin >> sx >> sy >> tx >> ty >> ch;
    sx++ , sy++ ,tx++ ,ty++;
    int sfc;
    if (ch == 'E')
        sfc = 0;
    else if (ch == 'S')
        sfc = 1;
    else if (ch == 'W')
        sfc = 2;
    else
        sfc = 3; // 'N'
    if (ysnb[sx][sy] == -2 || ysnb[tx][ty] == -2)
    {
        cout << -1 << endl;
        return;
    }
    ysnb[sx][sy] = 0 ;
    // * BFS start
    queue<node> qe;
    ysnb[sx][sy] = 0;
    qe.push({sx, sy, sfc});
    while (!qe.empty())
    {
        node cur = qe.front();
        qe.pop();
        int cx = cur.x, cy = cur.y, cfc = cur.fc;
        for (int i = 0 ; i < 4 ; i++)
        {
            int turn_val ;
            if (abs(cfc - i) == 2 ) turn_val = 2 ;
            else if (i == cfc) turn_val = 0 ;
            else turn_val = 1 ;
            for (int j = 1 ; j <= 3 ; j++)
            {
                int x = cx + dx[i] * j , y = cy + dy[i] * j ;
                if (x <= 0 || y <= 0 || x > n || y > m) break ;
                if (ysnb[x][y] == -2) break ;
                ysnb[x][y] = min (ysnb[x][y] , ysnb[cx][cy]+turn_val+1) ;
                if (!(ysnb[x][y]!=INF && ysnb[x][y] < ysnb[cx][cy]+turn_val+1 ))
                qe.push({x,y,i}) ;
            }
        }
    }
    if (ysnb[tx][ty]==INF) cout << -1 ;
    else cout << ysnb[tx][ty] ;
}

signed main()
{
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}