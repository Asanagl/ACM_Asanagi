#include <bits/stdc++.h>

using namespace std;

// 主解：把网格向外补一圈 0，得到 (n+2) x (m+2) 的整型数组后直接求和，
// 求和处不再需要任何边界判断。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = (row[j - 1] == '1') ? 1 : 0;
        }
    }

    string out;
    out.reserve(static_cast<size_t>(2) * static_cast<size_t>(n) * static_cast<size_t>(m));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            const int cnt = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
            if (j > 1) out.push_back(' ');
            out.push_back(static_cast<char>('0' + cnt));
        }
        out.push_back('\n');
    }

    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
