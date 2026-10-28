#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    string type = argv[1];
    long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    int n = 1, m = 1;
    vector<int> a;
    auto fillRandom = [&](long long lo, long long hi) {
        a.resize(n * m);
        for (int& x : a) {
            x = static_cast<int>(rnd.next(lo, hi));
        }
    };

    if (type == "sample") {
        n = 3, m = 4;
        a = {1, -2, 3, 4, -5, 0, 5, 10, 7, 8, -9, -1};
    } else if (type == "sample-min") {
        a = {-7};
    } else if (type == "sample-overflow") {
        n = 3, m = 2;
        a = {1000000000, 1, 1000000000, -1, 1000000000, 0};
    } else if (type == "min-zero") {
        a = {0};
    } else if (type == "min-negative") {
        a = {-1000000000};
    } else if (type == "min-positive") {
        a = {1000000000};
    } else if (type == "one-row") {
        n = 1, m = rnd.next(2, 20);
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "one-column") {
        n = rnd.next(2, 20), m = 1;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "wide") {
        n = 2, m = 9;
        a = {1, 2, 3, 4, 5, 6, 7, 8, 9, -9, -8, -7, -6, -5, -4, -3, -2, -1};
    } else if (type == "tall") {
        n = 9, m = 2;
        a = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9};
    } else if (type == "negative") {
        n = rnd.next(2, 12), m = rnd.next(2, 12);
        a.resize(n * m);
        for (int& x : a) {
            x = -static_cast<int>(rnd.next(1LL, 1000000000LL));
        }
    } else if (type == "repeated") {
        n = rnd.next(2, 12), m = rnd.next(2, 12);
        fillRandom(-2, 2);
    } else if (type == "zeros") {
        n = 5, m = 8;
        a.assign(n * m, 0);
    } else if (type == "alternating") {
        n = 6, m = 7;
        a.resize(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i * m + j] = (i + j) % 2 == 0 ? 1 : -1;
            }
        }
    } else if (type == "directed-rows") {
        n = 3, m = 3;
        a = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    } else if (type == "directed-loop") {
        n = 2, m = 5;
        a = {1, 2, 3, 4, 5, 10, 20, 30, 40, 50};
    } else if (type == "overflow-positive") {
        n = 1000, m = 4;
        a.assign(n * m, 1000000000);
    } else if (type == "overflow-negative") {
        n = 1000, m = 4;
        a.assign(n * m, -1000000000);
    } else if (type == "random-small") {
        n = rnd.next(1, 12), m = rnd.next(1, 12);
        fillRandom(-100, 100);
    } else if (type == "random-medium") {
        n = rnd.next(2, 80), m = rnd.next(2, 80);
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "random-wide") {
        n = rnd.next(1, 20), m = rnd.next(800, 1000);
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "random-tall") {
        n = rnd.next(800, 1000), m = rnd.next(1, 20);
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "near-max-rows") {
        n = 999, m = 1000;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "near-max-columns") {
        n = 1000, m = 999;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "max-random") {
        n = 1000, m = 1000;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "max-positive") {
        n = 1000, m = 1000;
        a.assign(n * m, 1000000000);
    } else if (type == "max-negative") {
        n = 1000, m = 1000;
        a.assign(n * m, -1000000000);
    } else if (type == "max-alternating") {
        n = 1000, m = 1000;
        a.resize(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i * m + j] = (i + j) % 2 == 0 ? 1000000000 : -1000000000;
            }
        }
    } else if (type == "max-one-row") {
        n = 1, m = 1000;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "max-one-column") {
        n = 1000, m = 1;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "large-prime") {
        n = 997, m = 991;
        fillRandom(-1000000000LL, 1000000000LL);
    } else if (type == "large-repeated") {
        n = 1000, m = 1000;
        fillRandom(-3, 3);
    } else if (type == "large-pattern") {
        n = 737, m = 913;
        a.resize(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long value = (i * 1000003LL + j * 1000033LL + seed) % 2000000001LL;
                a[i * m + j] = static_cast<int>(value - 1000000000LL);
            }
        }
    } else if (type == "extreme-cancellation") {
        n = 1000, m = 6;
        a.resize(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int value = 0;
                if (j == 0) value = 1000000000;
                if (j == 1) value = -1000000000;
                if (j == 2) value = i % 2 == 0 ? 1000000000 : -1000000000;
                if (j == 3) value = i == 0 ? 1000000000 : -1000000000;
                if (j == 4) value = i < 500 ? 1000000000 : -1000000000;
                if (j == 5) value = i % 3 == 0 ? 1000000000 : -1000000000;
                a[i * m + j] = value;
            }
        }
    } else if (type == "single-peak") {
        n = 1, m = 1000;
        a.assign(n * m, 0);
        a[0] = 1000000000;
        a[499] = -1000000000;
        a[999] = 1000000000;
    } else if (type == "stress") {
        n = rnd.next(1, 8), m = rnd.next(1, 8);
        fillRandom(-20, 20);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i * m + j] << (j + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
