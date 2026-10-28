#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    const int n = static_cast<int>(s.size());

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}
