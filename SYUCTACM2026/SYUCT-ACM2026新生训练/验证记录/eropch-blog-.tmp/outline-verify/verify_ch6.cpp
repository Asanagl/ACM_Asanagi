#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 12;                                      // 二进制 1100
    cout << "odd(12)=" << (x & 1) << "\n";           // 判奇偶：末位为 0
    cout << "bit2(12)=" << ((x >> 2) & 1) << "\n";   // 取第 2 位（从 0 数）
    cout << "lowbit(12)=" << (x & -x) << "\n";       // 最低位的 1 所代表的值

    int a = 5, b = 9;
    a ^= b; b ^= a; a ^= b;                          // 异或交换
    cout << "swap: " << a << " " << b << "\n";

    int same = 12;
    same ^= same;                                    // 异或自身得 0（清零性质）
    cout << "xor self=" << same << "\n";

    cout << "(1<<2)+1=" << ((1 << 2) + 1) << "\n";   // 加括号：先移位
    cout << "1<<(2+1)=" << (1 << (2 + 1)) << "\n";   // 优先级陷阱：+ 高于 <<
    cout << "1<<10=" << (1 << 10) << "\n";           // 1 左移 10 位 = 1024

    int mask = (1 << 0) | (1 << 2);                  // 用位表示集合 {0, 2}
    cout << "mask bits=" << mask << "\n";
    cout << "has bit2=" << ((mask >> 2) & 1) << "\n";
    cout.flush(); // 本机 MinGW(mcfgthread) 退出时不自动刷新 cout，显式刷新
    return 0;
}
