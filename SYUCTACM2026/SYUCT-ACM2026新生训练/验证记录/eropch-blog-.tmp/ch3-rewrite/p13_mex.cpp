#include <iostream>
using namespace std;

#define MAXN 1000

int cnt[105];

int main()
{
    int n;
    cin >> n;

    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = 1;
    }

    int mex = 0;
    while (cnt[mex] == 1)
    {
        mex++;
    }

    cout << mex << '\n';
    return 0;
}
