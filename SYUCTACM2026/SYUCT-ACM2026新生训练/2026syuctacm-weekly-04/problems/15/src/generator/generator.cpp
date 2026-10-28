#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

static void emit(const vector<vector<long long>>& g) {
    const int n = static_cast<int>(g.size());
    const int m = static_cast<int>(g[0].size());
    string out;
    out.reserve(static_cast<size_t>(n) * m * 12 + 32);
    out += to_string(n);
    out += ' ';
    out += to_string(m);
    out += '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                out += ' ';
            }
            out += to_string(g[i][j]);
        }
        out += '\n';
    }
    fwrite(out.data(), 1, out.size(), stdout);
}

static vector<vector<long long>> makeGrid(int n, int m) {
    return vector<vector<long long>>(n, vector<long long>(m, 0));
}

static void fillRandom(vector<vector<long long>>& g, long long lo, long long hi) {
    for (auto& row : g) {
        for (auto& cell : row) {
            cell = rnd.next(lo, hi);
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    if (type == "sample") {
        if (seed == 1) {
            emit({{1, 7, 3, 7}, {5, 2, 7, 4}, {6, 0, 7, 1}});
        } else if (seed == 2) {
            emit({{-5, -1, -9}, {-1, -7, -3}});
        } else {
            emit({{-1000000000LL}});
        }
        return 0;
    }

    if (type == "min") {
        // 1x1：最小规模，值覆盖 0、负下界、正上界
        const long long candidates[] = {0, -1, -1000000000LL, 1000000000LL, 42};
        const long long value = candidates[seed % 5];
        emit({{value}});
        return 0;
    }

    if (type == "tiny") {
        // 2x2 / 3x3：最小非平凡形状，含重复
        const int n = (seed % 2 == 0) ? 2 : 3;
        const int m = (seed % 2 == 0) ? 2 : 3;
        auto g = makeGrid(n, m);
        fillRandom(g, -3, 3);
        const long long top = rnd.next(4, 9);
        g[0][0] = top;
        g[n - 1][m - 1] = top;  // 让最大值同时出现在首尾，tie 规则生效
        emit(g);
        return 0;
    }

    if (type == "one-row") {
        const int m = rnd.next(2, 200);
        auto g = makeGrid(1, m);
        fillRandom(g, -100, 100);
        const long long top = 1000000;
        if (seed % 3 == 0) {
            g[0][0] = top;                     // 答案在第 1 列
        } else if (seed % 3 == 1) {
            g[0][m - 1] = top;                 // 答案在第 m 列
        } else {
            const int c = rnd.next(1, m - 2);
            g[0][c] = top;
            g[0][m - 1] = top;                 // 同一行内重复，答案仍是 c
        }
        emit(g);
        return 0;
    }

    if (type == "one-col") {
        const int n = rnd.next(2, 200);
        auto g = makeGrid(n, 1);
        fillRandom(g, -100, 100);
        const long long top = 1000000;
        if (seed % 3 == 0) {
            g[0][0] = top;
        } else if (seed % 3 == 1) {
            g[n - 1][0] = top;
        } else {
            const int r = rnd.next(1, n - 2);
            g[r][0] = top;
            g[n - 1][0] = top;
        }
        emit(g);
        return 0;
    }

    if (type == "square") {
        const int n = rnd.next(4, 40);
        auto g = makeGrid(n, n);
        fillRandom(g, -5, 5);  // 小范围取值，保证大量并列
        emit(g);
        return 0;
    }

    if (type == "duplicate") {
        const int n = rnd.next(3, 15);
        const int m = rnd.next(3, 20);
        auto g = makeGrid(n, m);
        const long long top = rnd.next(100, 1000);
        fillRandom(g, top - 400, top - 1);
        const int firstR = rnd.next(0, n - 1);
        const int firstC = rnd.next(0, m - 1);
        g[firstR][firstC] = top;
        // 在首次出现之后的位置再放几个并列最大值
        int placed = 0;
        for (int attempt = 0; attempt < 200 && placed < 4; ++attempt) {
            const int r = rnd.next(0, n - 1);
            const int c = rnd.next(0, m - 1);
            if (r > firstR || (r == firstR && c > firstC)) {
                g[r][c] = top;
                ++placed;
            }
        }
        if (placed == 0) {
            g[n - 1][m - 1] = top;
        }
        emit(g);
        return 0;
    }

    if (type == "negative") {
        const int n = rnd.next(2, 30);
        const int m = rnd.next(2, 30);
        auto g = makeGrid(n, m);
        const long long top = rnd.next(-1000, -1);
        fillRandom(g, top - 300, top - 1);
        const int r = rnd.next(0, n - 1);
        const int c = rnd.next(0, m - 1);
        g[r][c] = top;
        if (seed % 2 == 0) {
            g[n - 1][m - 1] = top;  // 并列最大值在更靠后的位置
        }
        if (seed % 3 == 0) {
            g[0][m - 1] = top;
        }
        emit(g);
        return 0;
    }

    if (type == "mixed") {
        const int n = rnd.next(2, 25);
        const int m = rnd.next(2, 25);
        auto g = makeGrid(n, m);
        fillRandom(g, -5, 5);
        g[0][0] = 0;
        g[n - 1][m - 1] = 0;
        emit(g);
        return 0;
    }

    if (type == "big-value") {
        const int n = rnd.next(2, 20);
        const int m = rnd.next(2, 20);
        auto g = makeGrid(n, m);
        fillRandom(g, -1000000000LL, -1);
        const int firstR = rnd.next(0, n - 1);
        const int firstC = rnd.next(0, m - 1);
        g[firstR][firstC] = 1000000000LL;
        if (seed % 2 == 0) {
            g[n - 1][m - 1] = 1000000000LL;
        }
        if (seed % 3 == 0) {
            g[0][m - 1] = 1000000000LL;
        }
        g[0][0] = -1000000000LL;
        emit(g);
        return 0;
    }

    if (type == "grid-tie") {
        // 定向：最大值同时出现在 (1,m) 与 (n,1)，列优先实现必然答错
        const int n = rnd.next(3, 20);
        const int m = rnd.next(3, 20);
        auto g = makeGrid(n, m);
        const long long top = rnd.next(500, 5000);
        fillRandom(g, top - 300, top - 1);
        g[0][m - 1] = top;   // 行优先第一次出现
        g[n - 1][0] = top;   // 列号更小但行号更大
        if (seed % 2 == 0) {
            g[n - 1][m - 1] = top;
        }
        if (seed % 3 == 0) {
            g[0][0] = top - 1;
        }
        emit(g);
        return 0;
    }

    if (type == "anti-last") {
        // 定向：扫描顺序上最后一个格子也是最大值，专杀 >= 更新
        const int n = rnd.next(3, 25);
        const int m = rnd.next(3, 25);
        auto g = makeGrid(n, m);
        const long long top = rnd.next(1000, 9000);
        fillRandom(g, top - 500, top - 1);
        g[0][m - 1] = top;      // 第一次出现
        g[n - 1][0] = top;
        g[n - 1][m - 1] = top;  // 扫描顺序最后
        g[0][0] = top - 1;
        g[n / 2][m / 2] = top;
        emit(g);
        return 0;
    }

    if (type == "corner") {
        if (seed % 2 == 0) {
            // 唯一最大值在 (1,1)，答案位置恒为 1 1
            const int n = rnd.next(2, 15);
            const int m = rnd.next(2, 15);
            auto g = makeGrid(n, m);
            fillRandom(g, -1000, 999);
            g[0][0] = 2000;
            emit(g);
        } else {
            // 唯一最大值在 (n,m)，且 n != m，同时卡漏最后一行/列与行列互换
            const int n = rnd.next(2, 15);
            const int m = rnd.next(16, 30);
            auto g = makeGrid(n, m);
            fillRandom(g, -1000, 999);
            g[n - 1][m - 1] = 2000;
            emit(g);
        }
        return 0;
    }

    if (type == "all-same") {
        const int n = rnd.next(2, 50);
        const int m = rnd.next(2, 50);
        const long long values[] = {0, -1000000000LL, 1000000000LL, -7};
        const long long v = values[seed % 4];
        auto g = makeGrid(n, m);
        for (auto& row : g) {
            for (auto& cell : row) {
                cell = v;
            }
        }
        emit(g);
        return 0;
    }

    if (type == "single-max") {
        // 唯一最大值恰好在最后一行最后一列
        const int n = rnd.next(2, 60);
        const int m = rnd.next(61, 120);
        auto g = makeGrid(n, m);
        fillRandom(g, -500, 500);
        g[n - 1][m - 1] = 5000;
        emit(g);
        return 0;
    }

    if (type == "last-row-dup") {
        // 最大值只出现在最后一行，且在两个不同列上并列
        const int n = rnd.next(2, 40);
        const int m = rnd.next(3, 40);
        auto g = makeGrid(n, m);
        const long long top = rnd.next(700, 7000);
        fillRandom(g, top - 600, top - 1);
        const int c1 = rnd.next(0, m - 2);
        int c2 = rnd.next(c1 + 1, m - 1);
        if (seed % 2 == 1) {
            c2 = m - 1;
        }
        g[n - 1][c1] = top;
        g[n - 1][c2] = top;
        emit(g);
        return 0;
    }

    if (type == "near-limit") {
        auto g = makeGrid(200, 200);
        fillRandom(g, -1000000000LL, 1000000000LL);
        if (seed % 2 == 0) {
            g[0][199] = 1000000000LL;
            g[199][0] = 1000000000LL;
            g[199][199] = 1000000000LL;
        }
        emit(g);
        return 0;
    }

    if (type == "near-limit-dup") {
        auto g = makeGrid(200, 200);
        const long long top = 1000000000LL;
        fillRandom(g, top - 2000000, top - 1);
        const int firstR = rnd.next(0, 199);
        const int firstC = rnd.next(0, 199);
        g[firstR][firstC] = top;
        for (int attempt = 0; attempt < 50; ++attempt) {
            const int r = rnd.next(0, 199);
            const int c = rnd.next(0, 199);
            if (r > firstR || (r == firstR && c > firstC)) {
                g[r][c] = top;
            }
        }
        g[199][199] = top;
        emit(g);
        return 0;
    }

    if (type == "near-limit-neg") {
        auto g = makeGrid(200, 200);
        const long long top = -1;
        fillRandom(g, -1000000000LL, top - 1);
        const int firstR = rnd.next(0, 199);
        const int firstC = rnd.next(0, 199);
        g[firstR][firstC] = top;
        g[199][199] = top;
        if (seed % 2 == 0) {
            g[0][199] = top;
            g[199][0] = top;
        }
        emit(g);
        return 0;
    }

    if (type == "directed") {
        // 综合定向：行优先第一次出现在 (1,m)，同时 (n,1)、(n,m) 也是最大值
        const int n = 5;
        const int m = 7;
        auto g = makeGrid(n, m);
        const long long top = 8192;
        fillRandom(g, -8192, top - 1);
        g[0][m - 1] = top;
        g[n - 1][0] = top;
        g[n - 1][m - 1] = top;
        g[2][3] = top;
        g[0][0] = top - 1;
        emit(g);
        return 0;
    }

    if (type == "random") {
        const int n = rnd.next(1, 200);
        const int m = rnd.next(1, 200);
        auto g = makeGrid(n, m);
        if (seed % 2 == 0) {
            // 小值域，制造大量并列
            fillRandom(g, -4, 4);
        } else {
            fillRandom(g, -1000000000LL, 1000000000LL);
        }
        emit(g);
        return 0;
    }

    cerr << "Unknown case type: " << type << '\n';
    return 2;
}
