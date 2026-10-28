#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long x;
    cin >> x;

    long long sum = x;
    long long maximum = x;
    int positiveCount = (x > 0);

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        sum += x;
        if (x > 0)
        {
            positiveCount++;
        }
        if (x > maximum)
        {
            maximum = x;
        }
    }

    cout << "sum " << sum << '\n';
    cout << "positive " << positiveCount << '\n';
    cout << "maximum " << maximum << '\n';
    return 0;
}
