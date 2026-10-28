#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<char>(c - 'A' + 'a');
        }
    }
    std::cout << s << '\n';
    return 0;
}
