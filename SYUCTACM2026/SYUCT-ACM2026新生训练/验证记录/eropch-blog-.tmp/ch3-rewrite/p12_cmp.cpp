#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAXN 1000

bool cmp(int x, int y)
{
    if (abs(x) != abs(y))
    {
        return abs(x) < abs(y);
    }
    return x < y;
}

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
