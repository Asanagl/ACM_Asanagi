#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int changes = 0;
    int left = 0;
    int right = n - 1;
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
