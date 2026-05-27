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
const int N = 100100 ;
int fa[N] , siz[N] ;
int find (int n)
{
    if(fa[n] == n) return n ;
    else return fa[n] = find(fa[n]) ; 
}
bool merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (siz[x] > siz[y])
    {
        fa[y] = x;
        siz[x] += siz[y];
        return true ;
    }
    else
    {
        fa[x] = y;
        siz[y] += siz[x];
        return true ;
    }
}
struct graph 
{
    int x, y ,z ;
};

void Asanagi() {
    int n ;
    cin >> n ;
    vector <graph> v (N) ;
    for (int i = 0 ; i <= n ; i++)
    {
        fa[i] = i ;
        siz[i] = 1 ;
    }
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<graph> e;
    for (int i = 1; i <= n; i++) 
    e.pb({0, i, w[i]});
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (i < j) e.pb({i, j, x});
        }
    }
    sort(e.begin() , e.end() , [](graph a,graph b) {return a.z < b.z ;}) ;
    int ans = 0  , sad = 0  ;
    for (auto &it : e) 
    {
        if (merge(it.x , it.y))
        {
            ans += it.z ;
            if (++sad == n ) break ; 
        }
    }
    cout << ans << endl ;
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
