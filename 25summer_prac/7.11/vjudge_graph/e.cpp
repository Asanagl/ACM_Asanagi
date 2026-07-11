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
#define pii pair<int ,int>
const int INF = 1e9+10;
const int LINF = 1e18+10;
const int N = 2e5 + 5 ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
int n , m ;
vector<pair<int, ll>> Djk[N];
vector <bool> vis (N , false) ;
void Dijkstra(vector <int> dist)
{
    priority_queue <pii,vector<pii>,greater<pii>> pqe ;
    dist[1] = 0 ;
    pqe.push(mp(0 , 1)) ;
    while (!pqe.empty())
    {
        auto t = pqe.top() ;
        pqe.pop() ;
        auto d = t.first ;
        auto u = t.second ;
        if (vis[u]) continue;
        vis[u] = true ;
        for (auto &it : Djk[u])
        {
            if (dist[it.first] > dist[u]+it.second)
            {
                dist[it.first] = dist[u]+it.second ;
                pqe.push({dist[it.first], it.first}); 
            }
        }
    }
}

void solve()
{
    cin >> n >> m ;
    vector <int> dist (N , INF) ;
    for (int i = 1 ;i <= n ; i++)
    {
        int u , v , w ;
        cin >> u >> v >> w ;

    }
    Dijkstra(dist);
    cout << (dist[b]==INF ? -1 : dist[b]) ;
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
