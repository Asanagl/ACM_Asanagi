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

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

int fa[30];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void Asanagi()
{
    int n;
    cin >> n;
    if (n == 0) exit(0);
    vector<Edge> e;
    for (int i = 0; i < n - 1; i++) {
        char a, b;
        int k, w;
        cin >> a >> k;
        while (k--) {
            cin >> b >> w;
            e.pb({a - 'A', b - 'A', w});
        }
    }
    sort(e.begin(), e.end());
    iota(fa, fa + n, 0);
    int ans = 0, cnt = 0;
    for (auto &x : e) {
        int u = find(x.u), v = find(x.v);
        if (u != v) {
            fa[u] = v;
            ans += x.w;
            if (++cnt == n - 1) break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    IOS;
    while (true) Asanagi();
    return 0;
}
