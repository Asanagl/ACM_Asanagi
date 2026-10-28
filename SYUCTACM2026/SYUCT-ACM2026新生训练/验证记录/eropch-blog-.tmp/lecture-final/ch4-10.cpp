#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "abc";
    string b = "xyz";

    string c = a + b; // 拼出一个新字符串
    a += b;           // 把 b 追加到 a 的末尾

    cout << c << '\n';
    cout << a << '\n';
    return 0;
}
