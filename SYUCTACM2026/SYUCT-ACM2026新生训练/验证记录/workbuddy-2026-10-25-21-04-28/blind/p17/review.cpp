#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    for (int i = 0; i < n; ++i) {
        std::vector<int> row(m);
        for (int j = 0; j < m; ++j) std::cin >> row[j];
        for (int j = m - 1; j >= 0; --j) {
            std::cout << row[j];
            if (j > 0) std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
