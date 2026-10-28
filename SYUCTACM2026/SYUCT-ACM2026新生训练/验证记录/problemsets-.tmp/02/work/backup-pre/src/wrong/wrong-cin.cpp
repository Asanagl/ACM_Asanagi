#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int answer = 0;
    for (char c : s) {
        if (c == ' ') {
            ++answer;
        }
    }

    std::cout << answer << '\n';
    return 0;
}
