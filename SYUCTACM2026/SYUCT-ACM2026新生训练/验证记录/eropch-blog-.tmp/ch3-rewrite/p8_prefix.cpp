#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN];
long long pre[MAXN + 1];

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
        cin >> left >> right;
        cout << pre[right + 1] - pre[left] << '\n';
    }
    return 0;
}
