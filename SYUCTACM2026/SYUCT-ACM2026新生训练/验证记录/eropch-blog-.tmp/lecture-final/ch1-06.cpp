#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    cout << c << '\n';            // 输出 A
    cout << c + 1 << '\n';        // 输出 66：字符先转成编码 65，再加 1
    cout << char(c + 1) << '\n';  // 输出 B：66 转回字符
    cout << 'C' - 'A' << '\n';    // 输出 2：两个字符编码相减
    return 0;
}
