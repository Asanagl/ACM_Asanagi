#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::getline(std::cin, line);

    long long answer = 0;
    for (std::size_t i = 0; i < line.size(); ++i) {
        std::string prefix;
        prefix.reserve(i + 1);
        for (std::size_t j = 0; j <= i; ++j) {
            prefix.push_back(line[j]);
        }
        answer = static_cast<long long>(std::count(prefix.begin(), prefix.end(), ' '));
    }

    std::cout << answer << '\n';
    return 0;
}
