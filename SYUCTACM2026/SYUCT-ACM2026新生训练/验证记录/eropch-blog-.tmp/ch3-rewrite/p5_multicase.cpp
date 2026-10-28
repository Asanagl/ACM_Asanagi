#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 1000

int cnt[10];

int main()
{
    int testCount;
    cin >> testCount;

    while (testCount--)
    {
        int n;
        cin >> n;

        int a[MAXN];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        fill(cnt, cnt + 10, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[a[i]]++;
        }

        for (int value = 0; value < 10; value++)
        {
            cout << cnt[value] << (value + 1 == 10 ? '\n' : ' ');
        }
    }
    return 0;
}
