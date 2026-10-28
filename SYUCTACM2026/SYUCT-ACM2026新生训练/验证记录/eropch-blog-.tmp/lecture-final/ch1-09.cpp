#include <iostream>
using namespace std;

int main()
{
    int a = 100000, b = 100000;
    long long wrong = a * b;       // 危险：乘法先在 int 里做
    long long right = 1LL * a * b; // 正确：先提升成 long long 再乘
    cout << wrong << '\n';
    cout << right << '\n';
    return 0;
}
