#include <bits/stdc++.h>

using namespace std;

// 思路层错误：统计"存在的邻居个数"而不是"值为 1 的邻居个数"。
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
            if (i > 0) ++cnt;
            if (i + 1 < n) ++cnt;
            if (j > 0) ++cnt;
            if (j + 1 < m) ++cnt;
            if (j > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
