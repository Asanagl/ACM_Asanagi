#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static void emit(int n, int m, const vector<vector<int>>& a) {
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
}

static vector<vector<int>> makeMatrix(int n, int m, int lo, int hi) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rnd.next(lo, hi);
        }
    }
    return a;
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

    const int V = 10000000;

    if (type == "sample") {
        if (seed == 2) {
            emit(1, 1, {{-7}});
        } else {
            emit(3, 4, {{1, 2, 3, 4}, {5, 6, 7, 8}, {-1, -2, -3, -4}});
        }
    } else if (type == "zero-sum") {
        emit(5, 5, {{10, 2, 3, 4, 1},
                    {6, 100, 100, 100, -16},
                    {7, 100, 100, 100, 0},
                    {8, 100, 100, 100, 0},
                    {-3, -4, -5, -6, -7}});
    } else if (type == "min") {
        emit(1, 1, {{7}});
    } else if (type == "min-neg") {
        emit(1, 1, {{-5}});
    } else if (type == "one-row") {
        int m = rnd.next(8, 20);
        emit(1, m, makeMatrix(1, m, -50, 50));
    } else if (type == "one-row-neg") {
        int m = rnd.next(8, 20);
        emit(1, m, makeMatrix(1, m, -50, -1));
    } else if (type == "one-col") {
        int n = rnd.next(8, 20);
        emit(n, 1, makeMatrix(n, 1, -50, 50));
    } else if (type == "one-col-neg") {
        int n = rnd.next(8, 20);
        emit(n, 1, makeMatrix(n, 1, -50, -1));
    } else if (type == "two-two") {
        emit(2, 2, makeMatrix(2, 2, -100, 100));
    } else if (type == "two-row") {
        int m = rnd.next(5, 15);
        emit(2, m, makeMatrix(2, m, -100, 100));
    } else if (type == "two-col") {
        int n = rnd.next(5, 15);
        emit(n, 2, makeMatrix(n, 2, -100, 100));
    } else if (type == "all-same") {
        int n = rnd.next(10, 30);
        emit(n, n, vector<vector<int>>(n, vector<int>(n, 3)));
    } else if (type == "all-same-neg") {
        int n = rnd.next(10, 30);
        emit(n, n, vector<vector<int>>(n, vector<int>(n, -7)));
    } else if (type == "hollow") {
        int n = rnd.next(10, 30);
        auto a = makeMatrix(n, n, 0, 0);
        long long innerSum = 0;
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < n; j++) {
                a[i][j] = rnd.next(-99, 99);
                innerSum += a[i][j];
            }
        }
        if (innerSum == 0) {
            a[1][1] = 1;
        }
        emit(n, n, a);
    } else if (type == "pattern") {
        vector<vector<int>> a(12, vector<int>(16));
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 16; j++) {
                a[i][j] = ((i + j) % 2 == 0) ? 5 : -5;
            }
        }
        emit(12, 16, a);
    } else if (type == "corner-neg") {
        emit(4, 4, {{-100, 100, 100, -100},
                    {100, 100, 100, 100},
                    {100, 100, 100, 100},
                    {-100, 100, 100, -100}});
    } else if (type == "mixed-signs") {
        emit(50, 60, makeMatrix(50, 60, -1000, 1000));
    } else if (type == "random") {
        int n = rnd.next(2, 60);
        int m = rnd.next(2, 60);
        emit(n, m, makeMatrix(n, m, -1000, 1000));
    } else if (type == "wide") {
        emit(1, 500, makeMatrix(1, 500, -V, V));
    } else if (type == "tall") {
        emit(500, 1, makeMatrix(500, 1, -V, V));
    } else if (type == "big-positive") {
        emit(500, 500, vector<vector<int>>(500, vector<int>(500, V)));
    } else if (type == "big-negative") {
        emit(500, 500, vector<vector<int>>(500, vector<int>(500, -V)));
    } else if (type == "big-random") {
        int n = rnd.next(300, 500);
        int m = rnd.next(300, 500);
        emit(n, m, makeMatrix(n, m, -V, V));
    } else if (type == "near-max") {
        emit(500, 500, makeMatrix(500, 500, -V, V));
    } else if (type == "int-edge") {
        vector<vector<int>> a(500, vector<int>(500, -V));
        for (int j = 0; j < 500; j++) {
            a[0][j] = V;
            a[499][j] = V;
        }
        for (int i = 0; i < 500; i++) {
            a[i][0] = V;
            a[i][499] = V;
        }
        emit(500, 500, a);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    return 0;
}
