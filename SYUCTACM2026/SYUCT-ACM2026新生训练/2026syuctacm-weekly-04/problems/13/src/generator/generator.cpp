#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static const long long LIM = 1000000000LL;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    int n = 1;
    int m = 1;
    vector<vector<long long>> a;

    auto full_random = [&]() -> long long { return rnd.next(-LIM, LIM); };

    if (type == "sample") {
        cout << "4 4\n"
                "1 2 3 4\n"
                "-1 0 1 0\n"
                "1000000000 1000000000 1000000000 0\n"
                "-1000000000 -1000000000 -1000000000 -7\n";
        return 0;
    } else if (type == "min") {
        n = 1;
        m = 1;
        a.assign(n, vector<long long>(m, full_random()));
    } else if (type == "single-row") {
        n = 1;
        m = (seed % 3 == 0) ? 1000 : rnd.next(2, 1000);
        a.assign(n, vector<long long>(m));
        for (int j = 0; j < m; ++j) a[0][j] = full_random();
    } else if (type == "single-col") {
        m = 1;
        n = (seed % 3 == 0) ? 1000 : rnd.next(2, 1000);
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i) a[i][0] = full_random();
    } else if (type == "square") {
        n = rnd.next(1, 1000);
        m = n;
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = full_random();
    } else if (type == "zero") {
        n = rnd.next(1, 1000);
        m = rnd.next(1, 1000);
        a.assign(n, vector<long long>(m, 0));
    } else if (type == "all-same") {
        const long long v = (seed % 3 == 0) ? LIM : (seed % 3 == 1) ? -LIM : full_random();
        n = rnd.next(1, 1000);
        m = rnd.next(1, 1000);
        a.assign(n, vector<long long>(m, v));
    } else if (type == "boundary") {
        n = rnd.next(100, 1000);
        m = rnd.next(100, 1000);
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = (rnd.next(0, 2) - 1) * LIM;
    } else if (type == "overflow-pos") {
        n = rnd.next(2, 1000);
        m = (seed % 2 == 0) ? 1000 : rnd.next(100, 1000);
        a.assign(n, vector<long long>(m, LIM));
    } else if (type == "overflow-neg") {
        n = rnd.next(2, 1000);
        m = (seed % 2 == 0) ? 1000 : rnd.next(100, 1000);
        a.assign(n, vector<long long>(m, -LIM));
    } else if (type == "cancel") {
        n = rnd.next(2, 1000);
        m = rnd.next(2, 1000);
        a.assign(n, vector<long long>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < m; j += 2) {
                a[i][j] = LIM;
                a[i][j + 1] = -LIM;
            }
        }
        if (m % 2 == 1 && n >= 2 && seed % 2 == 0) {
            a[0][m - 1] = LIM;
            a[1][m - 1] = -LIM;
        }
    } else if (type == "colswap") {
        n = rnd.next(2, 1000);
        m = rnd.next(2, 1000);
        if (m == n) m = (m == 1000) ? 999 : m + 1;
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = full_random();
    } else if (type == "random-small") {
        n = rnd.next(1, 8);
        m = rnd.next(1, 8);
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = full_random();
    } else if (type == "random") {
        n = rnd.next(1, 1000);
        m = rnd.next(1, 1000);
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = full_random();
    } else if (type == "max") {
        n = 1000;
        m = 1000;
        a.assign(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) a[i][j] = full_random();
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
