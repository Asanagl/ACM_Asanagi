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

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    cout << sum << '\n';
    return 0;
}
