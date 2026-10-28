#include <iostream>
#include <string>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    const std::size_t n = s.size();
    for (std::size_t i = 0; i <= n / 2; ++i) {
        std::swap(s[i], s[n - 1 - i]);
    }

    std::cout << s << '\n';
    return 0;
}
