// 四邻格统计
// 独立实现：直接按题意枚举四个正交方向并做边界检查。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    // 四个正交方向的偏移量：上、下、左、右
    static const int dr[4] = {-1, 1, 0, 0};
    static const int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue; // 越界邻居不参与统计
                if (g[ni][nj] == '1') ++cnt;
            }
            if (j) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
