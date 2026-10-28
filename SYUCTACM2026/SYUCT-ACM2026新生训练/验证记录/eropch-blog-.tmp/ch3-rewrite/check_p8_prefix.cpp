#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN];
long long pre[MAXN + 1];   // 长度是 n + 1，下标 0 到 n

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    pre[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    int queryCount;
    cin >> queryCount;

    while (queryCount--)
    {
        int left, right;
        cin >> left >> right;              // 0 开始的闭区间 [left, right]
        cout << pre[right + 1] - pre[left] << '\n';
    }
    return 0;
}
