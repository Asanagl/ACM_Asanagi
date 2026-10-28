#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    float f = 123456789.0f;   // 后缀 f 表示 float 字面量
    double d = 123456789.0;
    cout << fixed << setprecision(0);   // 按整数格式输出
    cout << f << '\n';   // 输出 123456792
    cout << d << '\n';   // 输出 123456789
    cout << flush;
    return 0;
}
