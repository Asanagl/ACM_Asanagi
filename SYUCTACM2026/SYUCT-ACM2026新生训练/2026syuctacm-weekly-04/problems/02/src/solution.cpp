#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::getline(std::cin, line);

    int spaces = 0;
    for (std::size_t i = 0; i < line.size(); ++i) {
        if (line[i] == ' ') {
            ++spaces;
        }
    }

    std::cout << spaces << '\n';
    return 0;
}
