#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

// 本题输入只有 n 和 m 两个整数。为了让 30+ 个 secret 输入彼此不同，
// 绝大多数据点直接固定 (n, m)；少数几个用固定种子在给定区间内抽取，
// 抽取区间刻意避开已固定的组合，最后由导出脚本核对哈希唯一性。
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    if (argc != 3) {
        cerr << "Usage: generator <type> <seed>\n";
        return 1;
    }

    const string type = argv[1];
    const long long seed = atoll(argv[2]);
    rnd.setSeed(seed);

    int n = 0;
    int m = 0;

    if (type == "sample") {
        // 与题面样例一致
        n = 3;
        m = 4;
    } else if (type == "min") {
        // 最小规模：1x1，只有 (1,1) 一个格子
        n = 1;
        m = 1;
    } else if (type == "row-2") {
        n = 1;
        m = 2;
    } else if (type == "row-3") {
        n = 1;
        m = 3;
    } else if (type == "row-4") {
        n = 1;
        m = 4;
    } else if (type == "row-10") {
        n = 1;
        m = 10;
    } else if (type == "row-999") {
        n = 1;
        m = 999;
    } else if (type == "row-max") {
        n = 1;
        m = 1000;
    } else if (type == "col-2") {
        n = 2;
        m = 1;
    } else if (type == "col-3") {
        n = 3;
        m = 1;
    } else if (type == "col-4") {
        n = 4;
        m = 1;
    } else if (type == "col-10") {
        n = 10;
        m = 1;
    } else if (type == "col-999") {
        n = 999;
        m = 1;
    } else if (type == "col-max") {
        n = 1000;
        m = 1;
    } else if (type == "sq-2") {
        n = 2;
        m = 2;
    } else if (type == "sq-3") {
        n = 3;
        m = 3;
    } else if (type == "sq-4") {
        n = 4;
        m = 4;
    } else if (type == "sq-5") {
        n = 5;
        m = 5;
    } else if (type == "sq-10") {
        n = 10;
        m = 10;
    } else if (type == "sq-100") {
        n = 100;
        m = 100;
    } else if (type == "wide-2-3") {
        n = 2;
        m = 3;
    } else if (type == "tall-3-2") {
        n = 3;
        m = 2;
    } else if (type == "wide-2-7") {
        n = 2;
        m = 7;
    } else if (type == "tall-7-2") {
        n = 7;
        m = 2;
    } else if (type == "wide-3-8") {
        n = 3;
        m = 8;
    } else if (type == "tall-8-3") {
        n = 8;
        m = 3;
    } else if (type == "wide-4-9") {
        n = 4;
        m = 9;
    } else if (type == "tall-9-4") {
        n = 9;
        m = 4;
    } else if (type == "wide-1-500") {
        n = 1;
        m = 500;
    } else if (type == "tall-500-1") {
        n = 500;
        m = 1;
    } else if (type == "small-random") {
        // 随机小棋盘：边长 2..12
        n = static_cast<int>(rnd.next(2, 12));
        m = static_cast<int>(rnd.next(2, 12));
    } else if (type == "even-even") {
        // 偶×偶：两维都是偶数，交替染色在四个角上同色
        n = 2 * static_cast<int>(rnd.next(1, 60));
        m = 2 * static_cast<int>(rnd.next(1, 60));
    } else if (type == "odd-odd") {
        // 奇×奇：两维都是奇数
        n = 2 * static_cast<int>(rnd.next(0, 60)) + 1;
        m = 2 * static_cast<int>(rnd.next(0, 60)) + 1;
    } else if (type == "even-odd") {
        n = 2 * static_cast<int>(rnd.next(1, 60));
        m = 2 * static_cast<int>(rnd.next(0, 60)) + 1;
    } else if (type == "odd-even") {
        n = 2 * static_cast<int>(rnd.next(0, 60)) + 1;
        m = 2 * static_cast<int>(rnd.next(1, 60));
    } else if (type == "medium-random") {
        // 随机中等规模：边长 40..200
        n = static_cast<int>(rnd.next(40, 200));
        m = static_cast<int>(rnd.next(40, 200));
    } else if (type == "thin-wide") {
        // 特殊形状：极扁，行数很少而列数接近上限
        n = static_cast<int>(rnd.next(2, 5));
        m = static_cast<int>(rnd.next(800, 1000));
    } else if (type == "thin-tall") {
        // 特殊形状：极瘦，列数很少而行数接近上限
        n = static_cast<int>(rnd.next(800, 1000));
        m = static_cast<int>(rnd.next(2, 5));
    } else if (type == "near-max-1") {
        n = 999;
        m = 1000;
    } else if (type == "near-max-2") {
        n = 1000;
        m = 999;
    } else if (type == "near-max-3") {
        n = 777;
        m = 998;
    } else if (type == "prime") {
        // 两个互不相同的大质数：避免任何周期性巧合
        n = 997;
        m = 991;
    } else if (type == "max") {
        n = 1000;
        m = 1000;
    } else {
        cerr << "Unknown case type: " << type << '\n';
        return 2;
    }

    cout << n << ' ' << m << '\n';
    return 0;
}
