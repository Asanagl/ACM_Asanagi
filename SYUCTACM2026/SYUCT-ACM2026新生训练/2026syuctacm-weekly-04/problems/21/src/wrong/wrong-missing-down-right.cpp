#include <bits/stdc++.h>

using namespace std;

// 实现层错误：只统计上和左两个邻居，漏掉下和右。
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
            if (i > 0 && g[i - 1][j] == '1') ++cnt;
            if (j > 0 && g[i][j - 1] == '1') ++cnt;
            if (j > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
