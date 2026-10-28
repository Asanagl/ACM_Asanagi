#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int answer = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        int prefixCount = 0;
        for (std::size_t j = 0; j <= i; ++j) {
            if (s[j] == ' ') {
                ++prefixCount;
            }
        }
        answer = prefixCount;
    }

    std::cout << answer << '\n';
    return 0;
}
