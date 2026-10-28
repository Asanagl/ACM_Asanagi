#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    if (!(std::cin >> n >> m)) return 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            std::cin >> a;
            std::cout << a;
            if (j + 1 < m) std::cout << ' ';
            else           std::cout << '\n';
        }
    }
    return 0;
}
