// 子矩阵求和 —— 可复现数据生成器。
// 用法：generator <type> <seed>；类型与 config.json 的 generator.cases 一一对应。
#include "testlib.h"

#include <array>
#include <bits/stdc++.h>

using namespace std;

static int n, m, q;
static vector<vector<long long>> a;
static vector<array<int, 4>> queries;

static void genUniform(long long lo, long long hi) {
    a.assign(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = rnd.next(lo, hi);
        }
    }
}

static void genConst(long long v) {
    a.assign(n + 1, vector<long long>(m + 1, v));
}

static void genChecker(long long v) {
    a.assign(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = ((i + j) % 2 == 0) ? v : -v;
        }
    }
}

// 随机闭区间询问，保证 r1 <= r2、c1 <= c2。
static void addRandomQueries() {
    for (int k = 0; k < q; ++k) {
        int r1 = rnd.next(1, n);
        int r2 = rnd.next(r1, n);
        int c1 = rnd.next(1, m);
        int c2 = rnd.next(c1, m);
        queries.push_back({r1, c1, r2, c2});
    }
}

static void addFullQueries() {
    for (int k = 0; k < q; ++k) {
        queries.push_back({1, 1, n, m});
    }
}

static void addPointQueries() {
    for (int k = 0; k < q; ++k) {
        int r = rnd.next(1, n);
        int c = rnd.next(1, m);
        queries.push_back({r, c, r, c});
    }
}

