// 子矩阵求和 —— 主解：对每次询问直接枚举闭区间 [r1,r2] × [c1,c2] 内的格子累加。
// 最坏 q*n*m = 1000*100*100 = 1e7 次加法，在 1000ms 内十分宽裕。
// 单次答案绝对值可达 100*100*10^9 = 1e13，必须用 long long 累加。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, q = 0;
    if (!(cin >> n >> m >> q)) {
        return 0;
    }

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < q; ++k) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        cin >> r1 >> c1 >> r2 >> c2;

        long long total = 0;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                total += a[i][j];
            }
        }
        cout << total << '\n';
    }
    return 0;
}
