#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;
using Matrix = vector<vector<int>>;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    auto constantMatrix = [](int n, int m, int value) {
        return Matrix(n, vector<int>(m, value));
    };
    auto randomMatrix = [](int n, int m) {
        Matrix a(n, vector<int>(m));
        for (auto& row : a) {
            for (int& value : row) {
                value = rnd.next(-1000, 1000);
            }
        }
        return a;
    };
    auto formulaMatrix = [](int n, int m, int multiplier) {
        Matrix a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = (i * 101 + j * multiplier) % 2001 - 1000;
            }
        }
        return a;
    };

    Matrix a;
    if (type == "sample-even") {
        a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    } else if (type == "sample-odd") {
        a = {{7, -1, 8}, {0, 0, 5}};
    } else if (type == "sample-single") {
        a = {{4}, {-2}, {9}};
    } else if (type == "min-single") {
        a = {{-1000}};
    } else if (type == "min-row") {
        a = {{-1000, 1000}};
    } else if (type == "single-column") {
        a = Matrix(100, vector<int>(1));
        for (int i = 0; i < 100; ++i) {
            a[i][0] = i % 2 == 0 ? -1000 : 1000;
        }
    } else if (type == "single-row") {
        a = Matrix(1, vector<int>(100));
        for (int j = 0; j < 100; ++j) {
            a[0][j] = j - 50;
        }
    } else if (type == "odd-min") {
        a = {{7, -1, 8}};
    } else if (type == "even-min") {
        a = {{1000, -1000}};
    } else if (type == "all-equal") {
        a = constantMatrix(7, 9, 7);
    } else if (type == "repeated") {
        a = Matrix(6, vector<int>(7));
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                a[i][j] = (i + j) % 3 - 1;
            }
        }
    } else if (type == "palindrome-rows") {
        a = randomMatrix(4, 7);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                a[i][6 - j] = a[i][j];
            }
        }
    } else if (type == "value-boundary" || type == "max-value-boundary") {
        const int n = type == "value-boundary" ? 5 : 100;
        const int m = type == "value-boundary" ? 5 : 100;
        const int values[] = {-1000, 1000, 0, -1, 1};
        a = Matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = values[(i + j) % 5];
            }
        }
    } else if (type == "ascending" || type == "descending") {
        const int n = 4;
        const int m = 10;
        a = Matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const int value = i * m + j;
                a[i][j] = type == "ascending" ? value : 1000 - value;
            }
        }
    } else if (type == "directed-global") {
        a = {{1, 2, 2, 1}, {3, 4, 4, 3}, {5, 6, 6, 5}};
    } else if (type == "directed-row-order") {
        a = formulaMatrix(4, 3, 1);
    } else if (type == "directed-double-swap") {
        a = {{1, 2, 3, 4, 5}, {5, 5, 0, -1, 9}};
    } else if (type == "directed-odd") {
        a = formulaMatrix(3, 5, 2);
    } else if (type == "directed-even") {
        a = formulaMatrix(3, 6, 3);
    } else if (type == "alternating") {
        a = Matrix(8, vector<int>(9));
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 9; ++j) {
                a[i][j] = (i + j) % 2 == 0 ? -1000 : 1000;
            }
        }
    } else if (type == "rectangular-wide") {
        a = randomMatrix(5, 100);
    } else if (type == "rectangular-tall") {
        a = randomMatrix(100, 5);
    } else if (type == "near-max-odd") {
        a = formulaMatrix(100, 99, 7);
    } else if (type == "near-max-even") {
        a = formulaMatrix(99, 100, 11);
    } else if (type == "max-all-equal") {
        a = constantMatrix(100, 100, -1000);
    } else if (type == "max-pattern") {
        a = formulaMatrix(100, 100, 17);
    } else if (type == "random-small") {
        a = randomMatrix(rnd.next(1, 8), rnd.next(1, 8));
    } else if (type == "random-odd") {
        a = randomMatrix(rnd.next(1, 30), 2 * rnd.next(0, 49) + 1);
    } else if (type == "random-even") {
        a = randomMatrix(rnd.next(1, 30), 2 * rnd.next(1, 50));
    } else if (type == "random-wide") {
        a = randomMatrix(rnd.next(1, 10), rnd.next(50, 100));
    } else if (type == "random-tall") {
        a = randomMatrix(rnd.next(50, 100), rnd.next(1, 10));
    } else if (type == "random-medium") {
        a = randomMatrix(rnd.next(10, 60), rnd.next(10, 60));
    } else if (type == "random-large") {
        a = randomMatrix(rnd.next(70, 100), rnd.next(70, 100));
    } else if (type == "random-values") {
        const int values[] = {-1000, -1, 0, 1, 1000};
        a = Matrix(50, vector<int>(50));
        for (auto& row : a) {
            for (int& value : row) {
                value = values[rnd.next(0, 4)];
            }
        }
    } else if (type == "near-max-random") {
        a = randomMatrix(100, 99);
    } else if (type == "max-random") {
        a = randomMatrix(100, 100);
    } else if (type == "stress-small") {
        int n = rnd.next(1, 8);
        int m = rnd.next(1, 8);
        if (seed % 8 == 0) {
            n = 1;
            m = 1;
        } else if (seed % 8 == 1) {
            m = 1;
        } else if (seed % 8 == 2) {
            n = 1;
        } else if (seed % 8 == 3) {
            m = 3;
        } else if (seed % 8 == 4) {
            m = 4;
        }
        a = randomMatrix(n, m);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << a.size() << ' ' << a[0].size() << '\n';
    for (const auto& row : a) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (j != 0) {
                cout << ' ';
            }
            cout << row[j];
        }
        cout << '\n';
    }
    return 0;
}
