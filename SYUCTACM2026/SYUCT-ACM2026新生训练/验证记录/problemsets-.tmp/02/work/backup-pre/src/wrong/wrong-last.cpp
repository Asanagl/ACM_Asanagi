#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int answer = 0;
    for (std::size_t i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == ' ') {
            ++answer;
        }
    }

    std::cout << answer << '\n';
    return 0;
}
