#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char s[100] = "hello";

    cout << strlen(s) << '\n'; // 5：strlen 不统计结尾的 '\0'
    cout << (int)s[5] << '\n'; // 0：s[5] 正是结尾的 '\0'

    char t[100] = "world";
    strcat(s, t);              // 把 t 拼接到 s 末尾
    cout << s << '\n';

    cout << strcmp("abc", "abd") << '\n'; // 负数：abc 字典序更小
    return 0;
}
