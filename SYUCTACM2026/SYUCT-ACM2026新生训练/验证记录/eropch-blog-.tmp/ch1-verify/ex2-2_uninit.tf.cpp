#include <iostream>
using namespace std;

int main()
{
    int x;          // 声明了，但没有初始化
    cout << x << '\n';   // 输出的是垃圾值，不可预测
    cout << flush;
    return 0;
}
