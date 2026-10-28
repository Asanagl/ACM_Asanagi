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
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> a[row][column];
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int left = 0, right = m - 1; left < right; left++, right--)
        {
            swap(a[row][left], a[row][right]);
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cout << a[row][column] << (column + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
