#include <cstdio>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;

    static long long a[105][105];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (std::scanf("%lld", &a[i][j]) != 1) return 0;
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i) std::putchar(' ');
            std::printf("%lld", a[i][j]);
        }
        std::putchar('\n');
    }

    return 0;
}
