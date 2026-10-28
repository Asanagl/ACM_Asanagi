#include <array>
#include <cstdio>
#include <iostream>
#include <string>

// 语义来自只读盲审给出的独立作答：逐字符把 x 映射成 y。
// 实现路径与主解不同：主解是下标循环 + 逐个比较；本解先构造 26 项映射表，
// 再用范围 for 查表改写，最后一次性块输出。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x = 'a', y = 'a';
    if (!(std::cin >> s >> x >> y)) {
        return 0;
    }

    std::array<char, 26> map{};
    for (int i = 0; i < 26; ++i) {
        map[static_cast<std::size_t>(i)] = static_cast<char>('a' + i);
    }
    map[static_cast<std::size_t>(x - 'a')] = y;

    for (char &c : s) {
        c = map[static_cast<std::size_t>(c - 'a')];
    }
    s.push_back('\n');

    std::fwrite(s.data(), 1, s.size(), stdout);
    return 0;
}
