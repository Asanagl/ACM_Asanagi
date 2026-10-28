// 错解 B（思路层：公式错误）：用了二维前缀和，但容斥时漏掉
// +ps[r1-1][c1-1] 这一项，左上角被多减一次。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> ps(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ps[i][j] = a[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    for (int k = 0; k < q; ++k) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        cin >> r1 >> c1 >> r2 >> c2;

        long long total = ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1];
        cout << total << '\n';
    }
    return 0;
}
