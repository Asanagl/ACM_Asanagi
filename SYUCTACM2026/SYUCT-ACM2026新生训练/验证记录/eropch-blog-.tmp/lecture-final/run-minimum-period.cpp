#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();
    int answer = n;
    for (int k = 1; k <= n; k++)
    {
        if (n % k != 0)
        {
            continue;
        }
        bool repeated = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[i % k])
            {
                repeated = false;
                break;
            }
        }
        if (repeated)
        {
            answer = k;
            break;
        }
    }

    cout << answer << ' ' << s.substr(0, answer) << '\n';
    return 0;
}
