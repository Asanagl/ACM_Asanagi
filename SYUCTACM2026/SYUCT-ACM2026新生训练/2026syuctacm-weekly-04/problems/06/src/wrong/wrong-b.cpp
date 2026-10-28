#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::string reversed;
    for (char c : s) {
        reversed.insert(reversed.begin(), c);
    }

    std::cout << reversed << '\n';
    return 0;
}
