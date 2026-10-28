#include <cstdio>
#include <climits>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;

    long long best = LLONG_MIN;
    int bestRow = 1, bestCol = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x = 0;
            if (std::scanf("%lld", &x) != 1) return 0;
            // 严格大于才更新：行优先扫描下，等值时保留更早的位置
            if (x > best) {
                best = x;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    std::printf("%lld %d %d\n", best, bestRow, bestCol);
    return 0;
}
