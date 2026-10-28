#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // 二维前缀和，使用 (n+1) x (m+1) 的 long long 数组，下标 1..n / 1..m
    vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0LL));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x;
            cin >> x;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }

    for (int t = 0; t < q; ++t) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        long long ans = pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1];
        cout << ans << '\n';
    }
    return 0;
}
