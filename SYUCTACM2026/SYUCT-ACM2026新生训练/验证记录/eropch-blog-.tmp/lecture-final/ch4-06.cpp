#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        cout << i << ": " << s[i] << '\n';
    }

    s[0] = 'A'; // 像数组元素一样修改
    cout << s << '\n';
    return 0;
}
