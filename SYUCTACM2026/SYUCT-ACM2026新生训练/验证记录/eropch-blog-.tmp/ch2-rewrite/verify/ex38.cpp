#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }

    cout << product << '\n';
    return 0;
}
