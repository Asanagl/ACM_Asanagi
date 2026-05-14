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

//八向
const int dx[8] = {-1,-1,-1,0,0,1,1,1} ;
const int dy[8] = {-1,0,1,-1,1,-1,0,1} ;


void solve()

{
    int n , m ;
    cin >> n >> m ;
    int l , r ;
    cin >> l >> r ;
    vector <string> g(n) ;
    for (int i = 0 ; i < n ;i ++)
    cin >> g[i] ;
    vector <vector<int> >dist (n,vector <int>(m ,-1));
    queue<pair<int , int >> q ;
    dist[0][0] = 0 ;
    q.push({0,0}) ;
    while (!q.empty())
    {
        auto [x , y] = q.front() ; 
        q.pop();
        for (int i = 0; i < 8 ; i++)
        {
            int tx = x + dx[i] , ty = y + dy[i] ;
            if (tx>=0&&tx<n&&ty>=0&&ty<m   &&  g[tx][ty]=='1'&&dist[tx][ty]==-1)
            {
                dist[tx][ty] = dist[x][y] + 1;
                    q.push({tx,ty});
            }
        }
    }
    int d = dist[n-1][m-1];
        if (d == -1) {
            cout << -1 << endl;
            return ;
        }
        int mint = (d + r - 1) / r; 
        int maxt = d / l;           
        
        if (mint <= maxt) {
            cout << mint << endl;
        } else {
            cout << -1 << endl;
        }
}

signed main()
{
    IOS;
    int t;
    // t = 1 ;
    cin >> t;
    while (t--)
    {
            solve();
        }
    return 0;
}