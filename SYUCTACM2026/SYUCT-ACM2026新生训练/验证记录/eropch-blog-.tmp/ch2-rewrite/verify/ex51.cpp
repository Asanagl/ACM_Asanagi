#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int divisor = 1; divisor <= n; divisor++)
    {
        if (n % divisor == 0)
        {
            cout << divisor << ' ';
        }
    }
    cout << '\n';
    return 0;
}
