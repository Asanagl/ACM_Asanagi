#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

// 判断 s 是否能由前 len 个字符整次重复得到。
static bool isExactPeriod(const string& s, int len) {
    const int n = static_cast<int>(s.size());
    if (n % len != 0) {
        return false;
    }
    for (int i = len; i < n; ++i) {
        if (s[i] != s[i % len]) {
            return false;
        }
    }
    return true;
}

static int periodLen(const string& s) {
    for (int len = 1; len <= static_cast<int>(s.size()); ++len) {
        if (isExactPeriod(s, len)) {
            return len;
        }
    }
    return static_cast<int>(s.size());
}

static string randString(int n) {
    string s(n, 'a');
    for (int i = 0; i < n; ++i) {
        s[i] = static_cast<char>('a' + rnd.next(0, 25));
    }
    return s;
}

// 生成一个最短循环节就是自身的随机串（长度为 len）。
static string aperiodicBase(int len) {
    for (int attempt = 0; attempt < 100000; ++attempt) {
        const string t = randString(len);
        if (periodLen(t) == len) {
            return t;
        }
    }
    // 保底构造 'a'*(len-1) + 'b' 必为非周期：若它有整除周期 d < len，
    // 则第 len-1 位 'b' 必须等于第 (len-1) mod d = d-1 位 'a'，矛盾。
    string t(static_cast<size_t>(len), 'a');
    t[len - 1] = 'b';
    return t;
}

static string repeat(const string& t, int k) {
    string s;
    s.reserve(t.size() * static_cast<size_t>(k));
    for (int i = 0; i < k; ++i) {
        s += t;
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

    if (type == "sample") {
        s = (seed == 1) ? "ababab" : "abcab";
    } else if (type == "min") {
        s = "a";
    } else if (type == "tiny") {
        s = randString(rnd.next(1, 8));
    } else if (type == "small") {
        s = randString(rnd.next(9, 50));
    } else if (type == "all-same") {
        s = string(static_cast<size_t>(rnd.next(2, 3000)), static_cast<char>('a' + rnd.next(0, 25)));
    } else if (type == "repeated") {
        // s = t^k，t 非周期，尽量接近长度上限。
        const int len = rnd.next(1, 100);
        const string t = aperiodicBase(len);
        s = repeat(t, 3000 / len);
    } else if (type == "anti-tail") {
        // s = t^k + t[0..r)：末尾拖着一段不完整周期，答案必为 n。
        const int len = rnd.next(2, 100);
        const string t = aperiodicBase(len);
        const int k = rnd.next(2, (3000 - len) / len);
        const int r = rnd.next(1, len - 1);
        s = repeat(t, k) + t.substr(0, r);
    } else if (type == "anti-border") {
        // s = p + x + p：有很长的前后缀 p，但答案为 n（击杀"最长前后缀"类错解）。
        const int plen = rnd.next(1, 60);
        const string p = randString(plen);
        s = p + randString(rnd.next(1, 3)) + p;
        for (int guard = 0; guard < 100000 && periodLen(s) != static_cast<int>(s.size()); ++guard) {
            s = p + randString(rnd.next(1, 3)) + p;
        }
    } else if (type == "anti-half") {
        // s = t^k，k 为不小于 4 的偶数：前后两半完全相等，但答案 |t| < n/2。
        const int len = rnd.next(1, 750);
        int k = 3000 / len;
        if (k % 2 == 1) {
            --k;
        }
        if (k < 4) {
            // len 接近 750 时 k 恰为 4，不会进入这里；防御性回退。
            k = 4;
        }
        s = repeat(aperiodicBase(len), k);
    } else if (type == "random") {
        s = randString(rnd.next(51, 3000));
    } else if (type == "prime") {
        // 2999 是素数：长度只能整除 1 和自身。
        s = randString(2999);
    } else if (type == "max") {
        s = randString(3000);
    } else if (type == "max-periodic") {
        s = repeat(aperiodicBase(750), 4);
    } else if (type == "near-max-tail") {
        const int len = 1000;
        const string t = aperiodicBase(len);
        s = repeat(t, 2) + t.substr(0, 999);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
