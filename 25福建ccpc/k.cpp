#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define pb push_back
#define ull unsigned long long
#define i128 __int128
const int INF = 1e9+10;
const int LINF = 1e18+10;
using ld = long double ;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;
using ll = long long ;
const int inf  = 2e5+10 ;

void solve()
{
    int n ;
    cin >> n ;
    vector < vector < pair <int , int > > > adj (n+1) ;
    for (int i = 0 ; i < n -1 ; i++)
    {
        int u , v ;
        cin >> u >> v ;
        int w ;
        cin >> w ;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    vector <int> a (inf , 0) ;
    vector <int> c (inf , 0) ;
    vector <bool> tar (inf , false) ;
    queue <int> qe ;
    qe.push(1) ;
    tar[1] = true ;
    a[1] = 1 ;
    c[1] = 0 ;
    int L = 1 , R = INF ;
    bool gumi = true ;
    while (!qe.empty() && gumi)
    {
        int u = qe.front()  ;
        qe.pop();
        if (a[u] == 1)
        {
            L = max (L , 1LL - c[u]) ;
            R = min (R , INF - c[u] ) ;
        } else 
        {
            L = max (L ,c[u] - INF) ;
            R = min (R , c[u] - 1);
        }
        if (L >  R ) 
        {
            gumi  = false ;
            break ;
        }
        for (auto [v, w] : adj[u])
        {
            if (!tar[v])
            {
                tar[v] = true ;
                a[v] = -a[u] ;
                c[v] = w - c[u] ;
                qe.push(v) ;
            }
        }
    }
    if (!gumi || L > R)
    {
        cout << "NO" << endl ;
        return ;
    }
    int temp = L ;
    cout << "YES" << endl ;
    for (int i = 1 ; i <= n ;i++)
    {
        int sbti = a[i] * temp +c[i] ;
        cout << sbti << " " ;
    }
    cout << endl ;
    

    
}

signed main()
{
    IOS;
    int t;
    t = 1 ;
    // cin >> t;?
    while (t--)
    {
            solve();
        }
    return 0;
}


