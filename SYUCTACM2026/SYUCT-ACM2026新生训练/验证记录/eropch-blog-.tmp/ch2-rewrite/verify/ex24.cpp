#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isPrime = (n >= 2);
    for (int divisor = 2; 1LL * divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << "prime\n";
    }
    else
    {
        cout << "not prime\n";
    }
    return 0;
}
