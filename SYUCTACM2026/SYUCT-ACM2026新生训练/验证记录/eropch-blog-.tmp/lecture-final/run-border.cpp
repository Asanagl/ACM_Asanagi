#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN][MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    long long borderSum = 0;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            if (row == 0 || row == n - 1 || column == 0 || column == m - 1)
            {
                borderSum += a[row][column];
            }
        }
    }

    cout << borderSum << '\n';
    return 0;
}
