#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix sequential(int n, int m) {
    Matrix a(n, vector<int>(m));
    int value = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = value++;
        }
    }
    return a;
}

Matrix constant(int n, int m, int value) {
    return Matrix(n, vector<int>(m, value));
}

Matrix randomMatrix(int n, int m, int low = -1000000000, int high = 1000000000) {
    Matrix a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rnd.next(low, high);
        }
    }
    return a;
}

void printMatrix(const Matrix& a) {
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(a[0].size());
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

    string type = argv[1];
    long long seed = atoll(argv[2]);
    rnd.setSeed(seed);
    Matrix a;

    if (type == "sample") {
        a = sequential(2, 3);
    } else if (type == "sample-tall") {
        a = {{1, -2}, {3, 4}, {-5, 6}};
    } else if (type == "min-zero") {
        a = constant(1, 1, 0);
    } else if (type == "min-value") {
        a = constant(1, 1, -1000000000);
    } else if (type == "single-row") {
        a = sequential(1, 2 + static_cast<int>(seed % 8));
    } else if (type == "single-row-max") {
        a = Matrix(1, vector<int>(500));
        for (int j = 0; j < 500; ++j) {
            a[0][j] = (j % 2 == 0 ? 1000000000 : -1000000000);
        }
    } else if (type == "single-col") {
        a = sequential(2 + static_cast<int>(seed % 8), 1);
    } else if (type == "single-col-max") {
        a = Matrix(500, vector<int>(1));
        for (int i = 0; i < 500; ++i) {
            a[i][0] = (i % 2 == 0 ? i + 1 : -(i + 1)) * 1000;
        }
    } else if (type == "square-2") {
        a = sequential(2, 2);
    } else if (type == "square-5") {
        a = sequential(5, 5);
    } else if (type == "wide-unique") {
        int n = 2 + static_cast<int>(seed % 4);
        int m = n + 1 + static_cast<int>(seed % 5);
        a = sequential(n, m);
    } else if (type == "tall-unique") {
        int m = 2 + static_cast<int>(seed % 4);
        int n = m + 1 + static_cast<int>(seed % 5);
        a = sequential(n, m);
    } else if (type == "wide-pattern") {
        a = Matrix(4, vector<int>(7));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 7; ++j) {
                a[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else if (type == "tall-pattern") {
        a = Matrix(7, vector<int>(4));
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 4; ++j) {
                a[i][j] = (i + 1) * 10 - j - 1;
            }
        }
    } else if (type == "all-same-zero") {
        a = constant(2, 7, 0);
    } else if (type == "all-same-pos") {
        a = constant(3, 5, 1000000000);
    } else if (type == "all-same-neg") {
        a = constant(4, 3, -1000000000);
    } else if (type == "repeat-wide") {
        a = Matrix(5, vector<int>(8));
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 8; ++j) {
                a[i][j] = (i + j) % 3 - 1;
            }
        }
    } else if (type == "repeat-tall") {
        a = Matrix(8, vector<int>(5));
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 5; ++j) {
                a[i][j] = (2 * i + j) % 4 - 2;
            }
        }
    } else if (type == "boundary-wide" || type == "boundary-tall") {
        const int values[] = {-1000000000, 1000000000, 0, -1, 1, 1000000000, -1000000000, 7, 0, -7, 1, -1};
        int n = type == "boundary-wide" ? 3 : 4;
        int m = type == "boundary-wide" ? 4 : 3;
        a = Matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = values[(i * m + j + static_cast<int>(seed)) % 12];
            }
        }
    } else if (type == "direction-wide") {
        a = Matrix(2, vector<int>(5));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                a[i][j] = (i + 1) * 100 + (j + 1) * 3;
            }
        }
    } else if (type == "direction-tall") {
        a = Matrix(5, vector<int>(2));
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 2; ++j) {
                a[i][j] = (i + 1) * 7 - (j + 1) * 100;
            }
        }
    } else if (type == "random-small") {
        a = randomMatrix(rnd.next(1, 10), rnd.next(1, 10), -50, 50);
    } else if (type == "random") {
        a = randomMatrix(rnd.next(1, 80), rnd.next(1, 80));
    } else if (type == "random-wide") {
        int n = rnd.next(2, 50);
        a = randomMatrix(n, rnd.next(n + 1, 120));
    } else if (type == "random-tall") {
        int m = rnd.next(2, 50);
        a = randomMatrix(rnd.next(m + 1, 120), m);
    } else if (type == "wide-limit") {
        a = sequential(3, 500);
    } else if (type == "tall-limit") {
        a = sequential(500, 3);
    } else if (type == "near-max-wide") {
        a = randomMatrix(499, 500);
    } else if (type == "near-max-tall") {
        a = randomMatrix(500, 499);
    } else if (type == "max-square") {
        a = sequential(500, 500);
    } else if (type == "max-values") {
        a = Matrix(500, vector<int>(500));
        for (int i = 0; i < 500; ++i) {
            for (int j = 0; j < 500; ++j) {
                a[i][j] = ((i + j) % 2 == 0 ? 1000000000 : -1000000000);
            }
        }
    } else if (type == "stress") {
        int n, m;
        if (seed % 12 == 0) {
            n = 1;
            m = rnd.next(1, 8);
        } else if (seed % 12 == 1) {
            n = rnd.next(1, 8);
            m = 1;
        } else {
            n = rnd.next(1, 8);
            m = rnd.next(1, 8);
        }
        a = randomMatrix(n, m, -100, 100);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    printMatrix(a);
    return 0;
}
