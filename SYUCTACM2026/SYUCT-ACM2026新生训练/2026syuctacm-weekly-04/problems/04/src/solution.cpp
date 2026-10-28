#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::getline(std::cin, s);

    for (char &c : s) {
        const unsigned char u = static_cast<unsigned char>(c);
        if (std::isupper(u)) {
            c = static_cast<char>(std::tolower(u));
        } else if (std::islower(u)) {
            c = static_cast<char>(std::toupper(u));
        }
    }

    std::cout << s << '\n';
    return 0;
}
