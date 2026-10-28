#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long answer;
    if (n % 2 == 0)
    {
        answer = (n / 2) * (n + 1);
    }
    else
    {
        answer = n * ((n + 1) / 2);
    }

    cout << answer << '\n';
    return 0;
}
