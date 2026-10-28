#include <iostream>
using namespace std;

#define MAXN 1000

int cnt[101];   // 全局数组，自动清零

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;    // a[i] 这个值又出现了一次
    }

    for (int value = 0; value <= 100; value++)
    {
        if (cnt[value] > 0)
        {
            cout << value << ": " << cnt[value] << '\n';
        }
    }
    return 0;
}
