#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string s;
    std::cin >> s;
    std::swap(s.front(), s.back());
    std::cout << s << '\n';
    return 0;
}
