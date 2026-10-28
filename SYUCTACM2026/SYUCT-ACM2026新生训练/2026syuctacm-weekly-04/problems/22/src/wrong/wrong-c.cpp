// 错解 C（实现层：类型选择错误）：用 32 位 int 累加子矩阵和。
// 答案绝对值可达 1e13，远超 int 范围。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < q; ++k) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        cin >> r1 >> c1 >> r2 >> c2;

        int total = 0;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                total += a[i][j];
            }
        }
        cout << total << '\n';
    }
    return 0;
}
