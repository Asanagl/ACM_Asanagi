#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n) {
        p.resize(n + 1);
        r.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) p[i] = i;
    }
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (r[x] < r[y]) p[x] = y;
        else if (r[x] > r[y]) p[y] = x;
        else { p[y] = x; r[x]++; }
    }
};

void Asanagi() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) cin >> p[i];

        DSU dsu(n);
        for (int i = 1; i <= n; ++i) {
            if (i + x <= n) dsu.unite(i, i + x);
            if (i + y <= n) dsu.unite(i, i + y);
        }

        vector<vector<int>> pos_by_root(n + 1);
        vector<vector<int>> val_by_root(n + 1);
        for (int i = 1; i <= n; ++i) {
            int r = dsu.find(i);
            pos_by_root[r].push_back(i);
            val_by_root[r].push_back(p[i]);
        }

        bool ok = true;
        for (int r = 1; r <= n; ++r) {
            if (pos_by_root[r].empty()) continue;
            sort(pos_by_root[r].begin(), pos_by_root[r].end());
            sort(val_by_root[r].begin(), val_by_root[r].end());
            if (pos_by_root[r] != val_by_root[r]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}

int main() {
    Asanagi();
    return 0;
}