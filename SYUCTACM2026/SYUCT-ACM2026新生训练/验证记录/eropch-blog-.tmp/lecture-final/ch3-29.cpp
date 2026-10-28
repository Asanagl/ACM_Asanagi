#include <iostream>
using namespace std;

#define MAXN 1000

int cnt[MAXN + 1];   // 值域 0~1000，下标 0~1000 都要放得下

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = 1;   // 标记“出现过”
    }

    int mex = 0;
    while (cnt[mex] == 1)
    {
        mex++;
    }

    cout << mex << '\n';
    return 0;
}
