#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = a++; // 先把旧值 5 交给 b，再让 a 变成 6

    int c = 5;
    int d = ++c; // 先让 c 变成 6，再把 6 交给 d

    cout << a << ' ' << b << '\n';
    cout << c << ' ' << d << '\n';
    return 0;
}
