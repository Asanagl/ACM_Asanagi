#include <iostream>
#include <string>

int main() {
    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>(c - 'A' + 'a');
        } else if (c >= 'a' && c <= 'z') {
            c = static_cast<char>(c - 'a' + 'A');
        }
    }
    std::cout << s << '\n';
    return 0;
}
