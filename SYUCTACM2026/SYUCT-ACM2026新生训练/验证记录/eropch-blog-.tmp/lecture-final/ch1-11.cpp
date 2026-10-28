#include <iostream>
using namespace std;

int main()
{
    cout << static_cast<int>(3.9) << ' ' << (int)3.9 << '\n';   // 输出 3 3
    cout << static_cast<double>(7) / 2 << '\n';                 // 输出 3.5
    return 0;
}
