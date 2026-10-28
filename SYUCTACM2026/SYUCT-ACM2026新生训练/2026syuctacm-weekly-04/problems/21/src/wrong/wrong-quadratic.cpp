#include <bits/stdc++.h>

using namespace std;

// 复杂度层错误：对每个格子扫描整个网格来找邻居，复杂度 O(n^2 m^2)，在 500x500 上超时。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    if (g[x][y] != '1') continue;
                    const int d = abs(x - i) + abs(y - j);
                    if (d == 1) ++cnt;
                }
            }
            if (j > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
