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
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y])
    {
        fa[y] = x;
        siz[x] += siz[y];
    }
    else
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}
struct graph 
{
    int x, y ,z ;
};

void Asanagi() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }
    vector<graph> alone;
    const int sb = m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        alone.pb({u, v, w});
    }
    int ans = 0, baka = 0;
    sort(alone.begin(), alone.end(), [](graph a, graph b) { return a.z > b.z; });
    for (int i = 0, baka = 0; i <= sb && baka < k; i++) {
        int l = find(alone[i].x), r = find(alone[i].y);
        if (l != r) {
            merge(l, r);
            baka++;
            ans += alone[i].z;
        }
    }
    cout << ans << endl;
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
