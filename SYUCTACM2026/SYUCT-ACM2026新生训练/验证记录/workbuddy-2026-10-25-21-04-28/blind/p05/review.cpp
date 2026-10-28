#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) return 0;

    char x = 0, y = 0;
    std::cin >> x >> y;

    for (char &c : s) {
        if (c == x) c = y;
    }

    std::cout << s << '\n';
    return 0;
}
