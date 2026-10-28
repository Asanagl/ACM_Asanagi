#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

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
    string fill = "unique";
    long long repeatedValue = 0;

    if (type == "sample") {
        n = 2;
        m = 3;
        fill = "sample";
    } else if (type == "sample2") {
        n = 3;
        m = 1;
        fill = "sample2";
    } else if (type == "min") {
        n = m = 1;
        fill = "zero";
    } else if (type == "min-limit") {
        n = m = 1;
        fill = "negative-limit";
    } else if (type == "single-row") {
        n = 1;
        m = 2 + static_cast<int>(seed % 7);
    } else if (type == "single-row-max") {
        n = 1;
        m = 100;
    } else if (type == "single-col") {
        n = 2 + static_cast<int>(seed % 7);
        m = 1;
    } else if (type == "single-col-max") {
        n = 100;
        m = 1;
    } else if (type == "square-small") {
        n = m = 2;
    } else if (type == "square") {
        n = m = 3 + static_cast<int>(seed % 8);
    } else if (type == "wide") {
        n = 2 + static_cast<int>(seed % 3);
        m = 5 + static_cast<int>(seed % 6);
    } else if (type == "tall") {
        n = 5 + static_cast<int>(seed % 6);
        m = 2 + static_cast<int>(seed % 3);
    } else if (type == "repeat-all") {
        n = 2 + static_cast<int>(seed % 20);
        m = 2 + static_cast<int>((seed / 3) % 20);
        fill = "repeat";
        repeatedValue = (seed % 2 == 0 ? -7 : 7);
    } else if (type == "repeat-pattern") {
        n = 4 + static_cast<int>(seed % 10);
        m = 3 + static_cast<int>(seed % 11);
        fill = "pattern";
    } else if (type == "limits") {
        n = 3 + static_cast<int>(seed % 5);
        m = 4 + static_cast<int>(seed % 5);
        fill = "limits";
    } else if (type == "directed-original") {
        n = 3;
        m = 2;
    } else if (type == "directed-reshape") {
        n = 2;
        m = 4;
    } else if (type == "directed-drop-last") {
        n = 4;
        m = 3;
    } else if (type == "directed-double-swap") {
        n = m = 3 + static_cast<int>(seed % 3);
    } else if (type == "random-small") {
        n = rnd.next(1, 8);
        m = rnd.next(1, 8);
        fill = "random";
    } else if (type == "random") {
        n = rnd.next(1, 100);
        m = rnd.next(1, 100);
        fill = "random";
    } else if (type == "near-max-wide") {
        n = 99;
        m = 100;
        fill = "random";
    } else if (type == "near-max-tall") {
        n = 100;
        m = 99;
        fill = "random";
    } else if (type == "max-random") {
        n = m = 100;
        fill = "random";
    } else if (type == "max-structured") {
        n = m = 100;
        fill = "structured";
    } else if (type == "max-repeat") {
        n = m = 100;
        fill = "repeat";
        repeatedValue = 1000000000LL;
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    vector<long long> a(static_cast<size_t>(n) * m, 0);
    const long long pattern[] = {-1, 0, 1, 7, 7, -5};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            const int k = i * m + j;
            if (fill == "unique") {
                a[k] = k + 1;
            } else if (fill == "random") {
                a[k] = rnd.next(-1000000000LL, 1000000000LL);
            } else if (fill == "repeat") {
                a[k] = repeatedValue;
            } else if (fill == "pattern") {
                a[k] = pattern[(i * 3 + j) % 6];
            } else if (fill == "limits") {
                const int selector = (i + j) % 4;
                a[k] = selector == 0 ? -1000000000LL
                     : selector == 1 ? 1000000000LL
                     : selector == 2 ? 0 : (i * 100LL + j);
            } else if (fill == "structured") {
                a[k] = (i * 1000003LL + j * 999983LL) % 2000000001LL - 1000000000LL;
            } else if (fill == "negative-limit") {
                a[k] = -1000000000LL;
            }
        }
    }

    if (fill == "sample") {
        a = {1, -2, 1, 3, 1000000000LL, -1000000000LL};
    } else if (fill == "sample2") {
        a = {5, -7, 0};
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << a[i * m + j];
        }
        cout << '\n';
    }
    return 0;
}
