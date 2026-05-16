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
const int INF = 1e5+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int dx[4] = {1,-1,0,0} ;
const int dy[4] = {0,0,1,-1} ;
int n , m ;
int vis[510][510] = {0};
vector <vector <int>> ysnb (510 , vector <int> (510 , INF)) ;
void bfs(vector <pair<int,int>> led , int l)
{
    queue<pair<int , int>> qe ;
    for (int i = 0 ; i < l ; i++)
    {
        qe.push(led[i]) ;
        ysnb[led[i].first][led[i].second] = 0 ;
    }
        
    while (!qe.empty())
    {
        pair<int , int> q = qe.front();
        qe.pop();
        for (int i = 0 ; i < 4 ; i ++)
        {
            int tx = q.first + dx[i] , ty = q.second + dy[i] ;
            if (tx == 0 || ty == 0 || tx > n || ty > m ) continue ;

            if(ysnb[q.first][q.second]+1 < ysnb[tx][ty])
            {
                ysnb[tx][ty] = ysnb[q.first][q.second] + 1 ;
                qe.push(mp(tx,ty)) ;
            }
        } 
    }
}
void Asanagi()
{
    int  a , b ;
    cin >> n >> m >> a >> b ;
    vector <pair<int,int>> po;
    vector <pair<int,int>> led;
    for (int i = 0 ;  i < a ; i++)
    {
        int x , y ;
        cin >> x >> y  ;
        po.pb(mp(x,y)) ;
    }
    for (int i = 0 ;  i < b ; i++)
    {
        int x , y ;
        cin >> x >> y  ;
        led.pb(mp(x,y)) ;
        ysnb[x][y] = 0 ;
    }
    bfs(po , a);
    for (int i = 0 ; i < b ; i++)
    {
        cout << ysnb[led[i].first][led[i].second] << endl ;
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