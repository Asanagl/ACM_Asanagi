#include <cstddef>
#include <cstdio>
#include <vector>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;

    const std::size_t total =
        static_cast<std::size_t>(n) * static_cast<std::size_t>(m);
    const std::size_t cols = static_cast<std::size_t>(m);

    std::vector<int> a(total);

    for (std::size_t k = 0; k < total; ++k) {
        if (std::scanf("%d", &a[k]) != 1) return 0;
    }

    for (std::size_t k = 0; k < total; ++k) {
        int b = 0;
        if (std::scanf("%d", &b) != 1) return 0;
        a[k] += b;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) std::putchar(' ');
            const std::size_t idx =
                static_cast<std::size_t>(i) * cols + static_cast<std::size_t>(j);
            std::printf("%d", a[idx]);
        }
        std::putchar('\n');
    }

    return 0;
}
