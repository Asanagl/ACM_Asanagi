#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static string randomString(int len, int alphaSize) {
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s.push_back(char('a' + rnd.next(alphaSize)));
    }
    return s;
}

static void ensureChar(string &s, char c) {
    if (s.find(c) == string::npos) {
        s[rnd.next((int)s.size())] = c;
    }
}

static void emit(const string &s, char x, char y) {
    cout << s << '\n' << x << ' ' << y << '\n';
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

    if (type == "sample") {
        emit("banana", 'a', 'o');
    } else if (type == "min") {
        emit("a", 'a', 'b');
    } else if (type == "min-nooccur") {
        emit("z", 'a', 'b');
    } else if (type == "single") {
        string s = randomString(rnd.next(3, 8), 26);
        ensureChar(s, 'a');
        // 只保留恰好一个 'a'：其余 'a' 换掉
        bool kept = false;
        for (auto &ch : s) {
            if (ch == 'a') {
                if (kept) ch = 'b';
                kept = true;
            }
        }
        emit(s, 'a', 'b');
    } else if (type == "two-occur") {
        string s = randomString(rnd.next(4, 10), 26);
        int p = rnd.next((int)s.size());
        int q = rnd.next((int)s.size());
        while (q == p) q = rnd.next((int)s.size());
        s[p] = 'a';
        s[q] = 'a';
        // 其余位置不出现 'a'
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'a' && i != p && i != q) s[i] = 'b';
        }
        emit(s, 'a', 'b');
    } else if (type == "small") {
        string s = randomString(rnd.next(2, 12), 26);
        char x = char('a' + rnd.next(26));
        char y = (rnd.next(100) < 15) ? x : char('a' + rnd.next(26));
        emit(s, x, y);
    } else if (type == "repeated") {
        emit(string(50, 'a'), 'a', 'b');
    } else if (type == "repeated-nooccur") {
        emit(string(50, 'a'), 'b', 'c');
    } else if (type == "first-pos") {
        string tail = randomString(rnd.next(10, 30), 25); // 字母 b..z
        for (auto &ch : tail) ++ch;
        emit("a" + tail, 'a', 'b');
    } else if (type == "last-pos") {
        string head = randomString(rnd.next(10, 30), 25);
        for (auto &ch : head) ++ch;
        emit(head + "a", 'a', 'b');
    } else if (type == "same-char") {
        string s = randomString(rnd.next(5, 20), 26);
        ensureChar(s, 'a');
        emit(s, 'a', 'a');
    } else if (type == "dense") {
        // 约 70% 的字符是 'a'
        int len = 1000;
        string s;
        s.reserve(len);
        for (int i = 0; i < len; ++i) {
            s.push_back(rnd.next(100) < 70 ? 'a' : char('b' + rnd.next(25)));
        }
        emit(s, 'a', 'b');
    } else if (type == "sparse") {
        int len = 1000;
        string s = randomString(len, 25);
        for (auto &ch : s) ++ch; // b..z，不含 'a'
        s[rnd.next(len)] = 'a';
        emit(s, 'a', 'z');
    } else if (type == "swap-kill") {
        int len = rnd.next(20, 60);
        string s = randomString(len, 2); // 只含 a、b
        ensureChar(s, 'a');
        ensureChar(s, 'b');
        emit(s, 'a', 'b');
    } else if (type == "delete-kill") {
        int len = rnd.next(5, 30);
        string s = randomString(len, 25);
        for (auto &ch : s) ++ch;
        s[rnd.next(len)] = 'a';
        emit(s, 'a', 'b');
    } else if (type == "binary-alphabet") {
        int len = rnd.next(100, 500);
        string s = randomString(len, 2);
        ensureChar(s, 'a');
        ensureChar(s, 'b');
        emit(s, 'a', 'b');
    } else if (type == "boundary-az") {
        int len = 1000;
        string s;
        s.reserve(len);
        for (int i = 0; i < len; ++i) {
            s.push_back(rnd.next(100) < 60 ? 'a' : char('a' + rnd.next(26)));
        }
        emit(s, 'a', 'z');
    } else if (type == "boundary-za") {
        int len = 1000;
        string s;
        s.reserve(len);
        for (int i = 0; i < len; ++i) {
            s.push_back(rnd.next(100) < 60 ? 'z' : char('a' + rnd.next(26)));
        }
        emit(s, 'z', 'a');
    } else if (type == "near-max") {
        string s = randomString(99999, 26);
        char x = char('a' + rnd.next(26));
        char y = char('a' + rnd.next(26));
        emit(s, x, y);
    } else if (type == "max-all") {
        emit(string(100000, 'a'), 'a', 'b');
    } else if (type == "max-random") {
        emit(randomString(100000, 26), 'a', 'z');
    } else if (type == "random") {
        int len = rnd.next(2, 99999);
        int alpha = rnd.next(100) < 25 ? 1 : (rnd.next(100) < 40 ? 2 : 26);
        string s = randomString(len, alpha);
        char x = char('a' + rnd.next(alpha));
        char y = (rnd.next(100) < 10) ? x : char('a' + rnd.next(alpha));
        emit(s, x, y);
    } else if (type == "directed-mixed") {
        // 首尾是 'a'，中间含 'b'：同时针对漏末尾、方向写反、删除字符等错解
        string mid = randomString(rnd.next(10, 30), 25);
        for (auto &ch : mid) ++ch;
        ensureChar(mid, 'b');
        emit("a" + mid + "a", 'a', 'b');
    } else if (type == "sample-same") {
        emit("abacaba", 'a', 'a');
    } else if (type == "alternating") {
        string s;
        for (int i = 0; i < 4096; ++i) {
            s.push_back(i % 2 == 0 ? 'a' : 'b');
        }
        emit(s, 'a', 'z');
    } else if (type == "max-same") {
        emit(string(100000, 'q'), 'q', 'q');
    } else if (type == "max-nooccur") {
        emit(string(100000, 'a'), 'b', 'c');
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    return 0;
}
