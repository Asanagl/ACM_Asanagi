#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long spaces = 0;
    int c = std::cin.get();
    while (c != EOF && c != '\n') {
        if (c == ' ') {
            ++spaces;
        }
        c = std::cin.get();
    }

    std::cout << spaces << '\n';
    return 0;
}
