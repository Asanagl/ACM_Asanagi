#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

static const int NMAX = 10000;

static string letters(int len, int alpha) {
    string r;
    r.reserve(len);
    for (int i = 0; i < len; ++i) {
        r.push_back(char('a' + rnd.next(0, alpha - 1)));
    }
    return r;
}

static string repeat(const string& unit, int times) {
    string r;
    r.reserve(unit.size() * times);
    for (int i = 0; i < times; ++i) {
        r += unit;
    }
    return r;
}

static string withInsertedChar(string base, char c) {
    int pos = rnd.next(0, static_cast<int>(base.size()));
    base.insert(base.begin() + pos, c);
    return base;
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
    string t;

    if (type == "sample-1") {
        s = "ababcabc";
        t = "abc";
    } else if (type == "sample-2") {
        s = "aaaa";
        t = "aab";
    } else if (type == "sample-3") {
        s = "aaaaa";
        t = "aaa";
    } else if (type == "min-found") {
        const char c = char('a' + seed % 26);
        s = string(1, c);
        t = s;
    } else if (type == "min-absent") {
        s = string(1, char('a' + seed % 26));
        t = string(1, char('a' + (seed + 7) % 26));
    } else if (type == "equal-found") {
        const int len = 3 + int(seed % 50);
        s = letters(len, 3);
        t = s;
    } else if (type == "equal-absent") {
        const int len = 3 + int(seed % 50);
        s = letters(len, 3);
        t = s;
        t.back() = char('a' + (t.back() - 'a' + 1) % 3);
    } else if (type == "prefix-found") {
        const int m = 2 + int(seed % 40);
        t = letters(m, 2);
        s = t + letters(5 + int(seed % 20), 2);
    } else if (type == "found-at-pos1") {
        const int m = 2 + int(seed % 20);
        t = letters(m, 3);
        s = string(1, 'z') + t;
    } else if (type == "found-at-pos2") {
        const int m = 2 + int(seed % 20);
        t = letters(m, 3);
        s = string(2, 'z') + t;
    } else if (type == "overlap-all-a") {
        const int n = 2000 + int(seed * 7 % 3000);
        const int m = 2 + int(seed % 50);
        s = string(n, 'a');
        t = string(m, 'a');
    } else if (type == "overlap-inner") {
        const string mid = repeat("ab", 4 + int(seed % 8));
        t = repeat("ab", 2 + int(seed % 2));
        s = "zz" + mid + "zz";
    } else if (type == "shift-after-mismatch") {
        const int m = 3 + int(seed % 40);
        s = string(m, 'a') + "b";
        t = string(m - 1, 'a') + "b";
    } else if (type == "tail-found") {
        const int p = 1 + int(seed % 30);
        t = letters(2 + int(seed % 20), 3);
        s = string(p, 'z') + t;
    } else if (type == "tail-at-upper") {
        const int m = (seed % 2 == 0) ? 2 + int(seed % 40) : 2500 + int(seed % 100);
        const int p = NMAX - m;
        t = letters(m, 3);
        s = string(p, 'z') + t;
    } else if (type == "many-occ") {
        if (seed % 2 == 0) {
            const int n = 2000 + int(seed % 1000);
            const int m = 5 + int(seed % 30);
            s = string(n, 'a');
            t = string(m, 'a');
        } else {
            const int times = 700 + int(seed % 300);
            s = repeat("abc", times);
            t = "abc";
        }
    } else if (type == "absent-basic") {
        const int n = 4 + int(seed % 40);
        const int k = 1 + int(seed % n);
        s = string(n, 'a');
        t = string(k - 1, 'a') + "b";
    } else if (type == "absent-long") {
        const int n = 5000 + int(seed % 100);
        const int m = 1000 + int(seed % 50);
        s = letters(n, 25);
        t = withInsertedChar(letters(m - 1, 25), 'z');
    } else if (type == "absent-insert") {
        const int n = 3000 + int(seed % 100);
        const int m = 1500 + int(seed % 50);
        s = letters(n, 2);
        t = withInsertedChar(letters(m - 1, 2), 'z');
    } else if (type == "periodic-absent") {
        const int times = 2500 + int(seed % 1000);
        s = repeat("ab", times);
        t = "aa" + string(1 + int(seed % 5), 'b');
    } else if (type == "all-a-max-absent") {
        const int m = 4999 + int(seed % 2);
        s = string(NMAX, 'a');
        t = string(m - 1, 'a') + "b";
    } else if (type == "max-single-found") {
        s = letters(NMAX, 2);
        t = string(1, 'a');
    } else if (type == "max-single-absent") {
        s = letters(NMAX, 25);
        t = "z";
    } else if (type == "near-max-found") {
        const int n = NMAX - int(seed % 50);
        const int m = 500 + int(seed % 500);
        s = letters(n, 4);
        const int pos = rnd.next(0, n - m);
        t = s.substr(pos, m);
    } else if (type == "near-max-absent") {
        const int n = NMAX - int(seed % 50);
        const int m = NMAX / 2;
        s = letters(n, 25);
        t = withInsertedChar(letters(m - 1, 25), 'z');
    } else if (type == "near-max-binary") {
        const int n = NMAX;
        const int m = 3000 + int(seed % 100);
        s = letters(n, 2);
        const int pos = rnd.next(0, n - m);
        t = s.substr(pos, m);
    } else if (type == "binary-random") {
        const int n = 2 + rnd.next(0, 500);
        const int m = 1 + rnd.next(0, n - 1);
        s = letters(n, 2);
        t = letters(m, 2);
    } else if (type == "small-random") {
        const int n = 1 + rnd.next(0, 8);
        const int m = 1 + rnd.next(0, n - 1);
        const int alpha = 1 + rnd.next(0, 2);
        s = letters(n, alpha);
        t = letters(m, alpha);
    } else if (type == "random") {
        const int n = 10 + rnd.next(0, 2000);
        const int m = 1 + rnd.next(0, n - 1);
        const int alpha = 2 + rnd.next(0, 24);
        s = letters(n, alpha);
        t = letters(m, alpha);
    } else if (type == "dense-random") {
        const int n = 100 + rnd.next(0, 2000);
        const int m = 2 + rnd.next(0, min(n - 1, 20) - 1);
        s = letters(n, 2);
        const int pos = rnd.next(0, n - m);
        t = s.substr(pos, m);
    } else {
        cerr << "Unknown generator type: " << type << "\n";
        return 1;
    }

    if (s.size() > static_cast<size_t>(NMAX) || t.empty() || t.size() > s.size()) {
        cerr << "generated data violates constraints: type=" << type << ", seed=" << seed << "\n";
        return 1;
    }

    printf("%s\n%s\n", s.c_str(), t.c_str());
    return 0;
}
