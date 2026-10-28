#include <iostream>
using namespace std;

#define MAXN 1000

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maximum = a[0];
    int minimum = a[0];
    int maximumIndex = 0;
    int negativeCount = (a[0] < 0) ? 1 : 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > maximum)
        {
            maximum = a[i];
            maximumIndex = i;
        }
        if (a[i] < minimum)
        {
            minimum = a[i];
        }
        if (a[i] < 0)
        {
            negativeCount++;
        }
    }

    cout << "maximum = " << maximum << '\n';
    cout << "maximum index = " << maximumIndex << '\n';
    cout << "minimum = " << minimum << '\n';
    cout << "negative count = " << negativeCount << '\n';
    return 0;
}
