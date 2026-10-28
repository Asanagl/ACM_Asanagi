#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) {
        return 0;
    }

    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x;
            std::cin >> x;

            if (i == 1 || i == n || j == 1 || j == m) {
                sum += x;
            }
        }
    }

    std::cout << sum << '\n';
    return 0;
}
