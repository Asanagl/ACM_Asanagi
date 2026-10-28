#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool palindrome = true;
    int left = 0;
    int right = (int)s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (palindrome)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}
