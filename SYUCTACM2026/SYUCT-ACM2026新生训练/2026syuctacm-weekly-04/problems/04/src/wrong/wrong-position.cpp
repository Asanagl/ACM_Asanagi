#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (size_t i = 0; i < s.size(); ++i) {
        if (i % 2 != 0) {
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = static_cast<char>(s[i] - 'A' + 'a');
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = static_cast<char>(s[i] - 'a' + 'A');
        }
    }
    std::cout << s << '\n';
    return 0;
}