static void printCase() {
    cout << n << ' ' << m << ' ' << q << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j > 1) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
    for (const auto& query : queries) {
        cout << query[0] << ' ' << query[1] << ' ' << query[2] << ' ' << query[3] << '\n';
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const int seed = atoi(argv[2]);
    rnd.setSeed(seed);

    if (type == "sample") {
        // 与 docs/statement.md 的样例逐字一致。
        n = 3;
        m = 4;
        q = 7;
        a.assign(n + 1, vector<long long>(m + 1, 0));
        a[1] = {0, 1000000000LL, 1000000000LL, 1000000000LL, -1000000000LL};
        a[2] = {0, 1000000000LL, -1000000000LL, 1000000000LL, 1000000000LL};
        a[3] = {0, -1000000000LL, 1000000000LL, 1000000000LL, 1000000000LL};
        queries = {{1, 1, 3, 4}, {1, 1, 2, 2}, {2, 2, 3, 3}, {1, 3, 1, 3},
                   {2, 4, 3, 4}, {1, 1, 3, 1}, {1, 4, 3, 4}};
    } else if (type == "min-neg") {
        n = 1;
        m = 1;
        q = 1;
        genConst(-1000000000LL);
        addFullQueries();
    } else if (type == "min-pos") {
        n = 1;
        m = 1;
        q = 3;
        genConst(1000000000LL);
        for (int k = 0; k < q; ++k) {
            queries.push_back({1, 1, 1, 1});
        }
    } else if (type == "single-row") {
        // 退化成一维：只有一行，验证行边界不越界。
        n = 1;
        m = 100;
        q = 60;
        genUniform(-1000000000LL, 1000000000LL);
        addRandomQueries();
    } else if (type == "single-col") {
        // 退化成一维：只有一列，验证列边界不越界。
        n = 100;
        m = 1;
        q = 60;
        genUniform(-1000000000LL, 1000000000LL);
        addRandomQueries();
    } else if (type == "square-small") {
        // 3×3 递增矩阵，便于人工核对，覆盖各种小矩形。
        n = 3;
        m = 3;
        q = 9;
        a.assign(n + 1, vector<long long>(m + 1, 0));
        long long v = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                a[i][j] = v++;
            }
        }
        queries = {{1, 1, 1, 1}, {1, 1, 3, 3}, {2, 2, 3, 3}, {1, 3, 3, 3},
                   {3, 1, 3, 3}, {1, 2, 2, 3}, {2, 1, 2, 1}, {1, 1, 2, 3},
                   {2, 2, 2, 2}};
    } else if (type == "duplicate") {
        // 全矩阵同一个值：只考边界覆盖，不考数值差异。
        n = 50;
        m = 50;
        q = 100;
        genConst(7);
        addRandomQueries();
    } else if (type == "zero") {
        // 全零矩阵：答案必须是 0，防止把空区间当非零。
        n = 20;
        m = 20;
        q = 40;
        genConst(0);
        addRandomQueries();
    } else if (type == "negative") {
        // 全负矩阵：答案全为负，防止用无符号类型或漏符号。
        n = 30;
        m = 40;
        q = 80;
        genUniform(-1000000000LL, -1LL);
        addRandomQueries();
    } else if (type == "checkerboard") {
        // 正负交替，正负相消，答案可能为 0 或很小的值。
        n = 50;
        m = 50;
        q = 100;
        genChecker(1000000000LL);
        addRandomQueries();
    } else if (type == "large-sum") {
        // 100×100 全 1e9，整矩阵询问 → 1e13，稳定击杀 int 累加。
        n = 100;
        m = 100;
        q = 8;
        genConst(1000000000LL);
        addFullQueries();
        // 再加几个小矩形，避免只有单一答案。
        for (int k = 0; k < 4; ++k) {
            queries.push_back({1, 1, rnd.next(1, n), rnd.next(1, m)});
        }
        q = static_cast<int>(queries.size());
    } else if (type == "large-neg") {
        // 100×100 全 -1e9，整矩阵询问 → -1e13。
        n = 100;
        m = 100;
        q = 8;
        genConst(-1000000000LL);
        addFullQueries();
    } else if (type == "full-cover") {
        // 每次询问都覆盖整个矩阵，答案恒等于全矩阵和。
        n = 40;
        m = 40;
        q = 40;
        genUniform(-1000000000LL, 1000000000LL);
        addFullQueries();
    } else if (type == "point-query") {
        // 全部单格询问：答案必须恰好等于该格的值。
        n = 60;
        m = 60;
        q = 400;
        genUniform(-1000000000LL, 1000000000LL);
        addPointQueries();
    } else if (type == "target-half") {
        // 只有最后一行和最后一列可能非零，且询问常常触达末行/末列。
        // 把闭区间当成半开区间的实现会稳定漏掉边界，从而输出 0。
        n = 30;
        m = 30;
        q = 100;
        genConst(0);
        for (int j = 1; j <= m; ++j) {
            a[n][j] = 1000000000LL;
        }
        for (int i = 1; i <= n; ++i) {
            a[i][m] = 1000000000LL;
        }
        for (int k = 0; k < q; ++k) {
            int r1 = rnd.next(1, n);
            int r2 = rnd.next(r1, n);
            int c1 = rnd.next(1, m);
            int c2 = rnd.next(c1, m);
            if (k % 2 == 0) {
                r2 = n;
            } else {
                c2 = m;
            }
            queries.push_back({r1, c1, r2, c2});
        }
    } else if (type == "target-prefix") {
        // 全正矩阵，且每次询问都有 r1>=2、c1>=2，
        // 漏加 +ps[r1-1][c1-1] 的容斥错误必定体现在答案里。
        n = 40;
        m = 40;
        q = 100;
        genUniform(1LL, 1000000000LL);
        for (int k = 0; k < q; ++k) {
            int r1 = rnd.next(2, n);
            int r2 = rnd.next(r1, n);
            int c1 = rnd.next(2, m);
            int c2 = rnd.next(c1, m);
            queries.push_back({r1, c1, r2, c2});
        }
    } else if (type == "target-colrange") {
        // 每次询问的列范围都不覆盖整行，
        // 只按行区间求和的实现必定出错。
        n = 40;
        m = 40;
        q = 100;
        genUniform(-1000000000LL, 1000000000LL);
        for (int k = 0; k < q; ++k) {
            int r1 = rnd.next(1, n);
            int r2 = rnd.next(r1, n);
            int c2 = rnd.next(1, m);
            int c1 = rnd.next(1, c2);
            while (c1 == 1 && c2 == m) {
                c2 = rnd.next(1, m);
                c1 = rnd.next(1, c2);
            }
            queries.push_back({r1, c1, r2, c2});
        }
    } else if (type == "random") {
        n = rnd.next(1, 100);
        m = rnd.next(1, 100);
        q = rnd.next(1, 1000);
        static const long long bounds[] = {1LL, 10LL, 1000LL, 1000000000LL};
        long long bound = bounds[rnd.next(0, 3)];
        int pattern = rnd.next(0, 2);
        if (pattern == 0) {
            genUniform(-bound, bound);
        } else if (pattern == 1) {
            genUniform(0LL, bound);
        } else {
            genUniform(-bound, 0LL);
        }
        addRandomQueries();
    } else if (type == "near-max") {
        // 满规模，但元素量级降到 1e8，答案约 1e12。
        n = 100;
        m = 100;
        q = 1000;
        genUniform(-100000000LL, 100000000LL);
        addRandomQueries();
    } else if (type == "max") {
        // 满规模满值域，答案可达 1e13，同时压时间上限。
        n = 100;
        m = 100;
        q = 1000;
        genUniform(-1000000000LL, 1000000000LL);
        addRandomQueries();
    } else if (type == "max-tiny") {
        // 满规模但元素只有 -1/0/1，答案很小，检验与数值范围无关的逻辑。
        n = 100;
        m = 100;
        q = 1000;
        genUniform(-1LL, 1LL);
        addRandomQueries();
    } else if (type == "max-mixed") {
        // 满规模，元素只取 ±1e9 与 0，答案在极端值附近摇摆。
        n = 100;
        m = 100;
        q = 1000;
        a.assign(n + 1, vector<long long>(m + 1, 0));
        static const long long pool[] = {1000000000LL, -1000000000LL, 0LL};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                a[i][j] = pool[rnd.next(0, 2)];
            }
        }
        addRandomQueries();
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    printCase();
    return 0;
}
