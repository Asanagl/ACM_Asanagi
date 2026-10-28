#include <cstdio>
#include <vector>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;
    if (n <= 0 || m <= 0) return 0;

    std::vector<long long> a(static_cast<size_t>(n) * static_cast<size_t>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x = 0;
            if (std::scanf("%lld", &x) != 1) x = 0;
            a[static_cast<size_t>(i) * static_cast<size_t>(m) + static_cast<size_t>(j)] = x;
        }
    }

    std::vector<long long> c(static_cast<size_t>(n) * static_cast<size_t>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x = 0;
            if (std::scanf("%lld", &x) != 1) x = 0;
            size_t pos = static_cast<size_t>(i) * static_cast<size_t>(m) + static_cast<size_t>(j);
            c[pos] = a[pos] + x;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) std::putchar(' ');
            std::printf("%lld", c[static_cast<size_t>(i) * static_cast<size_t>(m) + static_cast<size_t>(j)]);
        }
        std::putchar('\n');
    }
    return 0;
}
