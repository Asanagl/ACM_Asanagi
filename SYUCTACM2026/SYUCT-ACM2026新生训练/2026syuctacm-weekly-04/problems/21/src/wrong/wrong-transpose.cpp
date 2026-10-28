#include <bits/stdc++.h>

using namespace std;

// 实现层错误：把行列读反，输出转置后的答案。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            if (i > 0 && g[i - 1][j] == '1') ++cnt;
            if (i + 1 < n && g[i + 1][j] == '1') ++cnt;
            if (j > 0 && g[i][j - 1] == '1') ++cnt;
            if (j + 1 < m && g[i][j + 1] == '1') ++cnt;
            if (i > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
