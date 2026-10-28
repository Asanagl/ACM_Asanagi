#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double pi = 3.1415926;
    double x = 2.5;

    cout << pi << '\n';                              // 默认 6 位有效数字
    cout << fixed << setprecision(2) << pi << '\n';  // 四舍五入保留两位
    cout << fixed << setprecision(2) << x << '\n';   // 2.5 → 2.50
    printf("%.2f\n", pi);                            // printf 写法
    return 0;
}
