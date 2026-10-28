#include <bits/stdc++.h>

using namespace std;

// 思路层错误：把 8 邻域（含斜向）都当成邻居。
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
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    const int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == '1') ++cnt;
                }
            }
            if (j > 0) cout << ' ';
            cout << cnt;
        }
        cout << '\n';
    }
    return 0;
}
