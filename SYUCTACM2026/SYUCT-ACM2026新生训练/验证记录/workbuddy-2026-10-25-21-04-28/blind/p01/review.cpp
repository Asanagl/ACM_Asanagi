#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) return 0;   // 无输入则不输出
    if (s.empty()) return 0;          // 防御：n == 0 时避免 size()-1 回绕

    std::cout << s.size() << ' ' << s.front() << ' ' << s.back() << '\n';
    return 0;
}
