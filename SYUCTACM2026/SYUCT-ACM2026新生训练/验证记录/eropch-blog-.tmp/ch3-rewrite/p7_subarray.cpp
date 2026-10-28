#include <iostream>
using namespace std;

#define MAXN 200

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long best = a[0];
    for (int left = 0; left < n; left++)
    {
        long long currentSum = 0;
        for (int right = left; right < n; right++)
        {
            currentSum += a[right];
            if (currentSum > best)
            {
                best = currentSum;
            }
        }
    }

    cout << best << '\n';
    return 0;
}
