#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    for (int i = static_cast<int>(s.size()) - 2; i >= 0; --i) {
        std::cout << s[i];
    }
    std::cout << '\n';
    return 0;
}
