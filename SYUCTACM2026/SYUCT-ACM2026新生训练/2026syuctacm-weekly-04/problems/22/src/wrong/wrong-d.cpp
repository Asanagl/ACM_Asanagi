// 错解 D（思路层：题意理解错误）：忽略询问的列边界，
// 对第 r1~r2 行的整行（全部 m 列）求和。
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

        long long total = 0;
        for (int i = r1; i <= r2; ++i) {
            for (int j = 1; j <= m; ++j) {
                total += a[i][j];
            }
        }
        cout << total << '\n';
    }
    return 0;
}
