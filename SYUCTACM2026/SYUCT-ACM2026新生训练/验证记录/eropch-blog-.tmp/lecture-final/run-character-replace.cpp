#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
char x, y;
cin >> x >> y;
for (int i = 0; i < len; i++)
{
    if (s[i] == x)
    {
        s[i] = y;
    }
}
cout << s << '\n';
    return 0;
}
