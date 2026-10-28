#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    int i = 1;
    while (i <= n)
    {
        sum += i;
        i++;
    }

    cout << sum << '\n';
    return 0;
}
