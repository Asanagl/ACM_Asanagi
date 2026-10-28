#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

enum class Fill {
    Random,
    Zero,
    ConstPos,
    ConstNeg,
    Cancel,
    Pool,
    MixedSign,
    Directed,
    DirectedTransposed
};

struct Spec {
    int n;
    int m;
    Fill fill;
};

static const int kMin = -1000000;
static const int kMax = 1000000;

static Spec specFor(const string& type) {
    if (type == "min") return {1, 1, Fill::Random};
    if (type == "sample") return {2, 3, Fill::Directed};
    if (type == "row") return {1, 300, Fill::Random};
    if (type == "col") return {300, 1, Fill::Random};
    if (type == "thin-wide") return {2, 300, Fill::Random};
    if (type == "thin-tall") return {300, 2, Fill::MixedSign};
    if (type == "rect-small") return {2, 3, Fill::Directed};
    if (type == "rect-small-t") return {3, 2, Fill::DirectedTransposed};
    if (type == "square-small") return {3, 3, Fill::Directed};
    if (type == "zero") return {4, 5, Fill::Zero};
    if (type == "const-pos") return {6, 7, Fill::ConstPos};
    if (type == "const-neg") return {6, 7, Fill::ConstNeg};
    if (type == "cancel") return {5, 6, Fill::Cancel};
    if (type == "dup-pool") return {8, 9, Fill::Pool};
    if (type == "dup-const") return {12, 10, Fill::Pool};
    if (type == "mixed-sign") return {100, 101, Fill::MixedSign};
    if (type == "directed") return {3, 4, Fill::Directed};
    if (type == "directed-t") return {4, 3, Fill::DirectedTransposed};
    if (type == "small-random") return {3, 4, Fill::Random};
    if (type == "random") return {0, 0, Fill::Random};
    if (type == "near-max-wide") return {299, 300, Fill::Random};
    if (type == "near-max-tall") return {300, 297, Fill::Random};
    if (type == "near-max-both") return {299, 299, Fill::MixedSign};
    if (type == "max-pos") return {300, 300, Fill::ConstPos};
    if (type == "max-neg") return {300, 300, Fill::ConstNeg};
    if (type == "max-random") return {300, 300, Fill::Random};
    if (type == "max-mixed") return {300, 300, Fill::MixedSign};
    if (type == "square-max") return {300, 300, Fill::Directed};
    return {-1, -1, Fill::Random};
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    rnd.setSeed(atoll(argv[2]));

    Spec spec = specFor(type);
    if (spec.n < 0) {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    int n = spec.n;
    int m = spec.m;
    if (type == "random") {
        n = rnd.next(1, 300);
        m = rnd.next(1, 300);
    }
    if (type == "small-random") {
        n = rnd.next(1, 8);
        m = rnd.next(1, 8);
    }

    static const int pool[] = {-1000000, -1000, 0, 1000, 1000000};
    const int offset = rnd.next(0, 500);

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            switch (spec.fill) {
                case Fill::Zero:
                    a[i][j] = 0;
                    b[i][j] = 0;
                    break;
                case Fill::ConstPos:
                    a[i][j] = kMax;
                    b[i][j] = kMax;
                    break;
                case Fill::ConstNeg:
                    a[i][j] = kMin;
                    b[i][j] = kMin;
                    break;
                case Fill::Cancel:
                    a[i][j] = rnd.next(kMin, kMax);
                    b[i][j] = -a[i][j];
                    break;
                case Fill::Pool:
                    a[i][j] = pool[rnd.next(0, 4)];
                    b[i][j] = pool[rnd.next(0, 4)];
                    break;
                case Fill::MixedSign:
                    a[i][j] = (rnd.next(0, 1) == 0) ? kMax : kMin;
                    b[i][j] = (rnd.next(0, 1) == 0) ? kMax : kMin;
                    break;
                case Fill::Directed:
                    a[i][j] = offset + 101 + 7 * i + 3 * j;
                    b[i][j] = offset + 907 + 11 * i + 5 * j;
                    break;
                case Fill::DirectedTransposed:
                    a[i][j] = offset + 211 + 13 * j + 2 * i;
                    b[i][j] = offset + 811 + 17 * j + 19 * i;
                    break;
                case Fill::Random:
                default:
                    a[i][j] = rnd.next(kMin, kMax);
                    b[i][j] = rnd.next(kMin, kMax);
                    break;
            }
        }
    }

    if (type == "sample") {
        a = {{1, -2, 3}, {4, 5, -6}};
        b = {{-1, 2, -3}, {7, -8, 9}};
        n = 2;
        m = 3;
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) cout << ' ';
            cout << b[i][j];
        }
        cout << '\n';
    }
    return 0;
}
