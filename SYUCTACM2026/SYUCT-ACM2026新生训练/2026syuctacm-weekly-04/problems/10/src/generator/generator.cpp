#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

static string random_digits(int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        s.push_back(char('0' + rnd.next(0, 9)));
    }
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

    const int MAXLEN = 100000;
    string s;

    if (type == "sample") {
        // sample-1 与 sample-2 为公开样例，与题面一致。
        s = (seed == 1) ? "12345" : "10203";
    } else if (type == "min-zero") {
        s = "0";
    } else if (type == "min-nine") {
        s = "9";
    } else if (type == "small-random") {
        s = random_digits(rnd.next(2, 12));
    } else if (type == "mid-random") {
        s = random_digits(rnd.next(1000, 50000));
    } else if (type == "max-random") {
        s = random_digits(MAXLEN);
    } else if (type == "near-max") {
        s = random_digits(MAXLEN - 1);
    } else if (type == "all-zero-100") {
        s = string(100, '0');
    } else if (type == "all-nine-100") {
        s = string(100, '9');
    } else if (type == "all-zero-max") {
        s = string(MAXLEN, '0');
    } else if (type == "all-nine-max") {
        s = string(MAXLEN, '9');
    } else if (type == "alternating-01") {
        for (int i = 0; i < 1000; ++i) s.push_back(i % 2 == 0 ? '0' : '1');
    } else if (type == "alternating-98") {
        for (int i = 0; i < 1001; ++i) s.push_back(i % 2 == 0 ? '9' : '8');
    } else if (type == "repeated-123") {
        for (int i = 0; i < 3333; ++i) s += "123";
    } else if (type == "trailing-zeros") {
        s = "5" + string(MAXLEN - 1, '0');
    } else if (type == "leading-zeros-tail") {
        s = string(50000, '0') + "777";
    } else if (type == "boundary-len-19") {
        // 19 位但小于 LLONG_MAX（9223372036854775807），可被 long long 正确读入。
        s = "1234567890123456789";
    } else if (type == "boundary-len-20") {
        // 20 位必然超过 LLONG_MAX，定向击杀"按整数读入"的错解。
        s = "10000000000000000007";
    } else if (type == "directed-ascii") {
        s = "1";  // 未做 -'0' 转换的实现输出 49
    } else if (type == "directed-skip-first") {
        s = "9000";  // 跳过首字符的实现输出 0
    } else if (type == "directed-break-zero") {
        s = "90909";  // 遇 0 停止的实现输出 9
    } else if (type == "directed-digital-root") {
        s = "99999";  // 数根错解输出 9，正确为 45
    } else if (type == "directed-parse") {
        s = string(100, '9');  // 100 位必然溢出 long long
    } else if (type == "zero-heavy") {
        int n = 50000;
        s.reserve(n);
        for (int i = 0; i < n; ++i) {
            s.push_back(rnd.next(1, 10) <= 9 ? '0' : char('0' + rnd.next(0, 9)));
        }
    } else if (type == "nine-heavy") {
        int n = 50000;
        s.reserve(n);
        for (int i = 0; i < n; ++i) {
            s.push_back(rnd.next(1, 10) <= 9 ? '9' : char('0' + rnd.next(0, 9)));
        }
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << s << '\n';
    return 0;
}
