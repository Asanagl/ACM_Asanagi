#include <iostream>
using namespace std;

int reverseNumber(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }

        int sum = a + b;
        if (reverseNumber(a) + reverseNumber(b) == reverseNumber(sum))
        {
            cout << sum << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
