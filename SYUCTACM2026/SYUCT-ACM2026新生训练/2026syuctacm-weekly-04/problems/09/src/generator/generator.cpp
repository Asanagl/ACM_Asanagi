#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

static const int MAX_N = 1000;

string randomString(int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s += char('a' + rnd.next(0, 25));
    }
    return s;
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

    string s;
    int l = 1;
    int r = 1;

    if (type == "sample") {
        s = "helloworld";
        l = 4;
        r = 7;
    } else if (type == "sample2") {
        s = "qwerty";
        l = 6;
        r = 6;
    } else if (type == "min") {
        s = "a";
        l = 1;
        r = 1;
    } else if (type == "single-char") {
        const int n = rnd.next(2, MAX_N);
        s = randomString(n);
        l = rnd.next(1, n);
        r = l;
    } else if (type == "full") {
        const int n = rnd.next(2, MAX_N);
        s = randomString(n);
        l = 1;
        r = n;
    } else if (type == "prefix") {
        const int n = rnd.next(3, MAX_N);
        s = randomString(n);
        l = 1;
        r = rnd.next(2, n - 1);
    } else if (type == "suffix") {
        const int n = rnd.next(3, MAX_N);
        s = randomString(n);
        l = rnd.next(2, n - 1);
        r = n;
    } else if (type == "interior") {
        const int n = rnd.next(4, MAX_N);
        s = randomString(n);
        l = rnd.next(2, n - 2);
        r = rnd.next(l + 1, n - 1);
    } else if (type == "len2") {
        const int n = rnd.next(2, MAX_N);
        s = randomString(n);
        l = rnd.next(1, n - 1);
        r = l + 1;
    } else if (type == "repeat-same") {
        const int n = rnd.next(2, MAX_N);
        const char c = char('a' + rnd.next(0, 25));
        s = string(n, c);
        l = rnd.next(1, n);
        r = rnd.next(l, n);
    } else if (type == "repeat-pattern") {
        const int p = rnd.next(2, 7);
        const string base = randomString(p);
        const int n = rnd.next(p + 1, MAX_N);
        s.resize(n);
        for (int i = 0; i < n; ++i) {
            s[i] = base[i % p];
        }
        l = rnd.next(1, n);
        r = rnd.next(l, n);
    } else if (type == "small") {
        const int n = rnd.next(2, 12);
        s = randomString(n);
        l = rnd.next(1, n);
        r = rnd.next(l, n);
    } else if (type == "random") {
        const int n = rnd.next(1, MAX_N);
        s = randomString(n);
        l = rnd.next(1, n);
        r = rnd.next(l, n);
    } else if (type == "max-full") {
        s = randomString(MAX_N);
        l = 1;
        r = MAX_N;
    } else if (type == "max-random") {
        s = randomString(MAX_N);
        l = rnd.next(1, MAX_N);
        r = rnd.next(l, MAX_N);
    } else if (type == "near-max") {
        const int n = rnd.next(900, MAX_N);
        s = randomString(n);
        l = rnd.next(1, n);
        r = rnd.next(l, n);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n' << l << ' ' << r << '\n';
    return 0;
}
