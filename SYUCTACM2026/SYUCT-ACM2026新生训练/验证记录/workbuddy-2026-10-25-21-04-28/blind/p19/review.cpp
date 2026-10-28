// 顺时针旋转 90 度
// 原矩阵 0-indexed 的 (i,j) 旋转后落在 (j, n-1-i)
// 等价地: b[r][c] = a[n-1-c][r], 其中 0 <= r < m, 0 <= c < n
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a((size_t)n * (size_t)m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[(size_t)i * m + j];

    // 手工整数转字符串 + 输出缓冲
    string out;
    out.reserve((size_t)n * (size_t)m * 12 + (size_t)m * 2);

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            int v = a[(size_t)(n - 1 - c) * m + r];
            if (c) out.push_back(' ');
            if (v == 0) {
                out.push_back('0');
            } else {
                bool neg = (v < 0);
                long long x = neg ? -(long long)v : (long long)v;
                char tmp[16];
                int tl = 0;
                while (x > 0) { tmp[tl++] = char('0' + (int)(x % 10)); x /= 10; }
                if (neg) out.push_back('-');
                while (tl > 0) out.push_back(tmp[--tl]);
            }
        }
        out.push_back('\n');
    }

    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
