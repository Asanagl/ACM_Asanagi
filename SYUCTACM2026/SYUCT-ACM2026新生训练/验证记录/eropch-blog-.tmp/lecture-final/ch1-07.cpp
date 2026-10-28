#include <iostream>
using namespace std;

int main()
{
    bool a = true;   // 显式的真
    bool b = 42;     // 非零整数 → true
    bool c = 0;      // 只有 0 是 false
    cout << a << ' ' << b << ' ' << c << '\n';   // 输出 1 1 0
    return 0;
}
