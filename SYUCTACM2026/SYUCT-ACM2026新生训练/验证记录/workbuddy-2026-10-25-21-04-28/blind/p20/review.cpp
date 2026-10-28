#include <cstdio>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x = 0;
            if (std::scanf("%lld", &x) != 1) x = 0;  // 输入保证完整，此处仅为健壮性
            // 属于边框：第一行 / 最后一行 / 第一列 / 最后一列；同一格子只判定一次、只累加一次
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                ans += x;
            }
        }
    }

    std::printf("%lld\n", ans);
    return 0;
}
