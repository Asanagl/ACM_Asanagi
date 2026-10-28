#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end(), std::greater<char>());

    std::cout << s << '\n';
    return 0;
}
