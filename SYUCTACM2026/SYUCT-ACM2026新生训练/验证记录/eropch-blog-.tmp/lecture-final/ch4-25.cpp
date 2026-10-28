#include <iostream>
using namespace std;

#define MAXN 1000

int a[MAXN][MAXN];
int b[MAXN][MAXN];

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
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> b[row][column];
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            int sum = a[row][column] + b[row][column];
            cout << sum << (column + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}
