// 棋盘染色 —— 独立参考解：不用闭式奇偶公式，而是"逐格传播"地染色。
// 每一行的首列由上一行首列翻转得到，行内再从首列往后逐格交替。
// 这条实现路径与主解的 (i+j) 闭式完全无关，用来交叉印证唯一性结论。
#include <cstdio>
#include <string>
#include <vector>

int main() {
    int n = 0, m = 0;
    if (std::scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    std::string row(static_cast<std::size_t>(m), 'A');
    char first = 'A';  // 当前行首列的颜色，初始为 (1,1)=A

    for (int i = 0; i < n; ++i) {
        char c = first;
        for (int j = 0; j < m; ++j) {
            row[static_cast<std::size_t>(j)] = c;
            c = (c == 'A') ? 'B' : 'A';
        }
        std::fwrite(row.data(), 1, row.size(), stdout);
        std::fputc('\n', stdout);
        // 下一行的首列必须与上一行首列异色
        first = (first == 'A') ? 'B' : 'A';
    }

    return 0;
}
