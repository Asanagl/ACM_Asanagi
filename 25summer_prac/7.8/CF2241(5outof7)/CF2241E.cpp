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
const int INF = 1e9+10;
const int LINF = 1e18+10;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;

bool isPerfectSquare(int x) {
    int r = sqrt((long double)x);
    while (1LL * r * r < x) r++;
    while (1LL * r * r > x) r--;
    return 1LL * r * r == x;
}

void Asanagi()
{
    int n ;
    cin >> n ;
    vector <int> val (n+1) ; 
    for (int i = 1 ; i <= n ; i++) cin >> val[i] ;
    vector <vector<int>> graph(n+1) ;
    for (int i = 1 ; i < n ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0 ;
    vector <int> fa (n+1 , 0) ;
    vector <int> dfs_order;
    dfs_order.reserve(n) ;
    queue <int> qe ;
    qe.push(1) ;
    fa[1] = -1 ;
    while (!qe.empty())
    {
        int u = qe.front() ;
        qe.pop();
        dfs_order.pb(u) ;
        for (auto &v : graph[u])
        {
            if (v == fa[u]) continue ;
            fa[v] = u ;
            qe.push(v) ;
        }
    }
    vector <int> subtree(n+1 , 1) ;
    for (int i = n-1 ; i >= 1 ; i--)
    {
        int u = dfs_order[i] ;
        subtree[fa[u]] += subtree[u] ; 
    }
    for (int u = 1 ; u <= n ; u++)
    {
        if (!isPerfectSquare(val[u])) continue ;
        int prefix = 0 ;
        int c_pair = 0 ;
        int c3_num = 0 ;
        for (auto &v : graph[u])
        {
            int x_num ;
            if (v == fa[u])
            {
                x_num = n - subtree[u];
            } else x_num = subtree[v] ;
            c3_num += c_pair * x_num;
            c_pair += prefix * x_num;
            prefix += x_num;
        }
        ans += c_pair + c3_num ;
    }
    cout << ans << endl ;


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
