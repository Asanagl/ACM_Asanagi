#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s) {
        if (c >= 'A' && c <= 'z') {
            if (c <= 'Z') {
                c = static_cast<char>(c + 32);
            } else {
                c = static_cast<char>(c - 32);
            }
        }
    }
    std::cout << s << '\n';
    return 0;
}
