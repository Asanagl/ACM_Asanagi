#include <bits/stdc++.h>

using namespace std;

// 独立参考解：以盲审 Agent 的独立实现为基础，逐方向加边界判断，
// 与主解"补一圈 0 后直接求和"的结构不同。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    if (!(cin >> n >> m)) return 0;

    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    string out;
    out.reserve(static_cast<size_t>(2) * static_cast<size_t>(n) * static_cast<size_t>(m) +
                static_cast<size_t>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            if (i > 0 && g[i - 1][j] == '1') ++cnt;
            if (i + 1 < n && g[i + 1][j] == '1') ++cnt;
            if (j > 0 && g[i][j - 1] == '1') ++cnt;
            if (j + 1 < m && g[i][j + 1] == '1') ++cnt;
            if (j > 0) out.push_back(' ');
            out.push_back(static_cast<char>('0' + cnt));
        }
        out.push_back('\n');
    }

    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
