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
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }

    cout << s << '\n';
    return 0;
}
