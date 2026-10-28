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

    int transposed[MAXN][MAXN];
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            transposed[column][row] = a[row][column];
        }
    }

    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << transposed[row][column] << (column + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
