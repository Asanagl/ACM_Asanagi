#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix makeMatrix(int n, int m) {
    return Matrix(n, vector<int>(m));
}

void fillRandom(Matrix& a, int lo, int hi) {
    for (auto& row : a) {
        for (int& value : row) {
            value = rnd.next(lo, hi);
        }
    }
}

void printMatrix(const Matrix& a) {
    const int n = static_cast<int>(a.size());
    const int m = static_cast<int>(a[0].size());
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
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

    Matrix a;
    if (type == "sample") {
        if (seed == 1) {
            a = {{0, -7, 1000, 0}, {5, 5, -1000, 9}, {-1, 0, 8, 8}};
        } else if (seed == 2) {
            a = {{7, -3, 0, 42, -56}};
        } else if (seed == 3) {
            a = {{3}, {-2}, {3}, {0}};
        }
    } else if (type == "min-zero") {
        a = {{0}};
    } else if (type == "min-positive") {
        a = {{1000}};
    } else if (type == "min-negative") {
        a = {{-1000}};
    } else if (type == "single-row-two") {
        a = {{1, -1}};
    } else if (type == "single-col-two") {
        a = {{2}, {-2}};
    } else if (type == "single-row-max") {
        a = makeMatrix(1, 100);
        for (int j = 0; j < 100; ++j) {
            a[0][j] = (j % 2 == 0 ? 1000 - j : -1000 + j);
        }
    } else if (type == "single-col-max") {
        a = makeMatrix(100, 1);
        for (int i = 0; i < 100; ++i) {
            a[i][0] = (i % 2 == 0 ? -1000 + i : 1000 - i);
        }
    } else if (type == "rectangular-wide") {
        a = makeMatrix(2, 7);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 7; ++j) {
                a[i][j] = (i == 0 ? 1 : -1) * (j * j + 1);
            }
        }
    } else if (type == "rectangular-tall") {
        a = makeMatrix(7, 2);
        for (int i = 0; i < 7; ++i) {
            a[i][0] = i - 3;
            a[i][1] = 3 - i;
        }
    } else if (type == "square-non-symmetric") {
        a = makeMatrix(5, 5);
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                a[i][j] = i * 5 + j - 12;
            }
        }
    } else if (type == "all-zero-small") {
        a = makeMatrix(6, 9);
    } else if (type == "all-zero-max") {
        a = makeMatrix(100, 100);
    } else if (type == "all-same-positive") {
        a = makeMatrix(18, 17);
        for (auto& row : a) {
            fill(row.begin(), row.end(), 123);
        }
    } else if (type == "all-same-negative") {
        a = makeMatrix(19, 4);
        for (auto& row : a) {
            fill(row.begin(), row.end(), -123);
        }
    } else if (type == "repeated-pattern") {
        a = makeMatrix(37, 41);
        for (int i = 0; i < 37; ++i) {
            for (int j = 0; j < 41; ++j) {
                a[i][j] = (i * 3 + j) % 5 - 2;
            }
        }
    } else if (type == "alternating-extrema") {
        a = makeMatrix(40, 41);
        for (int i = 0; i < 40; ++i) {
            for (int j = 0; j < 41; ++j) {
                a[i][j] = (i + j) % 2 == 0 ? 1000 : -1000;
            }
        }
    } else if (type == "boundary-mix") {
        const int values[] = {-1000, 1000, 0, -1, 1};
        a = makeMatrix(17, 19);
        for (int i = 0; i < 17; ++i) {
            for (int j = 0; j < 19; ++j) {
                a[i][j] = values[(i * 2 + j) % 5];
            }
        }
    } else if (type == "increasing") {
        a = makeMatrix(20, 30);
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 30; ++j) {
                a[i][j] = i * 30 + j - 300;
            }
        }
    } else if (type == "decreasing") {
        a = makeMatrix(20, 30);
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 30; ++j) {
                a[i][j] = 300 - i * 30 - j;
            }
        }
    } else if (type == "directed-transpose") {
        a = makeMatrix(3, 5);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                a[i][j] = i * 5 + j + 1;
            }
        }
    } else if (type == "directed-abs") {
        a = makeMatrix(4, 6);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 6; ++j) {
                const int value = i * 6 + j + 1;
                a[i][j] = (i + j) % 3 == 0 ? -value : value;
            }
        }
    } else if (type == "directed-last-column") {
        a = makeMatrix(5, 4);
        for (int i = 0; i < 5; ++i) {
            a[i][3] = (i + 1) * 100;
        }
    } else if (type == "directed-last-row") {
        a = makeMatrix(5, 4);
        for (int j = 0; j < 4; ++j) {
            a[4][j] = -1000 + j;
        }
    } else {
        int n = 0;
        int m = 0;
        if (type == "single-row-random") {
            n = 1;
            m = rnd.next(2, 100);
        } else if (type == "single-col-random") {
            n = rnd.next(2, 100);
            m = 1;
        } else if (type == "random-small") {
            n = rnd.next(2, 10);
            m = rnd.next(2, 10);
        } else if (type == "random-medium") {
            n = rnd.next(10, 60);
            m = rnd.next(10, 60);
        } else if (type == "random-large") {
            n = rnd.next(50, 100);
            m = rnd.next(50, 100);
        } else if (type == "near-max-rows") {
            n = 99;
            m = 100;
        } else if (type == "near-max-cols") {
            n = 100;
            m = 99;
        } else if (type == "max-random") {
            n = 100;
            m = 100;
        } else if (type == "stress") {
            n = rnd.next(1, 8);
            m = rnd.next(1, 8);
        }

        if (n > 0) {
            a = makeMatrix(n, m);
            fillRandom(a, -1000, 1000);
        }
    }

    if (a.empty()) {
        cerr << "Unknown case type or seed: " << type << ' ' << seed << '\n';
        return 2;
    }
    printMatrix(a);
    return 0;
}
