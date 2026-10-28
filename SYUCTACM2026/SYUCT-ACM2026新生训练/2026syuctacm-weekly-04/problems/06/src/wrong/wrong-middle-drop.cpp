#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    const int n = static_cast<int>(s.size());
    const int middle = n / 2;
    for (int i = n - 1; i >= 0; --i) {
        if (n % 2 == 1 && i == middle) {
            continue;
        }
        std::cout << s[i];
    }
    std::cout << '\n';
    return 0;
}
