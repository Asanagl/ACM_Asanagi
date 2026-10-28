#include <algorithm>
#include <functional>
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

    sort(a, a + n);                 // 从小到大
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }

    sort(a, a + n, greater<int>()); // 从大到小
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
