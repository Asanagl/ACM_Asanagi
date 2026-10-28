#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 200000;

string randString(int n) {
    string s(n, 'a');
    for (int i = 0; i < n; ++i) s[i] = char('a' + rnd.next(26));
    return s;
}

string randPalindrome(int n) {
    string s(n, 'a');
    for (int i = 0; i < (n + 1) / 2; ++i) s[i] = char('a' + rnd.next(26));
    for (int i = 0; i < n / 2; ++i) s[n - 1 - i] = s[i];
    return s;
}

string flipPairs(string s, int k) {
    int pairs = int(s.size()) / 2;
    set<int> used;
    while (int(used.size()) < k) {
        int i = rnd.next(0, pairs - 1);
        if (used.count(i)) continue;
        used.insert(i);
        char oldC = s[i];
        char newC = char('a' + rnd.next(26));
        while (newC == oldC || newC == s[s.size() - 1 - i]) newC = char('a' + rnd.next(26));
        s[i] = newC;
    }
    return s;
}

string allSame(int n, char c) {
    return string(n, c);
}

string alternating(int n) {
    string s(n, 'a');
    for (int i = 0; i < n; ++i) s[i] = (i % 2 == 0 ? 'a' : 'b');
    return s;
}

string allMismatch(int n) {
    string s(n, 'a');
    for (int i = 0; i < n / 2; ++i) {
        char c = char('a' + rnd.next(25));
        s[i] = c;
        s[n - 1 - i] = char(c + 1);
    }
    if (n % 2 == 1) s[n / 2] = char('a' + rnd.next(26));
    return s;
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

    string s;
    if (type == "sample-even") {
        s = "abccdzaa";
    } else if (type == "sample-odd") {
        s = "abxdcba";
    } else if (type == "min-1") {
        s = randString(1);
    } else if (type == "min-2") {
        char a = char('a' + rnd.next(26));
        char b = char('a' + rnd.next(26));
        while (b == a) b = char('a' + rnd.next(26));
        s = string(1, a) + string(1, b);
    } else if (type == "min-2-same") {
        s = "aa";
    } else if (type == "pal-odd-small") {
        s = randPalindrome(21);
    } else if (type == "pal-even-small") {
        s = randPalindrome(20);
    } else if (type == "one-diff-small") {
        s = flipPairs(randPalindrome(30), 1);
    } else if (type == "two-diff-small") {
        s = flipPairs(randPalindrome(30), 2);
    } else if (type == "outer-only") {
        s = string(12, 'a');
        s.front() = 'b';
        s.back() = 'c';
    } else if (type == "center-only") {
        s = string(11, 'a');
        s[s.size() / 2] = 'z';
    } else if (type == "all-same-even") {
        s = allSame(N_MAX, 'a');
    } else if (type == "all-same-odd") {
        s = allSame(N_MAX - 1, 'b');
    } else if (type == "alt-even") {
        s = alternating(N_MAX);
    } else if (type == "alt-odd") {
        s = alternating(N_MAX - 1);
    } else if (type == "two-blocks") {
        s = string(75000, 'a') + string(75000, 'b');
    } else if (type == "period-3") {
        s.resize(N_MAX - 2);
        for (int i = 0; i < int(s.size()); ++i) s[i] = char('a' + i % 3);
    } else if (type == "half-mismatch") {
        s = flipPairs(randPalindrome(100000), 25000);
    } else if (type == "random-small") {
        s = randString(rnd.next(2, 60));
    } else if (type == "random-med") {
        s = randString(rnd.next(1000, 50000));
    } else if (type == "near-max-even") {
        int n = rnd.next(190000 / 2, (N_MAX - 2) / 2) * 2;
        s = randString(n);
    } else if (type == "near-max-odd") {
        int n = 2 * rnd.next(190000 / 2, (N_MAX - 2) / 2) + 1;
        s = randString(n);
    } else if (type == "pal-random-even") {
        s = randPalindrome(N_MAX);
    } else if (type == "pal-random-odd") {
        s = randPalindrome(N_MAX - 1);
    } else if (type == "one-diff-max") {
        s = flipPairs(randPalindrome(N_MAX), 1);
    } else if (type == "max-even") {
        s = allMismatch(N_MAX);
    } else if (type == "max-odd") {
        s = allMismatch(N_MAX - 1);
    } else if (type == "stress-small") {
        int n = rnd.next(1, 8);
        s.resize(n);
        for (int i = 0; i < n; ++i) s[i] = char('a' + rnd.next(3));
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s.size() << '\n' << s << '\n';
    return 0;
}
