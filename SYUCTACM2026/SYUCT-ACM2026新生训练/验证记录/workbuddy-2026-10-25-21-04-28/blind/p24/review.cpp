#include <cstdio>
#include <string>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) return 0;

    std::string out;
    out.reserve(static_cast<size_t>(n) * (static_cast<size_t>(m) + 1) + 16);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            out.push_back(((i + j) % 2 == 0) ? 'A' : 'B');
        }
        out.push_back('\n');
    }

    std::fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
