#include <iostream>
#include <string>

// 独立参考解：由只读盲审给出的实现为基础整理而来。
// 与主解的关键差异：按下标遍历，而不是范围 for。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) {
        return 0;
    }

    long long sum = 0;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }

    std::cout << sum << '\n';
    return 0;
}
