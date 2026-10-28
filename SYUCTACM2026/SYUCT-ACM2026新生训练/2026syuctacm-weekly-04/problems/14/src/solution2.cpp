#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0, m = 0;
    if (!(std::cin >> n >> m)) {
        return 0;
    }

    std::vector<long long> columnSum(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long value = 0;
            std::cin >> value;
            columnSum[j] += value;
        }
    }

    for (int j = 0; j < m; ++j) {
        if (j > 0) {
            std::cout << ' ';
        }
        std::cout << columnSum[j];
    }
    std::cout << '\n';

    return 0;
}
