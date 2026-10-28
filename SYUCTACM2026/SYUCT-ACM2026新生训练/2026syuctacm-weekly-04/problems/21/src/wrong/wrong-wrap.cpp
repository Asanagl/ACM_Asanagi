#include <bits/stdc++.h>

using namespace std;

// 实现层错误：用取模让下标"回绕"代替边界检查，跨过网格左右边界与上下边界去数邻居。
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
            if (g[(i - 1 + n) % n][j] == '1') ++cnt;
            if (g[(i + 1) % n][j] == '1') ++cnt;
            if (g[i][(j - 1 + m) % m] == '1') ++cnt;
            if (g[i][(j + 1) % m] == '1') ++cnt;
            if (j > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
