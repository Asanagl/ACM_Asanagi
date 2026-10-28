// Independent reference implementation produced by the blind-review solver and
// reviewed by the main author: it initialises the running maximum with LLONG_MIN
// instead of the first cell, streams the input without storing the matrix, and
// uses scanf/printf instead of the iostream layer used by solution.cpp.
#include <climits>
#include <cstdio>

int main() {
    int n = 0;
    int m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    long long best = LLONG_MIN;
    int bestRow = 1;
    int bestCol = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x = 0;
            std::scanf("%lld", &x);
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
