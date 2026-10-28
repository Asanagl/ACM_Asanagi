#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    int a[MAXN][MAXN];
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    int x, y;
    cin >> x >> y;

    long long neighborSum = 0;
    if (x - 1 >= 0)
    {
        neighborSum += a[x - 1][y];
    }
    if (x + 1 < n)
    {
        neighborSum += a[x + 1][y];
    }
    if (y - 1 >= 0)
    {
        neighborSum += a[x][y - 1];
    }
    if (y + 1 < m)
    {
        neighborSum += a[x][y + 1];
    }

    cout << neighborSum << '\n';
    return 0;
}
