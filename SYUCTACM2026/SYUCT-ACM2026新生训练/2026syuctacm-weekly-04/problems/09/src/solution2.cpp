// 独立参考解：不使用 substr，逐字符把 [l, r] 内的字符追加到结果串。
// 与主解的 substr 写法在实现路径上完全独立，用于交叉验证。
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    int l = 0, r = 0;
    if (!(std::cin >> s >> l >> r)) {
        return 0;
    }

    const int length = r - l + 1;
    std::string answer;
    answer.reserve(static_cast<std::size_t>(length));
    for (int offset = 0; offset < length; ++offset) {
        answer.push_back(s[static_cast<std::size_t>(l - 1 + offset)]);
    }

    std::cout << answer << '\n';
    return 0;
}
