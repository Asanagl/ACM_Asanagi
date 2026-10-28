#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    long long cnt = 0;
    if (std::getline(std::cin, s)) {
        for (char c : s) {
            if (c == ' ') ++cnt;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
