#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    // 场景一：整数除法转浮点
    cout << 7 / 2 << '\n';            // 输出 3：整数除法直接舍去小数
    cout << 7.0 / 2 << '\n';          // 输出 3.5：至少一个操作数是浮点
    cout << (double)(7 / 2) << '\n';  // 输出 3：先算完 7/2=3，再转已经晚了

    // 场景二：浮点转整型的截断规则
    cout << (int)3.9 << ' ' << (int)-3.9 << '\n';   // 输出 3 -3：向零取整

    // 场景三：四舍五入
    cout << round(3.4) << ' ' << round(3.5) << ' ' << round(-3.5) << '\n';  // 输出 3 4 -4
    return 0;
}
