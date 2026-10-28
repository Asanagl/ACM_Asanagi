#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static const long long LIM = 1000000000LL;

// 用 fill 回调生成一个 n x n 方阵，再按题面格式输出
template <typename F>
static void emit(int n, F fill) {
    vector<vector<long long>> a(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = fill(i, j);
        }
    }
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
}

static long long randValue() {
    return rnd.next(-LIM, LIM);
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
        // 与题面样例逐字节一致；由主解生成答案
        if (seed == 1) {
            emit(3, [](int i, int j) -> long long {
                static const long long v[3][3] = {
                    {1, -2, 3},
                    {4, 5, 6},
                    {7, 8, -9},
                };
                return v[i][j];
            });
        } else if (seed == 2) {
            emit(2, [](int i, int j) -> long long {
                static const long long v[2][2] = {
                    {-1, 2},
                    {3, 4},
                };
                return v[i][j];
            });
        } else {
            emit(1, [](int, int) -> long long { return -LIM; });
        }
    } else if (type == "min") {
        // 最小规模 n = 1：唯一元素同时属于两条对角线
        const long long v = (seed % 3 == 0) ? -LIM : ((seed % 3 == 1) ? 0LL : LIM);
        emit(1, [v](int, int) -> long long { return v; });
    } else if (type == "two") {
        // 最小非平凡规模 n = 2：两条对角线无公共元素
        emit(2, [](int, int) -> long long { return randValue(); });
    } else if (type == "odd-center") {
        // 奇数阶且中心元素非零：中心必须被两条对角线各算一次
        const int n = 3 + int(seed % 5) * 2;  // 3,5,7,9,11
        const long long center = (seed % 2 == 0) ? LIM : -LIM;
        emit(n, [n, center](int i, int j) -> long long {
            if (i == n / 2 && j == n / 2) {
                return center;
            }
            return randValue();
        });
    } else if (type == "even") {
        // 偶数阶：两条对角线没有公共元素
        const int n = 4 + int(seed % 4) * 2;  // 4,6,8,10
        emit(n, [](int, int) -> long long { return randValue(); });
    } else if (type == "same") {
        // 全部元素相同：两个答案恰好相等且都等于 n * v
        const int n = 3 + int(seed % 8);
        const long long v = randValue();
        emit(n, [v](int, int) -> long long { return v; });
    } else if (type == "all-negative") {
        // 全部为负数：答案均为负，考察负号处理
        const int n = 5 + int(seed % 9);
        emit(n, [](int, int) -> long long { return rnd.next(-LIM, -1LL); });
    } else if (type == "zero") {
        // 全部为零：两个答案都必须是 0
        const int n = 6 + int(seed % 10);
        emit(n, [](int, int) -> long long { return 0; });
    } else if (type == "diag-only") {
        // 只有主对角线非零，副对角线全 0：两个答案差别最大
        const int n = 5 + int(seed % 7);
        emit(n, [](int i, int j) -> long long {
            return (i == j) ? rnd.next(1LL, LIM) : 0LL;
        });
    } else if (type == "anti-only") {
        // 只有副对角线非零，主对角线全 0（奇数阶时中心被覆盖为主对角线值）
        const int n = 5 + int(seed % 7);
        emit(n, [n](int i, int j) -> long long {
            if (i + j + 1 == n) {
                return rnd.next(-LIM, -1LL);
            }
            return 0LL;
        });
    } else if (type == "center-zero") {
        // 奇数阶且中心为 0：故意让"去重/漏算中心"的错解在这一类上不暴露，
        // 保证击杀必须依赖其它中心非零的点，而不是偶然
        const int n = 3 + int(seed % 5) * 2;
        emit(n, [n](int i, int j) -> long long {
            if (i == n / 2 && j == n / 2) {
                return 0;
            }
            return randValue();
        });
    } else if (type == "directed-dedup") {
        // 定向：奇数阶、中心取极值，专杀"两条对角线合计后减去中心"的去重错解
        const int n = 3 + int(seed % 3) * 2;  // 3,5,7
        emit(n, [n](int i, int j) -> long long {
            if (i == n / 2 && j == n / 2) {
                return LIM;
            }
            if (i == j || i + j + 1 == n) {
                return rnd.next(-1000LL, 1000LL);
            }
            return 0;
        });
    } else if (type == "directed-swap") {
        // 定向：强制主对角线之和与副对角线之和一正一负，专杀输出顺序颠倒
        const int n = 4 + int(seed % 4);
        emit(n, [n](int i, int j) -> long long {
            if (i == j) {
                return rnd.next(1LL, LIM);
            }
            if (i + j + 1 == n) {
                return rnd.next(-LIM, -1LL);
            }
            return 0;
        });
    } else if (type == "directed-off-by-one") {
        // 定向：行内元素随列号严格递增，专杀副对角线列号偏一位的下标错解
        const int n = 3 + int(seed % 3);  // 3,4,5
        emit(n, [](int i, int j) -> long long {
            return (long long)i * 1000 + j + 1;
        });
    } else if (type == "directed-overflow") {
        // 定向：满规模且全部取 1e9 / -1e9，答案达 2e14，专杀 32 位求和
        const int n = 200;
        const long long v = (seed % 2 == 0) ? LIM : -LIM;
        emit(n, [v](int, int) -> long long { return v; });
    } else if (type == "random") {
        // 随机：阶数在 [1, 200] 内随机，元素全范围随机
        const int n = rnd.next(1, 200);
        emit(n, [](int, int) -> long long { return randValue(); });
    } else if (type == "mid") {
        // 中等规模
        emit(100, [](int, int) -> long long { return randValue(); });
    } else if (type == "near-max") {
        // 近上限：199 或 200
        const int n = (seed % 2 == 0) ? 199 : 200;
        emit(n, [](int, int) -> long long { return randValue(); });
    } else if (type == "max") {
        // 上限规模：全部元素取边界值
        const long long v = (seed % 2 == 0) ? -LIM : LIM;
        emit(200, [v](int, int) -> long long { return v; });
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    return 0;
}
