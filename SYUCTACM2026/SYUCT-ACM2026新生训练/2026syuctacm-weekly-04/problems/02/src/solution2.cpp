#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long cnt = 0;
    int c = std::cin.get();
    while (c != EOF && c != '\n') {
        if (c == ' ') {
            ++cnt;
        }
        c = std::cin.get();
    }

    std::cout << cnt << '\n';
    return 0;
}
