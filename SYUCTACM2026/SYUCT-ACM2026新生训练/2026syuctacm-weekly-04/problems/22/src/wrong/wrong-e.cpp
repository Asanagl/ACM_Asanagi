// 错解 E（复杂度层）：答案正确，但每次询问都用四重循环按定义
// 重算整张前缀和表，O(q * n^2 * m^2) ≤ 1000 * 10^8 = 10^11，必然超时。
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

    for (int k = 0; k < q; ++k) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        cin >> r1 >> c1 >> r2 >> c2;

        // 按定义逐项重算前缀和，而非递推——每次询问都重来一遍。
        vector<vector<long long>> ps(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                long long s = 0;
                for (int x = 1; x <= i; ++x) {
                    for (int y = 1; y <= j; ++y) {
                        s += a[x][y];
                    }
                }
                ps[i][j] = s;
            }
        }

        long long total = ps[r2][c2] - ps[r1 - 1][c2] - ps[r2][c1 - 1] + ps[r1 - 1][c1 - 1];
        cout << total << '\n';
    }
    return 0;
}
