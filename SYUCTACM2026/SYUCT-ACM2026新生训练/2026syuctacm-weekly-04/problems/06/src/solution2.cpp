#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::reverse(s.begin(), s.end());

    std::cout << s << '\n';
    return 0;
}
