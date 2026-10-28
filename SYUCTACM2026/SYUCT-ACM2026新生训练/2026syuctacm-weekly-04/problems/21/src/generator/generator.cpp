#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

using Grid = vector<string>;

static Grid randomGrid(int n, int m, int percentOne) {
    Grid g(n, string(m, '0'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] = (rnd.next(1, 100) <= percentOne) ? '1' : '0';
        }
    }
    return g;
}

static Grid blankGrid(int n, int m) {
    return Grid(n, string(m, '0'));
}

static void printGrid(const Grid& g) {
    cout << g.size() << ' ' << g[0].size() << '\n';
    for (const string& row : g) {
        cout << row << '\n';
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

    Grid g;

    if (type == "sample") {
        // 与题面样例一完全一致
        g = {"0101", "1010", "0010", "1101"};
    } else if (type == "sample-single-row") {
        // 与题面样例二完全一致
        g = {"11111"};
    } else if (type == "min-zero") {
        // 最小规模：1x1 且格子为空
        g = {"0"};
    } else if (type == "min-one") {
        // 最小规模：1x1 且格子被占据（唯一格子的答案必为 0）
        g = {"1"};
    } else if (type == "small") {
        const int n = static_cast<int>(rnd.next(2, 6));
        const int m = static_cast<int>(rnd.next(2, 6));
        g = randomGrid(n, m, 50);
    } else if (type == "single-row") {
        // 特殊形状：只有一行，所有格子缺少上下邻居
        g = randomGrid(1, static_cast<int>(rnd.next(2, 12)), 50);
    } else if (type == "single-col") {
        // 特殊形状：只有一列，所有格子缺少左右邻居
        g = randomGrid(static_cast<int>(rnd.next(2, 12)), 1, 50);
    } else if (type == "all-zero") {
        const int n = static_cast<int>(rnd.next(3, 15));
        const int m = static_cast<int>(rnd.next(3, 15));
        g = blankGrid(n, m);
    } else if (type == "all-one") {
        // 全 1：内部 4、边界 3、四角 2，八邻域错解会得到更大的值
        const int n = static_cast<int>(rnd.next(3, 15));
        const int m = static_cast<int>(rnd.next(3, 15));
        g = Grid(n, string(m, '1'));
    } else if (type == "checkerboard") {
        const int n = static_cast<int>(rnd.next(5, 10));
        const int m = static_cast<int>(rnd.next(5, 10));
        g = blankGrid(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                g[i][j] = ((i + j) % 2 == 0) ? '1' : '0';
            }
        }
    } else if (type == "diagonal") {
        // 斜向陷阱：1 只出现在两条对角线上，正交邻居恒为 0
        const int n = static_cast<int>(rnd.next(6, 12));
        g = blankGrid(n, n);
        for (int i = 0; i < n; ++i) {
            g[i][i] = '1';
            g[i][n - 1 - i] = '1';
        }
    } else if (type == "ring") {
        // 特殊形状：只有外圈为 1，中心大面积为空
        const int n = static_cast<int>(rnd.next(8, 12));
        const int m = static_cast<int>(rnd.next(8, 12));
        g = blankGrid(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    g[i][j] = '1';
                }
            }
        }
    } else if (type == "center-dot") {
        // 单点：只有中心一个 1，远离边界的孤立点
        const int n = 2 * static_cast<int>(rnd.next(2, 5)) + 1;
        const int m = 2 * static_cast<int>(rnd.next(2, 5)) + 1;
        g = blankGrid(n, m);
        g[n / 2][m / 2] = '1';
    } else if (type == "corners") {
        // 边界定向：1 只在四个角上，四角邻居数最少
        const int n = static_cast<int>(rnd.next(3, 12));
        const int m = static_cast<int>(rnd.next(3, 12));
        g = blankGrid(n, m);
        g[0][0] = '1';
        g[0][m - 1] = '1';
        g[n - 1][0] = '1';
        g[n - 1][m - 1] = '1';
    } else if (type == "tiled") {
        // 重复：把随机的 3x3 小块平铺到整个网格
        const int n = static_cast<int>(rnd.next(4, 12));
        const int m = static_cast<int>(rnd.next(4, 12));
        const Grid tile = randomGrid(3, 3, 50);
        g = blankGrid(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                g[i][j] = tile[i % 3][j % 3];
            }
        }
    } else if (type == "repeat-rows") {
        // 重复：每一行完全相同
        const int n = static_cast<int>(rnd.next(4, 12));
        const int m = static_cast<int>(rnd.next(4, 12));
        const string row = randomGrid(1, m, 50)[0];
        g = Grid(n, row);
    } else if (type == "kill-diagonal") {
        // 定向击杀：对角线上密集、正交方向稀疏，八邻域实现会明显偏大
        const int n = static_cast<int>(rnd.next(5, 9));
        g = blankGrid(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = (i == j || i + j == n - 1) ? '1' : '0';
            }
        }
        g[0][1] = '1';
        g[n - 1][n - 2] = '1';
    } else if (type == "kill-self") {
        // 定向击杀：1x1 的 1，把自身计入的实现会输出 1，正确答案是 0
        g = {"1"};
    } else if (type == "kill-wrap") {
        // 定向击杀：一行形状、两端都是 1，缺少边界检查而取模回绕的实现会在端点多算
        const int m = static_cast<int>(rnd.next(4, 9));
        g = blankGrid(1, m);
        g[0][0] = '1';
        g[0][m - 1] = '1';
    } else if (type == "kill-boundary") {
        // 定向击杀：最后一行与最后一列全为 1，漏掉下/右方向边界的实现会在底部与右侧出错
        const int n = static_cast<int>(rnd.next(4, 9));
        const int m = static_cast<int>(rnd.next(4, 9));
        g = blankGrid(n, m);
        for (int j = 0; j < m; ++j) {
            g[n - 1][j] = '1';
        }
        for (int i = 0; i < n; ++i) {
            g[i][m - 1] = '1';
        }
    } else if (type == "kill-count-neighbors") {
        // 定向击杀：2x2 全零，统计“邻居个数”而不是“值为 1 的邻居个数”的实现会输出 2
        const int n = static_cast<int>(rnd.next(2, 6));
        const int m = static_cast<int>(rnd.next(2, 6));
        g = blankGrid(n, m);
    } else if (type == "random") {
        const int n = static_cast<int>(rnd.next(1, 500));
        const int m = static_cast<int>(rnd.next(1, 500));
        g = randomGrid(n, m, 50);
    } else if (type == "random-sparse") {
        const int n = static_cast<int>(rnd.next(50, 300));
        const int m = static_cast<int>(rnd.next(50, 300));
        g = randomGrid(n, m, 5);
    } else if (type == "random-dense") {
        const int n = static_cast<int>(rnd.next(50, 300));
        const int m = static_cast<int>(rnd.next(50, 300));
        g = randomGrid(n, m, 90);
    } else if (type == "mixed-shapes") {
        // 随机在细长、正方、宽扁等形状间切换
        const int kind = static_cast<int>(rnd.next(0, 3));
        int n = 0, m = 0;
        if (kind == 0) {
            n = 1;
            m = static_cast<int>(rnd.next(100, 500));
        } else if (kind == 1) {
            n = static_cast<int>(rnd.next(100, 500));
            m = 1;
        } else if (kind == 2) {
            n = static_cast<int>(rnd.next(2, 500));
            m = static_cast<int>(rnd.next(2, 500));
        } else {
            n = static_cast<int>(rnd.next(60, 90));
            m = static_cast<int>(rnd.next(420, 500));
        }
        g = randomGrid(n, m, 50);
    } else if (type == "near-max") {
        const bool tall = (seed % 2 == 0);
        const int n = tall ? 500 : 499;
        const int m = tall ? 499 : 500;
        g = randomGrid(n, m, 50);
    } else if (type == "max") {
        g = randomGrid(500, 500, 50);
    } else if (type == "max-one") {
        g = Grid(500, string(500, '1'));
    } else if (type == "max-row") {
        g = randomGrid(1, 500, 50);
    } else if (type == "max-col") {
        g = randomGrid(500, 1, 50);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    printGrid(g);
    return 0;
}
