#include <iostream>
using namespace std;

int g = 10;   // 全局变量

int main()
{
    cout << g << '\n';   // 输出 10：此时只有全局的 g
    int g = 20;          // 局部 g 遮蔽了全局 g
    cout << g << '\n';   // 输出 20
    {
        int g = 30;      // 块级 g 又遮蔽了局部 g
        cout << g << '\n';   // 输出 30
    }                    // 块级 g 在这里失效
    cout << g << '\n';   // 输出 20：局部 g 恢复可见
    return 0;
}
