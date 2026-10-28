#include <iostream>
#include <string>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        ++left;
        --right;
    }

    std::cout << s << '\n';
    return 0;
}
