#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int answer = 0;
    bool previousWasSpace = false;
    for (char c : s) {
        if (c == ' ' && !previousWasSpace) {
            ++answer;
        }
        previousWasSpace = (c == ' ');
    }

    std::cout << answer << '\n';
    return 0;
}
