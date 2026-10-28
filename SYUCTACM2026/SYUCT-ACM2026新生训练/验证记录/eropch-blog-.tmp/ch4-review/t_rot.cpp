#include <iostream>
using namespace std;

#define MAXN 100

int main()
{
    cout << flush; // harness-only: flush stdio before reading (local MinGW-mcf quirk)
    int n, m;
    cin >> n >> m;

    if (n <= 0 || n > MAXN || m <= 0 || m > MAXN)
    {
        return 0;
    }

    int a[MAXN][MAXN];
    int rotated[MAXN][MAXN];
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            rotated[column][n - 1 - row] = a[row][column];
        }
    }

    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            cout << rotated[row][column] << (column + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
