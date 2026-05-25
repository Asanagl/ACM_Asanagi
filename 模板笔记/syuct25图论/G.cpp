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

struct DSU {
    vector<int> f;
    DSU(int n = 0) {
        init(n);
    }
    void init(int n) {
        f.resize(n + 1);
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        f[x] = y;
        return true;
    }
};

void Asanagi(int n) 
{
    int m = n * (n - 1) / 2;
    vector <array<int, 3>> e;
    e.reserve(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u, v});
    }
    sort(e.begin(), e.end());
    DSU dsu(n);
    int ans = 0, cnt = 0;
    for (auto &[w, u, v] : e) {
        if (dsu.merge(u, v)) {
            ans += w;
            if (++cnt == n - 1)
                break;
        }
    }
    cout << ans << endl;
}

signed main() {
    IOS;
    int n;
    while (cin >> n && n) {
        Asanagi(n);
    }
    return 0;
}
