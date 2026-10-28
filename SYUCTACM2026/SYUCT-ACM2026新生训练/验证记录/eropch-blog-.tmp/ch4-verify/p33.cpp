#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int changes = 0;
    int left = 0;
    int right = (int)s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            changes++;
        }
        left++;
        right--;
    }

    cout << changes << '\n';
    return 0;
}
