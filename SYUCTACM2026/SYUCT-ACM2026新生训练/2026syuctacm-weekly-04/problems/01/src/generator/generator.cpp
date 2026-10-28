#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static string randomString(int len) {
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s += char('a' + rnd.next(0, 25));
    }
    return s;
}

static char differentChar(char base, int spread) {
    return char('a' + (base - 'a' + 1 + rnd.next(0, spread)) % 26);
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
    if (type == "sample") {
        if (seed == 1) {
            s = "hello";
        } else if (seed == 2) {
            s = "a";
        } else {
            s = "syuctoj";
        }
    } else if (type == "min") {
        // 最小长度：单个字符
        s = string(1, char('a' + seed % 26));
    } else if (type == "two") {
        // 最短非平凡形状：长度 2，且首尾不同
        char first = char('a' + seed % 26);
        s = string(1, first) + differentChar(first, 24);
    } else if (type == "same") {
        // 特殊形状：整串同一字符（首尾相同）
        int len = 3 + int(seed % 98); // 3..100
        s = string(len, char('a' + seed % 26));
    } else if (type == "same-max") {
        // 同一字符 + 近上限长度
        s = string(1000, char('a' + seed % 26));
    } else if (type == "alt") {
        // 特殊形状：两字符交替
        int len = 6 + int(seed % 115); // 6..120
        char a = char('a' + seed % 26);
        char b = char('a' + (seed + 1) % 26);
        s.resize(len);
        for (int i = 0; i < len; ++i) {
            s[i] = (i % 2 == 0) ? a : b;
        }
    } else if (type == "pair") {
        // 重复：仅由两个不同字符组成的随机串
        int len = 20 + int(seed % 231); // 20..250
        char a = char('a' + seed % 26);
        char b = char('a' + (seed + 1) % 26);
        s.resize(len);
        for (int i = 0; i < len; ++i) {
            s[i] = (rnd.next(0, 1) == 0) ? a : b;
        }
    } else if (type == "directed") {
        // 定向：首尾强制不同，用于稳定击杀首尾颠倒 / 首字符复用类错解
        int len = 8 + int(seed % 53); // 8..60
        s = randomString(len);
        s[0] = char('a' + seed % 26);
        s[len - 1] = differentChar(s[0], 24);
    } else if (type == "random") {
        // 随机：长度 1..1000
        int len = rnd.next(1, 1000);
        s = randomString(len);
    } else if (type == "mid") {
        // 中部规模
        s = randomString(500);
    } else if (type == "near-max") {
        // 近上限：998 / 999
        int len = (seed % 2 == 0) ? 998 : 999;
        s = randomString(len);
    } else if (type == "max") {
        // 上限：1000
        s = randomString(1000);
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
